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

#ifndef __HAL_PHY_RF_8821A_H__
#define __HAL_PHY_RF_8821A_H__

/*--------------------------Define Parameters-------------------------------*/
#define	IQK_DELAY_TIME_8821A		10		//ms
#define	index_mapping_NUM_8821A	15
#define AVG_THERMAL_NUM_8821A	4
#define RF_T_METER_8821A		0x42


void ConfigureTxpowerTrack_8821A(
	PTXPWRTRACK_CFG	pConfig
	);

void DoIQK_8821A(
	PDM_ODM_T	pDM_Odm,
	u1Byte		DeltaThermalIndex,
	u1Byte		ThermalValue,
	u1Byte		Threshold
	);

void
ODM_TxPwrTrackSetPwr8821A(
	PDM_ODM_T			pDM_Odm,
	PWRTRACK_METHOD		Method,
	u1Byte				RFPath,
	u1Byte				ChannelMappedIndex
	);

//1 7.	IQK

void
PHY_IQCalibrate_8821A(
	PADAPTER	pAdapter,
	bool		bReCovery
);

void
PHY_LCCalibrate_8821A(
	PDM_ODM_T		pDM_Odm
);

void
GetDeltaSwingTable_8821A(
	PDM_ODM_T			pDM_Odm,
	pu1Byte			*TemperatureUP_A,
	pu1Byte			*TemperatureDOWN_A,
	pu1Byte			*TemperatureUP_B,
	pu1Byte			*TemperatureDOWN_B
);

void PHY_SetRFPathSwitch_8821A(
	PADAPTER	pAdapter,
	bool		bMain
	);


#endif	// #ifndef __HAL_PHY_RF_8821A_H__
