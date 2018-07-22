#ifndef __LCD_H__
#define __LCD_H__

#include "stm32f4xx_hal.h"


void init_lcd_port(void);
void init_lcd(SPI_HandleTypeDef* spi);

void lcd_reset(void);
void write_command(SPI_HandleTypeDef* spi, uint8_t);
void write_data(SPI_HandleTypeDef* spi, uint8_t);

void lcd_debug_colors(SPI_HandleTypeDef* spi);

// Define lcd control pins
#define LCD_PORT GPIOC
#define LCD_CS	GPIO_PIN_0
#define LCD_RST	GPIO_PIN_1
#define LCD_A0	GPIO_PIN_2

#define LCD_BLUE 0xF800
#define LCD_RED 0x00F8
#define LCD_GREEN 0x03E0

// Define size
#define ILI9163_HEIGHT 						128
#define ILI9163_WIDTH 						128

// ILI9163 LCD Controller Commands
#define LCD_CMD_NOP                     0x00
#define LCD_CMD_SOFT_RESET              0x01
#define LCD_CMD_GET_RED_CHANNEL         0x06
#define LCD_CMD_GET_GREEN_CHANNEL       0x07
#define LCD_CMD_GET_BLUE_CHANNEL        0x08
#define LCD_CMD_GET_PIXEL_FORMAT        0x0C
#define LCD_CMD_GET_POWER_MODE          0x0A
#define LCD_CMD_GET_ADDRESS_MODE        0x0B
#define LCD_CMD_GET_DISPLAY_MODE        0x0D
#define LCD_CMD_GET_SIGNAL_MODE         0x0E
#define LCD_CMD_GET_DIAGNOSTIC_RESULT   0x0F
#define LCD_CMD_ENTER_SLEEP_MODE        0x10
#define LCD_CMD_EXIT_SLEEP_MODE         0x11
#define LCD_CMD_ENTER_PARTIAL_MODE      0x12
#define LCD_CMD_ENTER_NORMAL_MODE       0x13
#define LCD_CMD_EXIT_INVERT_MODE        0x20
#define LCD_CMD_ENTER_INVERT_MODE       0x21
#define LCD_CMD_SET_GAMMA_CURVE         0x26
#define LCD_CMD_SET_DISPLAY_OFF         0x28
#define LCD_CMD_SET_DISPLAY_ON          0x29
#define LCD_CMD_SET_COLUMN_ADDRESS      0x2A
#define LCD_CMD_SET_PAGE_ADDRESS        0x2B
#define LCD_CMD_WRITE_MEMORY_START      0x2C
#define LCD_CMD_WRITE_LUT               0x2D
#define LCD_CMD_READ_MEMORY_START       0x2E
#define LCD_CMD_SET_PARTIAL_AREA        0x30
#define LCD_CMD_SET_SCROLL_AREA         0x33
#define LCD_CMD_SET_TEAR_OFF            0x34
#define LCD_CMD_SET_TEAR_ON             0x35
#define LCD_CMD_SET_ADDRESS_MODE        0x36
#define LCD_CMD_SET_SCROLL_START        0X37
#define LCD_CMD_EXIT_IDLE_MODE          0x38
#define LCD_CMD_ENTER_IDLE_MODE         0x39
#define LCD_CMD_SET_PIXEL_FORMAT        0x3A
#define LCD_CMD_WRITE_MEMORY_CONTINUE   0x3C
#define LCD_CMD_READ_MEMORY_CONTINUE    0x3E
#define LCD_CMD_SET_TEAR_SCANLINE       0x44
#define LCD_CMD_GET_SCANLINE            0x45
#define LCD_CMD_READ_ID1                0xDA
#define LCD_CMD_READ_ID2                0xDB
#define LCD_CMD_READ_ID3                0xDC
#define LCD_CMD_FRAME_RATE_CONTROL1     0xB1
#define LCD_CMD_FRAME_RATE_CONTROL2     0xB2
#define LCD_CMD_FRAME_RATE_CONTROL3     0xB3
#define LCD_CMD_DISPLAY_INVERSION       0xB4
#define LCD_CMD_SOURCE_DRIVER_DIRECTION 0xB7
#define LCD_CMD_GATE_DRIVER_DIRECTION   0xB8
#define LCD_CMD_POWER_CONTROL1          0xC0
#define LCD_CMD_POWER_CONTROL2          0xC1
#define LCD_CMD_POWER_CONTROL3          0xC2
#define LCD_CMD_POWER_CONTROL4          0xC3
#define LCD_CMD_POWER_CONTROL5          0xC4
#define LCD_CMD_VCOM_CONTROL1           0xC5
#define LCD_CMD_VCOM_CONTROL2           0xC6
#define LCD_CMD_VCOM_OFFSET_CONTROL     0xC7
#define LCD_CMD_WRITE_ID4_VALUE         0xD3
#define LCD_CMD_NV_MEMORY_FUNCTION1     0xD7
#define LCD_CMD_NV_MEMORY_FUNCTION2     0xDE
#define LCD_CMD_POSITIVE_GAMMA_CORRECT  0xE0
#define LCD_CMD_NEGATIVE_GAMMA_CORRECT  0xE1
#define LCD_CMD_GAM_R_SEL               0xF2

#endif
