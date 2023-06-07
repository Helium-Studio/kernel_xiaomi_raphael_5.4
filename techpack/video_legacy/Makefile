# SPDX-License-Identifier: GPL-2.0-only

# auto-detect subdirs
ifeq ($(CONFIG_ARCH_SM8150), y)
include $(srctree)/techpack/video_legacy/config/sm8150vid.conf
endif

ifeq ($(CONFIG_ARCH_SM8150), y)
LINUXINCLUDE    += -include $(srctree)/techpack/video_legacy/config/sm8150vid.h
endif

LINUXINCLUDE    += -I$(srctree)/techpack/video_legacy/include \
                   -I$(srctree)/techpack/video_legacy/include/uapi

USERINCLUDE     += -I$(srctree)/techpack/video_legacy/include/uapi

obj-y +=msm/
