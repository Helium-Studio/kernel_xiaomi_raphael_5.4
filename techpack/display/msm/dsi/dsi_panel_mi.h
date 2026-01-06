/*
 * Copyright (c) 2016-2018, The Linux Foundation. All rights reserved.
 * Copyright (C) 2021 XiaoMi, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _DSI_PANEL_MI_H_
#define _DSI_PANEL_MI_H_

#define DEFAULT_FOD_OFF_DIMMING_DELAY	170

enum bkl_dimming_state {
	STATE_NONE,
	STATE_DIM_BLOCK,
	STATE_DIM_RESTORE,
	STATE_ALL
};

enum DISPPARAM_MODE {
	DISPPARAM_DIMMING_OFF = 0xE00,
	DISPPARAM_DIMMING = 0xF00,
	DISPPARAM_ACL_L1 = 0x1000,
	DISPPARAM_ACL_L2 = 0x2000,
	DISPPARAM_ACL_L3 = 0x3000,
	DISPPARAM_ACL_OFF = 0xF000,
	DISPPARAM_HBM_ON = 0x10000,
	DISPPARAM_HBM_FOD_ON = 0x20000,
	DISPPARAM_DC_ON = 0x40000,
	DISPPARAM_DC_OFF = 0x50000,
	DISPPARAN_FOD_FLAG = 0x60000,
	DISPPARAM_HBM_FOD_OFF = 0xE0000,
	DISPPARAM_HBM_OFF = 0xF0000,
	DISPPARAM_P3 = 0x200000,
	DISPPARAM_SRGB = 0x300000,
	DISPPARAM_DOZE_BRIGHTNESS_HBM = 0x600000,
	DISPPARAM_DOZE_BRIGHTNESS_LBM = 0x700000,
	DISPPARAM_DOZE_OFF = 0x800000,
	DISPPARAM_HBM_BACKLIGHT_RESEND = 0xA00000,
	DISPPARAM_FOD_BACKLIGHT = 0xD00000,
	DISPPARAM_CRC_OFF = 0xF00000,
	DISPPARAM_FOD_BACKLIGHT_ON = 0x1000000,
	DISPPARAM_FOD_BACKLIGHT_OFF = 0x2000000,
	DISPPARAM_ELVSS_DIMMING_ON = 0x3000000,
	DISPPARAM_ELVSS_DIMMING_OFF = 0x4000000,
};

static int panel_disp_param_send_lock(struct dsi_panel *panel, int param);
#endif /* _DSI_PANEL_MI_H_ */
