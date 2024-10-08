/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.4.11
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains an Rte component template / example code
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.4.11
 * on Fri Dec 01 11:52:37 IST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_Swc_E2ESafetyCom.h>
#define E2E_P02STATUS_OK 			   0x0U  /**< New data has been correctly received. */
#define E2E_P02STATUS_OKSOMELOST 	   0x1U  /**< New data has been correctly received, but some data in the sequence have been probably lost. */
#define E2E_P02STATUS_WRONGCRC 		   0x2U  /**< The data has been received according to communication medium, but the CRC is incorrect. */
#define E2E_P02STATUS_REPEATED 	       0x3U  /**< New data has been correctly received, but the Counter is identical to the most recent Data */
#define E2E_CRCERROR				   TRUE
#define E2EP02_COUNTER_MAX             15U
#define DATA_LEN_ID641_INT1            9U
#define DATA_LEN_ID641_INT2 		   9U
#define DATA_LEN_ID00F 				   6U
#define DATA_LEN_ID010				   5U
#define InterLane_OFFSET              -8.19f
#define InterLane_FACTOR              0.001f
#define ID_064_CalRackFEstimd_OFFSET  -25000
#define ID_064_CalRackFEstimd_FACTOR  3.052f
#define ID_064_CalPinionAg_OFFSET     -840
#define ID_064_CalPinionAg_FACTOR     0.02625f
#define ID_00F_PinionAgReqdA_FACTOR   0.02625f
#define ID_00F_ShaftRatVar_FACTOR     0.005f
#define ID_00F_PinionAgReqdA_OFFSET   -840
#define ID_00F_ShaftRatVar_OFFSET     0.75f

uint8 const SCrc_Table8H2F[256] =
{
    0x00U, 0x2FU, 0x5EU, 0x71U, 0xBCU, 0x93U, 0xE2U, 0xCDU, 0x57U, 0x78U, 0x09U,
    0x26U, 0xEBU, 0xC4U, 0xB5U, 0x9AU,
    0xAEU, 0x81U, 0xF0U, 0xDFU, 0x12U, 0x3DU, 0x4CU, 0x63U, 0xF9U, 0xD6U, 0xA7U,
    0x88U, 0x45U, 0x6AU, 0x1BU, 0x34U, 0x73U, 0x5CU, 0x2DU, 0x02U, 0xCFU, 0xE0U,
    0x91U, 0xBEU, 0x24U, 0x0BU, 0x7AU, 0x55U, 0x98U, 0xB7U, 0xC6U, 0xE9U, 0xDDU,
    0xF2U, 0x83U, 0xACU, 0x61U, 0x4EU, 0x3FU, 0x10U, 0x8AU, 0xA5U, 0xD4U, 0xFBU,
    0x36U, 0x19U, 0x68U, 0x47U, 0xE6U, 0xC9U, 0xB8U, 0x97U, 0x5AU, 0x75U, 0x04U,
    0x2BU, 0xB1U, 0x9EU, 0xEFU, 0xC0U, 0x0DU, 0x22U, 0x53U, 0x7CU, 0x48U, 0x67U,
    0x16U, 0x39U, 0xF4U, 0xDBU, 0xAAU, 0x85U, 0x1FU, 0x30U, 0x41U, 0x6EU, 0xA3U,
    0x8CU, 0xFDU, 0xD2U, 0x95U, 0xBAU, 0xCBU, 0xE4U, 0x29U, 0x06U, 0x77U, 0x58U,
    0xC2U, 0xEDU, 0x9CU, 0xB3U, 0x7EU, 0x51U, 0x20U, 0x0FU, 0x3BU, 0x14U, 0x65U,
    0x4AU, 0x87U, 0xA8U, 0xD9U, 0xF6U, 0x6CU, 0x43U, 0x32U, 0x1DU, 0xD0U, 0xFFU,
    0x8EU, 0xA1U, 0xE3U, 0xCCU, 0xBDU, 0x92U, 0x5FU, 0x70U, 0x01U, 0x2EU, 0xB4U,
    0x9BU, 0xEAU, 0xC5U, 0x08U, 0x27U, 0x56U, 0x79U, 0x4DU, 0x62U, 0x13U, 0x3CU,
    0xF1U, 0xDEU, 0xAFU, 0x80U, 0x1AU, 0x35U, 0x44U, 0x6BU, 0xA6U, 0x89U, 0xF8U,
    0xD7U, 0x90U, 0xBFU, 0xCEU, 0xE1U, 0x2CU, 0x03U, 0x72U, 0x5DU, 0xC7U, 0xE8U,
    0x99U, 0xB6U, 0x7BU, 0x54U, 0x25U, 0x0AU, 0x3EU, 0x11U, 0x60U, 0x4FU, 0x82U,
    0xADU, 0xDCU, 0xF3U, 0x69U, 0x46U, 0x37U, 0x18U, 0xD5U, 0xFAU, 0x8BU, 0xA4U,
    0x05U, 0x2AU, 0x5BU, 0x74U, 0xB9U, 0x96U, 0xE7U, 0xC8U, 0x52U, 0x7DU, 0x0CU,
    0x23U, 0xEEU, 0xC1U, 0xB0U, 0x9FU, 0xABU, 0x84U, 0xF5U, 0xDAU, 0x17U, 0x38U,
    0x49U, 0x66U, 0xFCU, 0xD3U, 0xA2U, 0x8DU, 0x40U, 0x6FU, 0x1EU, 0x31U, 0x76U,
    0x59U, 0x28U, 0x07U, 0xCAU, 0xE5U, 0x94U, 0xBBU, 0x21U, 0x0EU, 0x7FU, 0x50U,
    0x9DU, 0xB2U, 0xC3U, 0xECU, 0xD8U, 0xF7U, 0x86U, 0xA9U, 0x64U, 0x4BU, 0x3AU,
    0x15U, 0x8FU, 0xA0U, 0xD1U, 0xFEU, 0x33U, 0x1CU, 0x6DU, 0x42U,
};

uint8 Data_ID[16]={0xB4,0xEF,0xF8,0x49,0x1E,0xE5,0xC2,0xC0,0x97,0x19,0x3C,0xC9,0xF1,0x98,0xD6,0x61};
enum E2Emsgs
{
	ID00F,
	ID010,
	MSG_INT1,
	MSG_INT2,
	NoOfE2EMessages
};
uint8 LastValidCounter[NoOfE2EMessages] = {0U,0U,0U,0U};
boolean WaitForFirstData[NoOfE2EMessages]= {TRUE,TRUE,TRUE,TRUE};
uint16 Age_Error_IntLane1 = 0;
uint16 IntLane1_Age = 0;
uint16 Age_Error_IntLane2 = 0;
uint16 IntLane2_Age = 0;
uint16 Age_Error_ID00F = 0;
uint16 ID00F_Age = 0;
uint16 Age_Error_ID010 = 0;
uint16 ID010_Age = 0;

static DT_IntLane1PduInCnvn RX_INTER1 =
{
   0U,
   0U,
   0.0f,
   0.0f,
   0.0f,
   0U,
   0U
 };
Std_ReturnType ret_Write_6;
static DT_FwsPduInCnvn RX_ID010 =
{
  0U,
  0U,
  0U,
  0U,
  0U
};
Std_ReturnType ret_Write_5;
static  DT_IntLane2PduInCnvn RX_INTER2 =
{
   0U,
   0U,
   0.0f,
   0.0f,
   0.0f,
   0U,
   0U
 };
 Std_ReturnType ret_Write_7;
 static DT_PinionPduInCnvn ID_00F =
 {
   0.0f,
   0.0f,
   0U,
   0U,
   0U
 };
 Std_ReturnType ret_Write_4;

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
 FUNC(uint8, E2E_CODE) SCrc_CalculateCRC8H2F_E2E
  (
     uint8  SCrc_DataPtr[8],
     uint8  SCrc_Length,
     uint8   SCrc_StartValue8H2F,
     boolean SCrc_IsFirstCall
  )
  {
     uint8 i;
     uint8 SCRC_CRC8H2F_INITIALVALUE = 0xFFU;
	 uint8 SCRC_CRC8H2F_XORVALUE = 0xFFU;

     /* Check if this is the first call in a sequence or individual CRC calculation.
      * If so, then use the defined initial value. Otherwise, the start value
      * is interpreted as the return value of the previous function call.
      */
     if (FALSE == SCrc_IsFirstCall)
     {
         SCrc_StartValue8H2F = (uint8)(SCrc_StartValue8H2F ^ SCRC_CRC8H2F_XORVALUE);
     }
     else
     {
         SCrc_StartValue8H2F = SCRC_CRC8H2F_INITIALVALUE;
     }

     /* Process all data (byte wise) */
     for (i=0U; i<SCrc_Length; ++i)
     {
         SCrc_StartValue8H2F = SCrc_Table8H2F[(uint8)(SCrc_StartValue8H2F ^ SCrc_DataPtr[i])];
     }

     /* Apply xor-value of 0xFF as specified in ASR R4.0 CRC SWS. */
     return (uint8)(SCrc_StartValue8H2F ^ SCRC_CRC8H2F_XORVALUE);
  }

//Function to calculate CRC
 FUNC(uint8, E2E_CODE) E2E_EB_CalculateCrc_E2E
 (
   uint8 ArrayLength,
   uint8 Data[8],
   uint8 Counter
 )
 {
   uint8 E2EP02_CRC_STARTVALUE = 0xFFU;
   uint8 DataId[1];
   DataId[0] =Data_ID[Counter];
   uint8 Crc;
   Crc = SCrc_CalculateCRC8H2F_E2E(Data,
                              ArrayLength - 1U,
                              E2EP02_CRC_STARTVALUE,
                              TRUE);
   Crc = SCrc_CalculateCRC8H2F_E2E(DataId,
                              1U,
                              Crc,
                              FALSE);
   return Crc;
 }

 /* Function to check Error Status */
FUNC(uint8, E2E_CODE) E2E_Seq_Check(uint8 R_counter, uint8 Msg_ID )
  {

    uint8 DeltaCounter;
    uint8 err_status = E2E_P02STATUS_OK;
		/* counter check */
		if (TRUE == WaitForFirstData[Msg_ID])
		 {
			/* first data received since init or reinit
			 * (sequence counter cannot be checked) */
			WaitForFirstData[Msg_ID] = FALSE;
			LastValidCounter[Msg_ID] = R_counter;
		 }
		else
		 {
			/* check sequence counter */
			DeltaCounter = (R_counter >= LastValidCounter[Msg_ID]) ?
						   (R_counter - LastValidCounter[Msg_ID]) :
						   ((R_counter + E2EP02_COUNTER_MAX + 1U) - LastValidCounter[Msg_ID]);
			if (1U == DeltaCounter)
			 {
				/* the Counter is incremented by 1, i.e. no Data has
				 * been lost since the last correct data reception. */
				err_status = E2E_P02STATUS_OK;
			 }
			else if (1U < DeltaCounter)
			 {
			   /* the Counter is incremented by DeltaCounter
				* (1 < DeltaCounter), i.e.
				* some Data in the sequence have been probably lost since
				* the last correct/initial reception, but this is within
				* the configured tolerance range. */
				err_status = E2E_P02STATUS_OKSOMELOST;
			 }
#if FALSE
			 else if (DeltaCounter == 0U) /* DeltaCounter == 0U */
			 {
				 /* the counter is identical, i.e. data has already been
				  * received (repeated message) */
				 /* Increment counter for consecutively missing or repeated Data */
				err_status = E2E_P02STATUS_REPEATED;
			 }
#endif
			 else
			 {
				 /* Do Nothing */
			 }
			LastValidCounter[Msg_ID] = R_counter;
		 }
 	return err_status;
 }
/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
FUNC(void, RTE_CODE) Swc_E2ESafetyCom_Runnable (void)
{
  uint16 calmottqintlane1;
  uint16 calMotTq1;
  uint16 calMotTqReqd1;
  uint16 pinionAg;
  uint16 calRackFEstimd_id064;

  /* TimeOut Implementation */
	DT_SG_ID641_EcuB_EcuA arg_Read_data_ID641_INTER1;
	Std_ReturnType ret_Read_ID641_INTER1_1;
	DT_SG_ID010_HwaA_RwaA arg_Read_data_ID010;
	Std_ReturnType ret_Read_ID010;
	DT_SG_ID00F_HwaA_RwaA arg_Read_data_ID00F;
	Std_ReturnType ret_Read_ID00F;
	DT_SG_ID641_EcuB_EcuA arg_Read_data_ID641_INTER2;
	Std_ReturnType ret_Read_ID641_INTER2;

	 DT_SG_ID064_RwaA_HwaA TX_ID064 =
	  {
	    0U,
	    0U,
	    0U,
	    0U,
	    0U,
	    0U
	  };
	  Std_ReturnType ret_Write;
	  DT_SG_ID065_RwaA_HwaA TX_ID065 =
	  {
	    0U,
	    0U,
	    0U,
	    0U
	  };
	  Std_ReturnType ret_Write_0;
	  DT_SG_ID066_RwaA_HwaA TX_ID066 =
	  {
	    0U,
	    0U,
	    0U,
	    0U,
	    0U,
	    0U
	  };
	  Std_ReturnType ret_Write_1;
	 DT_SG_ID100_EcuA_EcuB TX_INTER1 =
	  {
	    0U,
	    0U,
	    0U,
	    0U,
	    0U,
	    0U,
	    0U
	  };
	  Std_ReturnType ret_Write_2_ID100_INTER1;  /* Interlane1 */
	  DT_SG_ID100_EcuA_EcuB TX_INTER2 =
	  {
	    0U,
	    0U,
	    0U,
	    0U,
	    0U,
	    0U,
	    0U
	  };
	  Std_ReturnType ret_Write_3_ID100_INTER2;  /* Interlane2 */
  ATE arg_Read_data; 		 /* Interlane1 */ /* Interlane2 */
  Std_ReturnType ret_Read;
  float32 arg_Read_data_0_reqd;  /* Interlane1 */ /* Interlane2 */
  Std_ReturnType ret_Read_0_reqd;
  float32 arg_Read_data_1;     /* ID064 */
  Std_ReturnType ret_Read_1;
  DT_SysFctSt arg_Read_data_2; /* ID066 */ /* ID064 */
  Std_ReturnType ret_Read_2;
  DT_SysFctSt arg_Read_data_3; /* ID066 */ /* ID064 */
  Std_ReturnType ret_Read_3;
  DT_SysFctSt arg_Read_data_4; /* ID066 */ /* ID065 */
  Std_ReturnType ret_Read_4;
  DT_SysFctSt arg_Read_data_5; /* ID066 */ /* ID065 */
  Std_ReturnType ret_Read_5;
  uint8 arg_Read_data_7;  		 /* Interlane1 */ /* Interlane2 */
  Std_ReturnType ret_Read_7;
  uint8 arg_Read_data_8; 		/* Interlane1 */ /* Interlane2 */
  Std_ReturnType ret_Read_8;
  float32 arg_Read_data_9;     /* Interlane1 */ /* Interlane2 */
  Std_ReturnType ret_Read_9;
  float32 arg_Read_data_10;  /* ID064 */
  Std_ReturnType ret_Read_10;

  /* Interlane1 &  Interlane2 CAN communication: */

  /* float to uint16 conversion */
  /* Receive from ASW and send to CAN */
    (void)ret_Read_9;
    ret_Read_9 = Rte_Read_R_CalMotTqIntLane_MotTqIntLane(&arg_Read_data_9);
    calmottqintlane1=((arg_Read_data_9  - InterLane_OFFSET)/InterLane_FACTOR);
    TX_INTER1.S_EcuA_MotTqIntLane_Nm = calmottqintlane1;
    TX_INTER2.S_EcuA_MotTqIntLane_Nm = calmottqintlane1;

    (void)ret_Read;
    ret_Read = Rte_Read_R_ATE_ATE(&arg_Read_data);
    calMotTq1=((arg_Read_data.VATE_sMotorActTqCalc_Nm  - InterLane_OFFSET)/InterLane_FACTOR);
    TX_INTER1.S_EcuA_MotTq_Nm = calMotTq1;
    TX_INTER2.S_EcuA_MotTq_Nm = calMotTq1;

    (void)ret_Read_0_reqd;
    ret_Read_0_reqd = Rte_Read_R_CalMotTqReq_MotTqReqd(&arg_Read_data_0_reqd);
    calMotTqReqd1=((arg_Read_data_0_reqd  - InterLane_OFFSET)/InterLane_FACTOR);
    TX_INTER1.S_EcuA_MotTqReqd_Nm =calMotTqReqd1;
    TX_INTER2.S_EcuA_MotTqReqd_Nm =calMotTqReqd1;

    (void)ret_Read_7;
    ret_Read_7 = Rte_Read_R_CompFctModCrp_CompFctMod(&arg_Read_data_7);
    TX_INTER1.S_EcuA_CompFctModCrp_Enum = arg_Read_data_7;
    TX_INTER2.S_EcuA_CompFctModCrp_Enum = arg_Read_data_7;

    (void)ret_Read_8;
    ret_Read_8 = Rte_Read_R_CompFctSoHDrrp_CompFctSoH(&arg_Read_data_8);
    TX_INTER1.S_EcuA_CompFctSoHDrrp_Enum = arg_Read_data_8;
    TX_INTER2.S_EcuA_CompFctSoHDrrp_Enum = arg_Read_data_8;

    (void)ret_Write_2_ID100_INTER1;
    ret_Write_2_ID100_INTER1 = Rte_Write_P_IntLane1PduOutCnvn_IntLane1PduOutCnvn(&TX_INTER1);
    (void)ret_Write_3_ID100_INTER2;
    ret_Write_3_ID100_INTER2 = Rte_Write_P_IntLane2PduOutCnvn_IntLane2PduOutCnvn(&TX_INTER2);

    /* ------------[External CAN]-------------- */
     /* ------------[ID_066 ]-------------- */
     /* Receive from ASW and send to E2E(CAN BUS) */

     (void)ret_Read_2;
     ret_Read_2 = Rte_Read_R_CalSysFctStPpa_SysFctSt(&arg_Read_data_2);
     TX_ID066.S_SysFctModPpa_Enum= arg_Read_data_2.SysFctMod;

     (void)ret_Read_3;
     ret_Read_3 = Rte_Read_R_CalSysFctStPrf_SysFctSt(&arg_Read_data_3);
     TX_ID066.S_SysFctModPrf_Enum=arg_Read_data_3.SysFctMod;

     (void)ret_Read_4;
     ret_Read_4 = Rte_Read_R_CalSysFctStIrp_SysFctSt(&arg_Read_data_4);
     TX_ID066.S_SysFctModIrp_Enum=arg_Read_data_4.SysFctMod;

     (void)ret_Read_5;
     ret_Read_5 = Rte_Read_R_CalSysFctStPbd_SysFctSt(&arg_Read_data_5);
     TX_ID066.S_SysFctModPbd_Enum=arg_Read_data_5.SysFctMod;

     (void)ret_Write_1;
     ret_Write_1 = Rte_Write_P_SysFctModPduOutCnvn_SysFctModPduOutCnvn(&TX_ID066);

     /* ------------[ID_065 ]-------------- */
     /*Receive from ASW and send to E2E(CAN BUS) */

     TX_ID065.S_SysFctSoHIrp_Enum = arg_Read_data_4.SysFctSoH;
     TX_ID065.S_SysFctSoHPbd_Enum = arg_Read_data_5.SysFctSoH;

     (void)ret_Write_0;
     ret_Write_0 = Rte_Write_P_PbdIrpPduOutCnvn_PbdIrpPduOutCnvn(&TX_ID065);

     /* ------------[ID_064 ]-------------- */
     /* Receive from ASW and send to E2E(CAN BUS) */

     TX_ID064.S_SysFctSoHPpa_Enum = arg_Read_data_2.SysFctSoH;
     TX_ID064.S_SysFctSoHPrf_Enum = arg_Read_data_3.SysFctSoH;

     (void)ret_Read_1;
     ret_Read_1 = Rte_Read_R_CalRackFEstimd_RackFEstimd(&arg_Read_data_1);
     calRackFEstimd_id064 =((arg_Read_data_1 - ID_064_CalRackFEstimd_OFFSET)/ID_064_CalRackFEstimd_FACTOR );/* float to uint16 conversion(Open point )*/
     TX_ID064.S_Rwa_RackFEstimd_N = calRackFEstimd_id064;

     (void)ret_Read_10;
     ret_Read_10 = Rte_Read_R_CalPinionAg_PinionAg(&arg_Read_data_10);
     pinionAg = ((arg_Read_data_10 - ID_064_CalPinionAg_OFFSET )/ ID_064_CalPinionAg_FACTOR);/* float to uint16 conversion (Open point ) */
     TX_ID064.S_Rwa_PinionAg_Deg = pinionAg;

     (void)ret_Write;
     ret_Write = Rte_Write_P_PrfPpaPduOutCnvn_SG_ID064_RwaA_HwaA(&TX_ID064);

     /* Time_Out for ID641 Int_1 */
	 (void)ret_Read_ID641_INTER1_1;
	 ret_Read_ID641_INTER1_1 = Rte_Read_R_IntLane1ComPdu_DT_IntLane1ComPdu(&arg_Read_data_ID641_INTER1);
	 if((ret_Read_ID641_INTER1_1 & RTE_E_MAX_AGE_EXCEEDED) == RTE_E_MAX_AGE_EXCEEDED)
	 {
 /* A timeout has occurred and has been reported */
	WaitForFirstData[MSG_INT1] = TRUE;
	 }

	/* Time_Out for ID010  */
	(void)ret_Read_ID010;
	ret_Read_ID010 = Rte_Read_R_FwsComPdu_DT_FwsComPdu(&arg_Read_data_ID010);
	if((ret_Read_ID010 & RTE_E_MAX_AGE_EXCEEDED) == RTE_E_MAX_AGE_EXCEEDED)
	{
 /* A timeout has occurred and has been reported */
	WaitForFirstData[ID010] = TRUE;
	}

	 /* Time_Out for ID00F */
	(void)ret_Read_ID00F;
	ret_Read_ID00F = Rte_Read_R_PinionComPdu_DT_PinionComPdu(&arg_Read_data_ID00F);
	/* TimeOut Implementation */
	if((ret_Read_ID00F & RTE_E_MAX_AGE_EXCEEDED) == RTE_E_MAX_AGE_EXCEEDED)
	{
  /* A timeout has occurred and has been reported */
	WaitForFirstData[ID00F] = TRUE;
	}

	/* Time_Out for ID641 Int_2 */
	(void)ret_Read_ID641_INTER2;
	ret_Read_ID641_INTER2 = Rte_Read_R_IntLane2ComPdu_DT_IntLane2ComPdu(&arg_Read_data_ID641_INTER2);
	if((ret_Read_ID641_INTER2 & RTE_E_MAX_AGE_EXCEEDED) == RTE_E_MAX_AGE_EXCEEDED)
	{
   /* A timeout has occurred and has been reported */
	WaitForFirstData[MSG_INT2] = TRUE;
	}

} /* FUNC(void, RTE_CODE) Swc_E2ESafetyCom_Runnable (void) */

FUNC(void, RTE_CODE) Swc_E2ESafetyCom_E2ESafetyCom_ID641_INTER1 (void)
{
  uint8 Data_Tx[8]={0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U};
  uint8 ReceivedCounter_E2E;
  uint8 E2E_MsgChkSts_ID641_INTER1 = 0U;
  uint8 E2E_CrcRes_ID641_INTER1 = 0U;
  boolean E2E_SeqRes_ID641_INTER1 = FALSE;
  uint8 ID641_IntLane1_crc;
  uint8 cal_Crc_ID641_IntLane1;
  float Calmottqintlane1;
  float CalMotTq1;
  float CalMotTqReqd1;
  DT_SG_ID641_EcuB_EcuA arg_Read_data_ID641_INTER1;
  Std_ReturnType ret_Read_ID641_INTER1_1;
  boolean ret_IsUpdated_ID641_INTER1;

	(void)ret_Read_ID641_INTER1_1;
	ret_Read_ID641_INTER1_1 = Rte_Read_R_IntLane1ComPdu_DT_IntLane1ComPdu(&arg_Read_data_ID641_INTER1);
	ReceivedCounter_E2E = arg_Read_data_ID641_INTER1.S_EcuB_MsgCnt;
	Data_Tx[0] = ((arg_Read_data_ID641_INTER1.S_EcuB_MotTqReqd_Nm & 0x000F)<<4) | (arg_Read_data_ID641_INTER1.S_EcuB_MsgCnt & 0x0F);
	Data_Tx[1] = ((arg_Read_data_ID641_INTER1.S_EcuB_MotTqReqd_Nm & 0x0FF0)>>4);
	Data_Tx[2] = ((arg_Read_data_ID641_INTER1.S_EcuB_MotTq_Nm & 0x003F)<<2) | ((arg_Read_data_ID641_INTER1.S_EcuB_MotTqReqd_Nm & 0x3000)>>12);
	Data_Tx[3] = ((arg_Read_data_ID641_INTER1.S_EcuB_MotTq_Nm & 0x3FC0)>>6) ;
	Data_Tx[4] = (arg_Read_data_ID641_INTER1.S_EcuB_MotTqIntLane_Nm & 0x00FF) ;
	Data_Tx[5] = ((arg_Read_data_ID641_INTER1.S_EcuB_CompFctModCrp_Enum & 0x0003)<<6) | (arg_Read_data_ID641_INTER1.S_EcuB_MotTqIntLane_Nm & 0x3F00)>>8;
	Data_Tx[6] = ((arg_Read_data_ID641_INTER1.S_EcuB_CompFctSoHDrrp_Enum & 0x0003)<<6) | (arg_Read_data_ID641_INTER1.S_EcuB_CompFctModCrp_Enum & 0x00FC)>>2;
	Data_Tx[7] = ((arg_Read_data_ID641_INTER1.S_EcuB_CompFctSoHDrrp_Enum & 0x00FC)>>2) ;
	cal_Crc_ID641_IntLane1 = E2E_EB_CalculateCrc_E2E(DATA_LEN_ID641_INT1, Data_Tx, ReceivedCounter_E2E);
	ID641_IntLane1_crc = arg_Read_data_ID641_INTER1.S_EcuB_Chksm;
  if(ID641_IntLane1_crc == cal_Crc_ID641_IntLane1)
  {
	/* correct CRC */
	  E2E_MsgChkSts_ID641_INTER1 = E2E_Seq_Check(ReceivedCounter_E2E , MSG_INT1);
	  E2E_SeqRes_ID641_INTER1 = E2E_MsgChkSts_ID641_INTER1;
  }
  else
  {
	/* wrong CRC */
	  E2E_MsgChkSts_ID641_INTER1 = E2E_P02STATUS_WRONGCRC;
	  E2E_CrcRes_ID641_INTER1 = E2E_CRCERROR ;
  }
  /* Uint16 to float conversion */
  /* Receive from E2E and send to SwcOut */
  Calmottqintlane1 = (float)((arg_Read_data_ID641_INTER1.S_EcuB_MotTqIntLane_Nm * InterLane_FACTOR) + InterLane_OFFSET);
  RX_INTER1.S_Ecu_MotTqIntLane_Nm = Calmottqintlane1;

  CalMotTq1 = (float)((arg_Read_data_ID641_INTER1.S_EcuB_MotTq_Nm * InterLane_FACTOR) + InterLane_OFFSET);
  RX_INTER1.S_Ecu_MotTq_Nm = CalMotTq1;

  CalMotTqReqd1 = (float)((arg_Read_data_ID641_INTER1.S_EcuB_MotTqReqd_Nm * InterLane_FACTOR) +InterLane_OFFSET);
  RX_INTER1.S_Ecu_MotTqReqd_Nm = CalMotTqReqd1;

  RX_INTER1.S_Ecu_CompFctModCrp_Enum = arg_Read_data_ID641_INTER1.S_EcuB_CompFctModCrp_Enum;
  RX_INTER1.S_Ecu_CompFctSoHDrrp_Enum = arg_Read_data_ID641_INTER1.S_EcuB_CompFctSoHDrrp_Enum;
  RX_INTER1.MsgIntLane1E2eChkSts = E2E_MsgChkSts_ID641_INTER1;
  if(E2E_CrcRes_ID641_INTER1== 1 || E2E_SeqRes_ID641_INTER1 == 1)
  	  {
  		  Age_Error_IntLane1 = 1;
  	  }
  	  else
  	  {
  		  Age_Error_IntLane1 = 0;
  	  }
  (void)ret_IsUpdated_ID641_INTER1;
  ret_IsUpdated_ID641_INTER1 = Rte_IsUpdated_R_IntLane1ComPdu_DT_IntLane1ComPdu();

} /* FUNC(void, RTE_CODE) Swc_E2ESafetyCom_E2ESafetyCom_ID641_INTER1 (void) */

FUNC(void, RTE_CODE) Swc_E2ESafetyCom_DataReceived_ID010 (void)
{
	uint8 Data_Tx[4]={0x00U, 0x00U, 0x00U, 0x00U};
    uint8 ReceivedCounter_E2E;
	uint8 E2E_MsgChkSts_ID010 = 0U;
    uint8 E2E_CrcRes_ID010 = 0U;
	boolean E2E_SeqRes_ID010 = FALSE;
	uint8 ID010_crc;
	uint8 cal_Crc_ID010;
	DT_SG_ID010_HwaA_RwaA arg_Read_data_ID010;
	Std_ReturnType ret_Read_ID010;
    boolean ret_IsUpdated_ID010;

  (void)ret_Read_ID010;
  ret_Read_ID010 = Rte_Read_R_FwsComPdu_DT_FwsComPdu(&arg_Read_data_ID010);
  ReceivedCounter_E2E = arg_Read_data_ID010.S_Msg010Cnt;
  Data_Tx[0] = ((arg_Read_data_ID010.S_FwsSysFctModManSteerFwd_Enum & 0x0F)<<4) | (arg_Read_data_ID010.S_Msg010Cnt & 0x0F);
  Data_Tx[1] = ((arg_Read_data_ID010.S_FwsSysFctModManSteerBwd_Enum & 0x0F)<<4) | ((arg_Read_data_ID010.S_FwsSysFctModManSteerFwd_Enum & 0xF0)>>4);
  Data_Tx[2] = ((arg_Read_data_ID010.S_FwsSysFctModIngressEgress_Enum & 0x0F)<<4) | ((arg_Read_data_ID010.S_FwsSysFctModManSteerBwd_Enum & 0xF0)>>4);
  Data_Tx[3] = ((arg_Read_data_ID010.S_FwsSysFctModIngressEgress_Enum & 0xF0)>>4);
  cal_Crc_ID010 = E2E_EB_CalculateCrc_E2E(DATA_LEN_ID010, Data_Tx, ReceivedCounter_E2E);
  ID010_crc = arg_Read_data_ID010.S_Msg010Chksm;
 if(ID010_crc == cal_Crc_ID010)
 {
	/* correct CRC */
	 E2E_MsgChkSts_ID010 = E2E_Seq_Check(ReceivedCounter_E2E , ID010);
	 E2E_SeqRes_ID010 = E2E_MsgChkSts_ID010;
 }
 else
 {
	/* wrong CRC */
	 E2E_MsgChkSts_ID010 = E2E_P02STATUS_WRONGCRC;
	 E2E_CrcRes_ID010 = E2E_CRCERROR;
 }
  RX_ID010.FwsSysFctModIngressEgress = arg_Read_data_ID010.S_FwsSysFctModIngressEgress_Enum;
  RX_ID010.FwsSysFctModManSteerBwd = arg_Read_data_ID010.S_FwsSysFctModManSteerBwd_Enum;
  RX_ID010.FwsSysFctModManSteerFwd = arg_Read_data_ID010.S_FwsSysFctModManSteerFwd_Enum;
  RX_ID010.MsgFwsE2eChkSts = E2E_MsgChkSts_ID010;
  if(E2E_CrcRes_ID010== 1 || E2E_SeqRes_ID010 == 1)
  	  {
	  Age_Error_ID010 = 1;
  	  }
  	  else
  	  {
  		Age_Error_ID010 = 0;
  	  }
  (void)ret_IsUpdated_ID010;
   ret_IsUpdated_ID010 = Rte_IsUpdated_R_FwsComPdu_DT_FwsComPdu();
} /* FUNC(void, RTE_CODE) Swc_E2ESafetyCom_DataReceived_ID010 (void) */

FUNC(void, RTE_CODE) Swc_E2ESafetyCom_DataReceived_ID00F (void)
{
  uint8 Data_Tx[6]={0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U};
  uint8 ReceivedCounter_E2E;
  uint8 E2E_MsgChkSts_ID00F = 0U;
  uint8 E2E_CrcRes_ID00F = 0U;
  boolean E2E_SeqRes_ID00F = FALSE;
  uint8 ID00F_crc;
  uint8 cal_Crc_ID00F;
  float PinionAgReqdA ;
  float ShaftratVar;
  DT_SG_ID00F_HwaA_RwaA arg_Read_data_ID00F;
  Std_ReturnType ret_Read_ID00F;
  boolean ret_IsUpdated_ID00F;

 (void)ret_Read_ID00F;
 ret_Read_ID00F = Rte_Read_R_PinionComPdu_DT_PinionComPdu(&arg_Read_data_ID00F);
 ReceivedCounter_E2E = arg_Read_data_ID00F.S_Msg00FCnt;
 Data_Tx[0] = ((arg_Read_data_ID00F.S_Hwa_PinionAgReqdA & 0x000F)<<4) | (arg_Read_data_ID00F.S_Msg00FCnt & 0x0F);
 Data_Tx[1] = ((arg_Read_data_ID00F.S_Hwa_PinionAgReqdA & 0x0FF0)>>4);
 Data_Tx[2] = ((arg_Read_data_ID00F.S_Hwa_ShaftRatVar & 0x0F)<<4) | ((arg_Read_data_ID00F.S_Hwa_PinionAgReqdA & 0xF000)>>12);
 Data_Tx[3] = ((arg_Read_data_ID00F.S_SysFctSoHPrpa_Enum & 0x0007)<<5) | (arg_Read_data_ID00F.S_Hwa_ShaftRatVar & 0x01F0)>>4;
 Data_Tx[4] = ((arg_Read_data_ID00F.S_SysFctSoHPrpa_Enum & 0x00F8)>>3) ;
 cal_Crc_ID00F = E2E_EB_CalculateCrc_E2E(DATA_LEN_ID00F, Data_Tx, ReceivedCounter_E2E);
 ID00F_crc = arg_Read_data_ID00F.S_Msg00FChksm;
 if(ID00F_crc == cal_Crc_ID00F)
 {
	/* correct CRC */
	 E2E_MsgChkSts_ID00F = E2E_Seq_Check(ReceivedCounter_E2E , ID00F);
	 E2E_SeqRes_ID00F = E2E_MsgChkSts_ID00F;
 }
 else
 {
	/* wrong CRC */
	 E2E_MsgChkSts_ID00F = E2E_P02STATUS_WRONGCRC;
	 E2E_CrcRes_ID00F = E2E_CRCERROR;
 }
  /* Uint16 to float conversion */
  /* Receive from E2E(CAN BUS) and send to SwcInp */
  PinionAgReqdA = (float)((arg_Read_data_ID00F.S_Hwa_PinionAgReqdA * ID_00F_PinionAgReqdA_FACTOR) + ID_00F_PinionAgReqdA_OFFSET);
  ID_00F.PinionAgReqdA = PinionAgReqdA;

  ShaftratVar = (float)((arg_Read_data_ID00F.S_Hwa_ShaftRatVar * ID_00F_ShaftRatVar_FACTOR) + ID_00F_ShaftRatVar_OFFSET);
  ID_00F.ShaftRatVar 	= ShaftratVar;

  ID_00F.SysFctSoHPrpa 	= arg_Read_data_ID00F.S_SysFctSoHPrpa_Enum;
  ID_00F.MsgPinionE2eChkSts = E2E_MsgChkSts_ID00F;
  if(E2E_CrcRes_ID00F== 1 || E2E_SeqRes_ID00F == 1)
  {
	  Age_Error_ID00F = 1;
  }
  else
    {
	  Age_Error_ID00F = 0;
    }
  (void)ret_IsUpdated_ID00F;
  ret_IsUpdated_ID00F = Rte_IsUpdated_R_PinionComPdu_DT_PinionComPdu();
} /* FUNC(void, RTE_CODE) Swc_E2ESafetyCom_DataReceived_ID00F (void) */

FUNC(void, RTE_CODE) Swc_E2ESafetyCom_E2ESafetyCom_ID641_INTER2 (void)
{
  uint8 Data_Tx[8]={0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U};
  uint8 ReceivedCounter_E2E;
  uint8 E2E_MsgChkSts_ID641_INTER2 = 0U;
  uint8 E2E_CrcRes_ID641_INTER2 = 0U;
  boolean E2E_SeqRes_ID641_INTER2 = FALSE;
  uint8 ID641_IntLane2_crc;
  uint8 cal_Crc_ID641_IntLane2;
  float Calmottqintlane2;
  float CalMotTq2;
  float CalMotTqReqd2;
  DT_SG_ID641_EcuB_EcuA arg_Read_data_ID641_INTER2;
  Std_ReturnType ret_Read_ID641_INTER2;

	(void)ret_Read_ID641_INTER2;
	ret_Read_ID641_INTER2 = Rte_Read_R_IntLane2ComPdu_DT_IntLane2ComPdu(&arg_Read_data_ID641_INTER2);;
	ReceivedCounter_E2E = arg_Read_data_ID641_INTER2.S_EcuB_MsgCnt;
	Data_Tx[0] = ((arg_Read_data_ID641_INTER2.S_EcuB_MotTqReqd_Nm & 0x000F)<<4) | (arg_Read_data_ID641_INTER2.S_EcuB_MsgCnt & 0x0F);
	Data_Tx[1] = ((arg_Read_data_ID641_INTER2.S_EcuB_MotTqReqd_Nm & 0x0FF0)>>4);
	Data_Tx[2] = ((arg_Read_data_ID641_INTER2.S_EcuB_MotTq_Nm & 0x003F)<<2) | ((arg_Read_data_ID641_INTER2.S_EcuB_MotTqReqd_Nm & 0x3000)>>12);
	Data_Tx[3] = ((arg_Read_data_ID641_INTER2.S_EcuB_MotTq_Nm & 0x3FC0)>>6) ;
	Data_Tx[4] = (arg_Read_data_ID641_INTER2.S_EcuB_MotTqIntLane_Nm & 0x00FF) ;
	Data_Tx[5] = ((arg_Read_data_ID641_INTER2.S_EcuB_CompFctModCrp_Enum & 0x0003)<<6) | (arg_Read_data_ID641_INTER2.S_EcuB_MotTqIntLane_Nm & 0x3F00)>>8;
	Data_Tx[6] = ((arg_Read_data_ID641_INTER2.S_EcuB_CompFctSoHDrrp_Enum & 0x0003)<<6) | (arg_Read_data_ID641_INTER2.S_EcuB_CompFctModCrp_Enum & 0x00FC)>>2;
	Data_Tx[7] = ((arg_Read_data_ID641_INTER2.S_EcuB_CompFctSoHDrrp_Enum & 0x00FC)>>2) ;
	cal_Crc_ID641_IntLane2=E2E_EB_CalculateCrc_E2E(DATA_LEN_ID641_INT2, Data_Tx, ReceivedCounter_E2E);
	ID641_IntLane2_crc = arg_Read_data_ID641_INTER2.S_EcuB_Chksm;
	 if(ID641_IntLane2_crc == cal_Crc_ID641_IntLane2)
	 {
		/* correct CRC */
		 E2E_MsgChkSts_ID641_INTER2 = E2E_Seq_Check(ReceivedCounter_E2E , MSG_INT2);
		 E2E_SeqRes_ID641_INTER2 = E2E_MsgChkSts_ID641_INTER2;
	  }
	  else
	  {
		/* wrong CRC */
		 E2E_MsgChkSts_ID641_INTER2 = E2E_P02STATUS_WRONGCRC;
		 E2E_CrcRes_ID641_INTER2 = E2E_CRCERROR ;
	  }

	  Calmottqintlane2 = (float)((arg_Read_data_ID641_INTER2.S_EcuB_MotTqIntLane_Nm * InterLane_FACTOR) +InterLane_OFFSET);
	  RX_INTER2.S_Ecu_MotTqIntLane_Nm = Calmottqintlane2;

	  CalMotTq2 = (float)((arg_Read_data_ID641_INTER2.S_EcuB_MotTq_Nm * InterLane_FACTOR) +InterLane_OFFSET);
	  RX_INTER2.S_Ecu_MotTq_Nm = CalMotTq2;

	  CalMotTqReqd2 = (float)((arg_Read_data_ID641_INTER2.S_EcuB_MotTqReqd_Nm * InterLane_FACTOR) +InterLane_OFFSET);
	  RX_INTER2.S_Ecu_MotTqReqd_Nm = CalMotTqReqd2;

	  RX_INTER2.S_Ecu_CompFctModCrp_Enum = arg_Read_data_ID641_INTER2.S_EcuB_CompFctModCrp_Enum;
	  RX_INTER2.S_Ecu_CompFctSoHDrrp_Enum = arg_Read_data_ID641_INTER2.S_EcuB_CompFctSoHDrrp_Enum;
	  RX_INTER2.MsgIntLane2E2eChkSts = E2E_MsgChkSts_ID641_INTER2;
	  if(E2E_CrcRes_ID641_INTER2== 1 || E2E_SeqRes_ID641_INTER2 == 1)
	  {
		  Age_Error_IntLane2 = 1;
	  }
	  else
	  {
		  Age_Error_IntLane2=0;
	  }

} /* FUNC(void, RTE_CODE) Swc_E2ESafetyCom_E2ESafetyCom_ID641_INTER2 (void) */
FUNC(void, RTE_CODE) Calculate_Age_E2ESafetyCom (void)
{
	if(Age_Error_IntLane1 == 1 || WaitForFirstData[MSG_INT1] ==1 )
	{
		if(IntLane1_Age < 65535)
			IntLane1_Age++;
	}
	else
	{
		IntLane1_Age = 0;
	}
RX_INTER1.MsgIntLane1Age = IntLane1_Age;
(void)ret_Write_6;
ret_Write_6 = Rte_Write_P_IntLane1PduInCnvn_IntLane1PduInCnvn(&RX_INTER1);

   if(Age_Error_IntLane2 == 1 || WaitForFirstData[MSG_INT2] ==1 )
	{
		if(IntLane2_Age < 65535)
			IntLane2_Age++;
	}
	else
	{
		IntLane2_Age = 0;
	}
  RX_INTER2.MsgIntLane2Age = IntLane2_Age;
  (void)ret_Write_7;
  ret_Write_7 = Rte_Write_P_IntLane2PduInCnvn_IntLane2PduInCnvn(&RX_INTER2);

	if(Age_Error_ID00F == 1 || WaitForFirstData[ID00F] ==1 )
	{
		if(ID00F_Age < 65535)
			ID00F_Age++;
	}
	else
	{
		ID00F_Age = 0;
	}
 ID_00F.MsgPinionAge = ID00F_Age;
 (void)ret_Write_4;
 ret_Write_4 = Rte_Write_P_PinionPduInCnvn_PinionPduInCnvn(&ID_00F);

	if(Age_Error_ID010 == 1 || WaitForFirstData[ID010] ==1 )
	{
	  if(ID010_Age < 65535)
		  ID010_Age++;
	}
	else
	{
		ID010_Age = 0;
	}

RX_ID010.MsgFwsAge = ID010_Age;
(void)ret_Write_5;
ret_Write_5 = Rte_Write_P_FwsPduInCnvn_FwsPduInCnvn(&RX_ID010);


} /* FUNC(void, RTE_CODE) Age_E2ESafetyCom (void) */
/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
