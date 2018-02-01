/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 ******************************************************************************/

 #ifndef __HAL_PHY_RF_H__
 #define __HAL_PHY_RF_H__

typedef enum _SPUR_CAL_METHOD {
	PLL_RESET,
	AFE_PHASE_SEL
} SPUR_CAL_METHOD;

typedef enum _PWRTRACK_CONTROL_METHOD {
	BBSWING,
	TXAGC,
	MIX_MODE
} PWRTRACK_METHOD;

typedef void	(*FuncSetPwr)(PDM_ODM_T, PWRTRACK_METHOD, u1Byte, u1Byte);
typedef void	(*FuncIQK)(PDM_ODM_T, u1Byte, u1Byte, u1Byte);
typedef void	(*FuncLCK)(PDM_ODM_T);
typedef void	(*FuncSwing)(PDM_ODM_T, pu1Byte*, pu1Byte*, pu1Byte*, pu1Byte*);

typedef struct _TXPWRTRACK_CFG {
	u1Byte		SwingTableSize_CCK;
	u1Byte		SwingTableSize_OFDM;
	u1Byte		Threshold_IQK;
	u1Byte		AverageThermalNum;
	u1Byte		RfPathCount;
	u4Byte		ThermalRegAddr;
	FuncSetPwr	ODM_TxPwrTrackSetPwr;
	FuncIQK		DoIQK;
	FuncLCK		PHY_LCCalibrate;
	FuncSwing	GetDeltaSwingTable;
} TXPWRTRACK_CFG, *PTXPWRTRACK_CFG;

void ConfigureTxpowerTrack(
	PDM_ODM_T		pDM_Odm,
	PTXPWRTRACK_CFG	pConfig
	);


void
ODM_ClearTxPowerTrackingState(
	PDM_ODM_T		pDM_Odm
	);

void
ODM_TXPowerTrackingCallback_ThermalMeter(
	PADAPTER	Adapter
	);

#define ODM_TARGET_CHNL_NUM_2G_5G	59

void
ODM_ResetIQKResult(
	PDM_ODM_T	pDM_Odm
);
u1Byte
ODM_GetRightChnlPlaceforIQK(
    u1Byte chnl
);


#endif	// #ifndef __HAL_PHY_RF_H__
