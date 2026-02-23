/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2020 The Linux Foundation. All rights reserved.
 */

#ifndef __STEP_CHG_H__
#define __STEP_CHG_H__

#include <linux/iio/consumer.h>
#include "smb5-iio.h"

#if defined(CONFIG_MACH_XIAOMI_VAYU)
#define MAX_STEP_CHG_ENTRIES	6
#elif defined(CONFIG_MACH_XIAOMI_SM8150)
#define MAX_STEP_CHG_ENTRIES	5
#else
#define MAX_STEP_CHG_ENTRIES	8
#endif

#if defined(CONFIG_MACH_XIAOMI_VAYU)
#define BATT_CP_COOL_THRESHOLD		100
#define BATT_CP_WARM_THRESHOLD		450

#define BATT_COOL_THRESHOLD		150
#define BATT_WARM_THRESHOLD		450
#define FFC_CHG_TERM_TEMP_THRESHOLD	350
enum hvdcp3_class_type {
	HVDCP3_CLASS_NONE = 0,
	HVDCP3_CLASS_A_18W,
	HVDCP3_CLASS_B_27W,
};
#endif

struct step_chg_jeita_param {
	u32			psy_prop;
	u32			iio_prop;
	char			*prop_name;
	int			hysteresis;
	bool			use_bms;
};

struct range_data {
	int low_threshold;
	int high_threshold;
	u32 value;
};

int qcom_step_chg_init(struct device *dev, bool step_chg_enable,
	bool sw_jeita_enable, bool jeita_arb_en, struct iio_channel *iio_chans);
void qcom_step_chg_deinit(void);
#if defined(CONFIG_MACH_XIAOMI_VAYU)
int qcom_step_chg_get_step_index(void);
#endif
#endif /* __STEP_CHG_H__ */
