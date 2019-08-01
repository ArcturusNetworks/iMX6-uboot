/*
 * Copyright (C) 2018 Technexion Ltd.
 *
 * Author: Richard Hu <richard.hu@technexion.com>
 *         Po Cheng <po.cheng@technexion.com>
 *
 * SPDX-License-Identifier:    GPL-2.0+
 */

#ifndef __PICO_IMX6_CONFIG_H
#define __PICO_IMX6_CONFIG_H

#include "mx6_common.h"
#include <asm/arch/imx-regs.h>
#include <asm/mach-imx/gpio.h>
#include <linux/sizes.h>

#ifdef CONFIG_SPL
#include "imx6_spl.h"
#endif

#define CONFIG_SYS_BOOTM_LEN       0xA000000

#define CONFIG_DISPLAY_BOARDINFO_LATE  /* display board info (after reloc) */

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

#undef CONFIG_LDO_BYPASS_CHECK

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * SZ_1M)

/* #define CONFIG_BOARD_LATE_INIT -- redefined */
/* #define CONFIG_MXC_GPIO -- redefined */

#define CONFIG_MXC_UART_BASE		UART1_BASE

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200

/* Command definition */
#undef CONFIG_CMD_IMLS

/* #define CONFIG_CMD_BMODE -- redefined */

#define CONFIG_SYS_MEMTEST_START	0x10000000
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + 500 * SZ_1M)
#define CONFIG_LOADADDR			0x12000000
#define CONFIG_SYS_TEXT_BASE		0x17800000

/* I2C Configs */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_MXC_I2C1         /* enable I2C bus 1 */
#define CONFIG_SYS_I2C_MXC_I2C2         /* enable I2C bus 2 */
#define CONFIG_SYS_I2C_MXC_I2C3         /* enable I2C bus 3 */
#define CONFIG_SYS_I2C_SPEED		100000

/* PMIC */
#define CONFIG_POWER
#define CONFIG_POWER_I2C
#define CONFIG_POWER_PFUZE100
#define CONFIG_POWER_PFUZE100_I2C_ADDR	0x08

/* MMC Configuration */
#define CONFIG_SYS_FSL_USDHC_NUM	2
#define CONFIG_SYS_FSL_ESDHC_ADDR	0

/* USB Configs */
/* #define CONFIG_USB_EHCI -- not used */
/* #define CONFIG_USB_EHCI_MX6 -- redefined */
#define CONFIG_USB_MAX_CONTROLLER_COUNT	2
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS		0

/* Ethernet Configuration */
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_FEC_MXC_PHYADDR		1
#define CONFIG_PHYLIB
#define CONFIG_PHY_ATHEROS

/* Framebuffer */
#define CONFIG_VIDEO_IPUV3
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
/* #define CONFIG_IPUV3_CLK 260000000 -- not used, IPUV3_CLK_MX6Q is 26400000, IPUV3_CLK_MX6DL is 19800000 */
#define CONFIG_IMX_HDMI
#define CONFIG_IMX_VIDEO_SKIP

/* #define CONFIG_CMD_FUSE -- redefined */
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#if 1
#define CONFIG_EXTRA_ENV_SETTINGS \
	"SRK0=0x00000000\0" \
	"SRK1=0x00000000\0" \
	"SRK2=0x00000000\0" \
	"SRK3=0x00000000\0" \
	"SRK4=0x00000000\0" \
	"SRK5=0x00000000\0" \
	"SRK6=0x00000000\0" \
	"SRK7=0x00000000\0" \
	"fuse_program=fuse prog 3 0 $SRK0; " \
                     "fuse prog 3 1 $SRK1; " \
                     "fuse prog 3 2 $SRK2; " \
                     "fuse prog 3 3 $SRK3; " \
                     "fuse prog 3 4 $SRK4; " \
                     "fuse prog 3 5 $SRK5; " \
                     "fuse prog 3 6 $SRK6; " \
                     "fuse prog 3 7 $SRK7\0" \
	"fuse_secure=fuse prog 0 0 0x4000; " \
                    "fuse prog 0 6 0x8; " \
                    "fuse prog 0 6 0x100000; " \
                    "fuse prog 0 6 0xC00000; " \
                    "fuse prog 0 6 0x8000000; " \
                    "fuse prog 0 0 0xC\0" \
	"fuse_lock=fuse prog 0 6 0x2\0" \
	"program_mac_low=fuse prog 4 2 0x0\0" \
	"program_mac_high=fuse prog 4 3 0x0\0" \
	"fdtfile=undefined\0" \
	"fdt_high=0xffffffff\0" \
	"fdt_addr=0x18000000\0" \
	"console=ttymxc0,"__stringify(CONFIG_BAUDRATE)"\0" \
	"splashpos=m,m\0" \
	"ip_dyn=no\0" \
	"fdtfile=undefined\0" \
	"fdt_high=0xffffffff\0" \
	"fdt_addr=0x18000000\0" \
	"fdt_addr_r=0x18000000\0" \
	"ramdisk_addr_r=0x18000000\0" \
	"kernel_addr_r="__stringify(CONFIG_LOADADDR)"\0" \
	"pxefile_addr_r="__stringify(CONFIG_LOADADDR)"\0" \
	"scriptaddr="__stringify(CONFIG_LOADADDR)"\0" \
	"initrd_high=0xffffffff\0" \
	"initrd_addr==0x18000000\0" \
	"bootenv=uEnv.txt\0" \
	"boot_fdt=try\0" \
	"rescuefile=tnrescue.itb\0" \
	"fit_addr=0x21100000\0" \
	"mmcroot=/dev/mmcblk0p2 rw\0" \
	"mmcargs=setenv bootargs console=${console} " \
		"root=${mmcroot}\0" \
	"loadbootscript=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source\0" \
	"loadimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${image}\0" \
	"loadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootz; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootz; " \
		"fi;\0" \
	BOOTENV

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND \
	   "mmc dev ${mmcdev}; if mmc rescan; then " \
		   "if run loadimage; then " \
			   "run mmcboot; " \
		   "fi; " \
	   "fi"
#else
#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=ttymxc0,"__stringify(CONFIG_BAUDRATE)"\0" \
	"splashpos=m,m\0" \
	"ip_dyn=no\0" \
	"fdtfile=undefined\0" \
	"fdt_high=0xffffffff\0" \
	"fdt_addr=0x18000000\0" \
	"fdt_addr_r=0x18000000\0" \
	"ramdisk_addr_r=0x18000000\0" \
	"kernel_addr_r="__stringify(CONFIG_LOADADDR)"\0" \
	"pxefile_addr_r="__stringify(CONFIG_LOADADDR)"\0" \
	"scriptaddr="__stringify(CONFIG_LOADADDR)"\0" \
	"initrd_high=0xffffffff\0" \
	"initrd_addr==0x18000000\0" \
	"bootenv=uEnv.txt\0" \
	"rescuefile=tnrescue.itb\0" \
	"fit_addr=0x21100000\0" \
	BOOTENV

#endif

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(MMC, mmc, 1) \
	func(DHCP, dhcp, na)

#include <config_distro_bootcmd.h>

/* Miscellaneous configurable options */
/* #define CONFIG_SYS_LONGHELP -- redefined */
/* #define CONFIG_AUTO_COMPLETE -- redefined */
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR

/* #define CONFIG_CMDLINE_EDITING -- redefined */

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

#define CONFIG_ENV_SIZE			0x3000 /* 12,288 bytes (24 sectors) */
#define CONFIG_ENV_OFFSET		(8 * SZ_64K) /* at 512KB (sector 1024) address */
#define CONFIG_SYS_MMC_ENV_DEV		0

#if defined(CONFIG_ANDROID_SUPPORT)
#include "pico-imx6_android_common.h"
#else
#define CONFIG_USBD_HS
#endif /* CONFIG_ANDROID_SUPPORT */

#endif  /* __PICO_IMX6_CONFIG_H */
