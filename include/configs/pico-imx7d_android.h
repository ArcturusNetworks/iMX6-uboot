
/*
 * Copyright (C) 2015-2016 Freescale Semiconductor, Inc.
 * Copyright (C) 2019 Technexion Ltd.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __PICO_IMX7D_ANDROID_H
#define __PICO_IMX7D_ANDROID_H
#include "mx_android_common.h"

#define CONFIG_CMD_FASTBOOT
#define CONFIG_ANDROID_BOOT_IMAGE
/* lock/unlock stuff */
#define FASTBOOT_ENCRYPT_LOCK
#define CONFIG_FASTBOOT_LOCK
#define FSL_FASTBOOT_FB_DEV "mmc"

#define CONFIG_AVB_SUPPORT
#ifdef CONFIG_AVB_SUPPORT
#define CONFIG_ANDROID_RECOVERY

#ifdef CONFIG_SYS_CBSIZE
#undef CONFIG_SYS_CBSIZE
#define CONFIG_SYS_CBSIZE 2048
#endif
#ifdef CONFIG_SYS_MAXARGS
#undef CONFIG_SYS_MAXARGS
#define CONFIG_SYS_MAXARGS     64
#endif

#ifdef CONFIG_SYS_MALLOC_LEN
#undef CONFIG_SYS_MALLOC_LEN
#define CONFIG_SYS_MALLOC_LEN           (96 * SZ_1M)
#endif

#endif /* CONFIG_AVB_SUPPORT */

#define AVB_AB_I_UNDERSTAND_LIBAVB_AB_IS_DEPRECATED

#endif
