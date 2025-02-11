/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2022 Intel Corporation */

#ifndef TI960_REG_H
#define TI960_REG_H

struct ti960_register_write {
	u8 reg;
	u8 val;
};

struct ti960_register_devid {
	u8 reg;
	u8 val_expected;
};

static const struct ti960_register_write ti960_frame_sync_settings[2][5] = {
	{
		{0x18, 0x00}, /* Disable frame sync. */
		{0x19, 0x00},
		{0x1a, 0x00},
		{0x1b, 0x00},
		{0x1c, 0x00},
	},
	{
		{0x19, 0x15}, /* Frame sync high time.*/
		{0x1a, 0xb3},
		{0x1b, 0xc3}, /* Frame sync low time. */
		{0x1c, 0x4f},
		{0x18, 0x01}, /* Enable frame sync. and use high/low mode */
	}
};

static const struct ti960_register_write ti960_gpio_settings[] = {
	{0x10, 0x81},
	{0x11, 0x85},
	{0x12, 0x89},
	{0x13, 0x8d},
};

static const struct ti960_register_write ti960_init_settings[] = {
	{0x0c, 0x0f}, /* RX_PORT_CTL */
	{0x1f, 0x06}, /* CSI_PLL_CTL */
	{0x4c, 0x01}, /* FPD3_PORT_SEL */
	{0x58, 0x5e}, /* BCC_CONFIG */
	{0x5c, 0xb0}, /* SER_ALIAS_ID */
	{0x5d, 0x6c}, /* SlaveID[0] */
	{0x65, 0x60}, /* SlaveAlias[0] */
	{0x6d, 0x7c}, /* PORT_CONFIG */
	{0x7c, 0x01}, /* PORT_CONFIG2 */
	{0x70, 0x2b}, /* RAW10_ID */
	{0x71, 0x2c}, /* RAW12_ID */
	{0x72, 0xe4}, /* CSI_VC_MAP */
	{0x4c, 0x12}, /* FPD3_PORT_SEL */
	{0x58, 0x5e},
	{0x5c, 0xb2},
	{0x5d, 0x6c},
	{0x65, 0x62},
	{0x6d, 0x7c},
	{0x7c, 0x01},
	{0x70, 0x2b},
	{0x71, 0x2c},
	{0x72, 0xee}, /* CSI_VC_MAP */
	{0x4c, 0x24}, /* FPD3_PORT_SEL */
	{0x58, 0x5e},
	{0x5c, 0xb4},
	{0x5d, 0x6c},
	{0x65, 0x64},
	{0x6d, 0x7c},
	{0x7c, 0x01},
	{0x70, 0x2b},
	{0x71, 0x2c},
	{0x72, 0xe4},
	{0x4c, 0x38}, /* FPD3_PORT_SEL */
	{0x58, 0x5e},
	{0x5c, 0xb6},
	{0x5d, 0x6c},
	{0x65, 0x66},
	{0x6d, 0x7c},
	{0x7c, 0x01},
	{0x70, 0x2b},
	{0x71, 0x2c},
	{0x72, 0xe4},
	{0xb0, 0x14}, /* FPD3 RX Shared Reg */
	{0xb1, 0x03},
	{0xb2, 0x04},
	{0xb1, 0x04},
	{0xb2, 0x04},
	{0x32, 0x12}, /* select TX1 R/W */
	{0x33, 0x03}, /* CSI_ENABLE, CONTS_CLOCK */
	{0x34, 0x08}, /* CSI_PASS_MODE all */
	{0x32, 0x01}, /* select TX0 R/W */
	{0x33, 0x03}, /* CSI_ENABLE, CONTS_CLOCK */
	{0x34, 0x08}, /* CSI_PASS_MODE all */
	{0x20, 0xf0},
	{0x21, 0x03},
};

/* register definition */
#define TI960_DEVID		0x0
#define TI960_RESET		0x1
#define TI960_CSI_PLL_CTL	0x1f
#define TI960_FS_CTL		0x18
#define TI960_FWD_CTL1		0x20
#define TI960_RX_PORT_SEL	0x4c
#define TI960_SER_ALIAS_ID	0x5c
#define TI960_SLAVE_ID0		0x5d
#define TI960_SLAVE_ALIAS_ID0	0x65
#define TI960_PORT_CONFIG	0x6d
#define TI960_BC_GPIO_CTL0	0x6e
#define TI960_BC_GPIO_CTL1	0x6f
#define TI960_RAW10_ID		0x70
#define TI960_RAW12_ID		0x71
#define TI960_CSI_VC_MAP	0x72
#define TI960_PORT_CONFIG2	0x7c
#define TI960_CSI_CTL		0x33
#define TI960_CSI_CTL2		0x34

/* register value definition */
#define TI960_POWER_ON		0x1
#define TI960_POWER_OFF		0x20
#define TI960_FPD3_RAW10_100MHz	0x7f
#define TI960_FPD3_RAW12_50MHz	0x7d
#define TI960_FPD3_RAW12_75MHz	0x7e
#define TI960_FPD3_CSI		0x7c
#define TI960_RAW12		0x41
#define TI960_RAW10_NORMAL	0x1
#define TI960_RAW10_8BIT	0x81
#define TI960_GPIO0_HIGH	0x09
#define TI960_GPIO0_LOW		0x08
#define TI960_GPIO1_HIGH	0x90
#define TI960_GPIO1_LOW		0x80
#define TI960_GPIO0_FSIN	0x0a
#define TI960_GPIO1_FSIN	0xa0
#define TI960_GPIO0_MASK	0x0f
#define TI960_GPIO1_MASK	0xf0
#define TI960_GPIO2_FSIN	0x0a
#define TI960_GPIO3_FSIN	0xa0
#define TI960_GPIO2_MASK	0x0f
#define TI960_GPIO3_MASK	0xf0
#define TI960_MIPI_400MBPS	0x3
#define TI960_MIPI_800MBPS	0x2
#define TI960_MIPI_1200MBPS	0x1
#define TI960_MIPI_1600MBPS	0x0
#define TI960_CSI_ENABLE	0x1
#define TI960_CSI_CONTS_CLOCK	0x2
#define TI960_CSI_SKEWCAL	0x40
#define TI960_FSIN_ENABLE	0x1

#endif
