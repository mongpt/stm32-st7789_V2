/**
 ******************************************************************************
 * @file           : st7789_config.h
 * @brief          : ST7789 library configuration
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 Lars Boegild Thomsen <lbthomsen@gmail.com>
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 * Copy this template to another folder and rename it to st7789_config.h
 *
 ******************************************************************************
 */

#ifndef INC_ST7789_CONFIG_H_
#define INC_ST7789_CONFIG_H_

/* choose a Hardware SPI port to use. */
#define ST7789_SPI_PORT hspi1

/* choose whether use DMA or not */
#define USE_DMA 1

/*
 * DMA line-buffer ("slicer") — RAM vs speed
 * -----------------------------------------
 * With USE_DMA, the driver uses a small uint16_t RAM buffer and sends the panel in
 * chunks. Set ST7789_USE_FB_SLICER to 1 and tune ST7789_DMA_STRIP_LINES (e.g. 5
 * => 240x5 pixels on a 240-wide panel) for low-RAM MCUs.
 *
 * Set ST7789_USE_FB_SLICER to 0 to use a single scanline buffer only (width x 1
 * pixels). Same minimum RAM, more SPI/DMA round-trips than a multi-line strip.
 *
 * (A full-screen buffer is not required for correctness; the old comment about
 * "avoid DMA if low RAM" meant: shrink the strip or disable USE_DMA — DMA does
 * not require a full framebuffer.)
 */
#ifndef ST7789_USE_FB_SLICER
#define ST7789_USE_FB_SLICER 1
#endif

#if ST7789_USE_FB_SLICER
#ifndef ST7789_DMA_STRIP_LINES
#define ST7789_DMA_STRIP_LINES 5
#endif
#if ST7789_DMA_STRIP_LINES < 1
#error ST7789_DMA_STRIP_LINES must be >= 1
#endif
#endif

/* If u need CS control, comment below*/
#define CFG_NO_CS
/* Pin connection*/
#define ST7789_RST_PORT TFT_RST_GPIO_Port
#define ST7789_RST_PIN  TFT_RST_Pin
#define ST7789_DC_PORT  TFT_DC_GPIO_Port
#define ST7789_DC_PIN   TFT_DC_Pin

#ifndef CFG_NO_CS
#define ST7789_CS_PORT  TFT_CS_GPIO_Port
#define ST7789_CS_PIN   TFT_CS_Pin
#endif

/* If u need Backlight control, uncomment below */
#define BLK_PORT TFT_BL_GPIO_Port
#define BLK_PIN  TFT_BL_Pin

#define USING_240X240
#define ST7789_ROTATION 1

#endif /* INC_ST7789_CONFIG_H_ */
