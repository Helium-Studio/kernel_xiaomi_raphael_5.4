/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 */

#ifndef __H_MSM_VIDC_BUS_DEFS_H__
#define __H_MSM_VIDC_BUS_DEFS_H__

#include <linux/module.h>
#include "msm_vidc_debug.h"
#include "fixedpoint.h"
#include "vidc_hfi_api.h"

#define COMPRESSION_RATIO_MAX 5

enum vidc_bus_type {
	PERF,
	DDR,
	LLCC,
};

/*
 * Minimum dimensions for which to calculate bandwidth.
 * This means that anything bandwidth(0, 0) ==
 * bandwidth(BASELINE_DIMENSIONS.width, BASELINE_DIMENSIONS.height)
 */
static const struct {
	int height, width;
} BASELINE_DIMENSIONS = {
	.width = 1280,
	.height = 720,
};

/* converts Mbps to bps (the "b" part can be bits or bytes based on context) */
#define kbps(__mbps) ((__mbps) * 1000)
#define bps(__mbps) (kbps(__mbps) * 1000)

#define GENERATE_COMPRESSION_PROFILE(__bpp, __worst) {              \
	.bpp = __bpp,                                                          \
	.ratio = __worst,                \
}

/*
 * The below table is a structural representation of the following table:
 *  Resolution |    Bitrate |              Compression Ratio          |
 * ............|............|.........................................|
 * Width Height|Average High|Avg_8bpc Worst_8bpc Avg_10bpc Worst_10bpc|
 *  1280    720|      7   14|    1.69       1.28      1.49        1.23|
 *  1920   1080|     20   40|    1.69       1.28      1.49        1.23|
 *  2560   1440|     32   64|     2.2       1.26      1.97        1.22|
 *  3840   2160|     42   84|     2.2       1.26      1.97        1.22|
 *  4096   2160|     44   88|     2.2       1.26      1.97        1.22|
 *  4096   2304|     48   96|     2.2       1.26      1.97        1.22|
 */
static struct lut {
	int frame_size; /* width x height */
	int frame_rate;
	unsigned long bitrate;
	struct {
		int bpp;
		fp_t ratio;
	} compression_ratio[COMPRESSION_RATIO_MAX];
} const LUT[] = {
	{
		.frame_size = 1280 * 720,
		.frame_rate = 30,
		.bitrate = 14,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 28, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 23, 100)),
		}
	},
	{
		.frame_size = 1280 * 720,
		.frame_rate = 60,
		.bitrate = 22,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 28, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 23, 100)),
		}
	},
	{
		.frame_size = 1920 * 1088,
		.frame_rate = 30,
		.bitrate = 40,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 28, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 23, 100)),
		}
	},
	{
		.frame_size = 1920 * 1088,
		.frame_rate = 60,
		.bitrate = 64,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 28, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 23, 100)),
		}
	},
	{
		.frame_size = 2560 * 1440,
		.frame_rate = 30,
		.bitrate = 64,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
	{
		.frame_size = 2560 * 1440,
		.frame_rate = 60,
		.bitrate = 102,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
	{
		.frame_size = 3840 * 2160,
		.frame_rate = 30,
		.bitrate = 84,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
	{
		.frame_size = 3840 * 2160,
		.frame_rate = 60,
		.bitrate = 134,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
	{
		.frame_size = 4096 * 2160,
		.frame_rate = 30,
		.bitrate = 88,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
	{
		.frame_size = 4096 * 2160,
		.frame_rate = 60,
		.bitrate = 141,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
	{
		.frame_size = 4096 * 2304,
		.frame_rate = 30,
		.bitrate = 96,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
	{
		.frame_size = 4096 * 2304,
		.frame_rate = 60,
		.bitrate = 154,
		.compression_ratio = {
			GENERATE_COMPRESSION_PROFILE(8,
					FP(1, 26, 100)),
			GENERATE_COMPRESSION_PROFILE(10,
					FP(1, 22, 100)),
		}
	},
};

static inline u32 get_type_frm_name(const char *name)
{
	if (!strcmp(name, "venus-llcc"))
		return LLCC;
	else if (!strcmp(name, "venus-ddr"))
		return DDR;
	else
		return PERF;
}

static inline struct lut const *__lut(int width, int height, int fps)
{
	int frame_size = height * width, c = 0;

	do {
		if (LUT[c].frame_size >= frame_size && LUT[c].frame_rate >= fps)
			return &LUT[c];
	} while (++c < ARRAY_SIZE(LUT));

	return &LUT[ARRAY_SIZE(LUT) - 1];
}

static inline fp_t __compression_ratio(struct lut const *entry, int bpp)
{
	int c = 0;

	for (c = 0; c < COMPRESSION_RATIO_MAX; ++c) {
		if (entry->compression_ratio[c].bpp == bpp)
			return entry->compression_ratio[c].ratio;
	}

	WARN(true, "Shouldn't be here, LUT possibly corrupted?\n");
	return FP_ZERO; /* impossible */
}

#define DUMP_HEADER_MAGIC 0xdeadbeef
#define DUMP_FP_FMT "%FP" /* special format for fp_t */
struct dump {
	char *key;
	char *format;
	size_t val;
};

static inline void __dump(struct dump dump[], int len)
{
	int c = 0;

	for (c = 0; c < len; ++c) {
		char format_line[128] = "", formatted_line[128] = "";

		if (dump[c].val == DUMP_HEADER_MAGIC) {
			snprintf(formatted_line, sizeof(formatted_line), "%s\n",
					dump[c].key);
		} else {
			bool fp_format = !strcmp(dump[c].format, DUMP_FP_FMT);

			if (!fp_format) {
				snprintf(format_line, sizeof(format_line),
						"    %-35s: %s\n", dump[c].key,
						dump[c].format);
				snprintf(formatted_line, sizeof(formatted_line),
						format_line, dump[c].val);
			} else {
				size_t integer_part, fractional_part;

				integer_part = fp_int(dump[c].val);
				fractional_part = fp_frac(dump[c].val);
				snprintf(formatted_line, sizeof(formatted_line),
						"    %-35s: %zd + %zd/%zd\n",
						dump[c].key, integer_part,
						fractional_part,
						fp_frac_base());


			}
		}

		dprintk(VIDC_DBG, "%s", formatted_line);
	}
}

static inline bool __ubwc(enum hal_uncompressed_format f)
{
	switch (f) {
	case HAL_COLOR_FORMAT_NV12_UBWC:
	case HAL_COLOR_FORMAT_NV12_TP10_UBWC:
		return true;
	default:
		return false;
	}
}

static inline int __bpp(enum hal_uncompressed_format f)
{
	switch (f) {
	case HAL_COLOR_FORMAT_NV12:
	case HAL_COLOR_FORMAT_NV21:
	case HAL_COLOR_FORMAT_NV12_UBWC:
		return 8;
	case HAL_COLOR_FORMAT_NV12_TP10_UBWC:
	case HAL_COLOR_FORMAT_P010:
		return 10;
	default:
		dprintk(VIDC_ERR,
				"What's this?  We don't support this colorformat (%x)",
				f);
		return INT_MAX;
	}
}

unsigned long __calc_bw(struct bus_info *bus,
			struct msm_vidc_gov_data *vidc_data);
unsigned long __calc_bw_ar50(struct bus_info *bus,
				struct msm_vidc_gov_data *vidc_data);

#endif // __H_MSM_VIDC_BUS_DEFS_H__
