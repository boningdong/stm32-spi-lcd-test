#include "stm32f4xx_hal.h"
#include "lcd.h"


void init_lcd_port() 
{
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef config;
	config.Mode = GPIO_MODE_OUTPUT_PP;
	config.Pin = LCD_CS | LCD_RST | LCD_A0;
	config.Pull = GPIO_NOPULL;
	config.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(LCD_PORT, &config);
	
	HAL_GPIO_WritePin(LCD_PORT, LCD_CS, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_PORT, LCD_RST, GPIO_PIN_SET);
}

void init_lcd(SPI_HandleTypeDef* spi) 
{
	SPI_HandleTypeDef hspi1 = *spi;
	
	lcd_reset();
	write_command(&hspi1, LCD_CMD_EXIT_SLEEP_MODE);
	HAL_Delay(10);
	
	write_command(&hspi1, LCD_CMD_SET_PIXEL_FORMAT);
	write_data(&hspi1, 0x05);
	
	/*
	write_command(&hspi1, LCD_CMD_SET_GAMMA_CURVE);
	write_data(&hspi1, 0x01);
	
	write_command(&hspi1, LCD_CMD_GAM_R_SEL);
	write_data(&hspi1, 0x00);
	
	write_command(&hspi1, LCD_CMD_EXIT_INVERT_MODE);*/
	
	/*
	write_command(&hspi1, LCD_CMD_POSITIVE_GAMMA_CORRECT);
	write_data(&hspi1, 0x3f); // 1st Parameter
    write_data(&hspi1, 0x25); // 2nd Parameter
    write_data(&hspi1, 0x1c); // 3rd Parameter
    write_data(&hspi1, 0x1e); // 4th Parameter
    write_data(&hspi1, 0x20); // 5th Parameter
    write_data(&hspi1, 0x12); // 6th Parameter
    write_data(&hspi1, 0x2a); // 7th Parameter
    write_data(&hspi1, 0x90); // 8th Parameter
    write_data(&hspi1, 0x24); // 9th Parameter
    write_data(&hspi1, 0x11); // 10th Parameter
    write_data(&hspi1, 0x00); // 11th Parameter
    write_data(&hspi1, 0x00); // 12th Parameter
    write_data(&hspi1, 0x00); // 13th Parameter
    write_data(&hspi1, 0x00); // 14th Parameter
    write_data(&hspi1, 0x00); // 15th Parameter
	
	write_command(&hspi1, LCD_CMD_NEGATIVE_GAMMA_CORRECT);
    write_data(&hspi1, 0x20); // 1st Parameter
    write_data(&hspi1, 0x20); // 2nd Parameter
    write_data(&hspi1, 0x20); // 3rd Parameter
    write_data(&hspi1, 0x20); // 4th Parameter
    write_data(&hspi1, 0x05); // 5th Parameter
    write_data(&hspi1, 0x00); // 6th Parameter
    write_data(&hspi1, 0x15); // 7th Parameter
    write_data(&hspi1, 0xa7); // 8th Parameter
    write_data(&hspi1, 0x3d); // 9th Parameter
    write_data(&hspi1, 0x18); // 10th Parameter
    write_data(&hspi1, 0x25); // 11th Parameter
    write_data(&hspi1, 0x2a); // 12th Parameter
    write_data(&hspi1, 0x2b); // 13th Parameter
    write_data(&hspi1, 0x2b); // 14th Parameter
    write_data(&hspi1, 0x3a); // 15th Parameter*/
	
	
	write_command(&hspi1, LCD_CMD_FRAME_RATE_CONTROL1);
    write_data(&hspi1, 0x08); // DIVA = 8
    write_data(&hspi1, 0x08); // VPA = 8
    
    write_command(&hspi1, LCD_CMD_DISPLAY_INVERSION);
    write_data(&hspi1, 0x00); // NLA = 1, NLB = 1, NLC = 1 (all on Frame Inversion)
   
    write_command(&hspi1, LCD_CMD_SET_ADDRESS_MODE);
	write_data(&hspi1, (1<<5) | (1<<6));
   /*
    write_command(&hspi1, LCD_CMD_POWER_CONTROL1);
    write_data(&hspi1, 0x0a); // VRH = 10:  GVDD = 4.30
    write_data(&hspi1, 0x02); // VC = 2: VCI1 = 2.65
      
    write_command(&hspi1, LCD_CMD_POWER_CONTROL2);
    write_data(&hspi1, 0x02); // BT = 2: AVDD = 2xVCI1, VCL = -1xVCI1, VGH = 5xVCI1, VGL = -2xVCI1

    write_command(&hspi1,LCD_CMD_VCOM_CONTROL1);
    write_data(&hspi1, 0x50); // VMH = 80: VCOMH voltage = 4.5
    write_data(&hspi1, 0x5b); // VML = 91: VCOML voltage = -0.225
    
    write_command(&hspi1, LCD_CMD_VCOM_OFFSET_CONTROL);
    write_data(&hspi1, 0x40); // nVM = 0, VMF = 64: VCOMH output = VMH, VCOML output = VML*/

	write_command(&hspi1, LCD_CMD_SET_COLUMN_ADDRESS);
	write_data(&hspi1, 0x01); // XSH
	write_data(&hspi1, 0x01); // XSL
	write_data(&hspi1, 0x01); // XEH
	write_data(&hspi1, 0x80); // XEL (128 pixels x)
   
    write_command(&hspi1, LCD_CMD_SET_PAGE_ADDRESS);
    write_data(&hspi1, 0x01);
    write_data(&hspi1, 0x01);
    write_data(&hspi1, 0x01);
    write_data(&hspi1, 0x80); // 128 pixels y
	
	write_command(&hspi1, LCD_CMD_SET_DISPLAY_ON);
    write_command(&hspi1, LCD_CMD_WRITE_MEMORY_START);
	
}

void lcd_debug_colors(SPI_HandleTypeDef* spi) {
	
	for(int x = 0; x < 128; x++){
		for(int y = 0; y < 128; y++) {
			write_data(spi, (LCD_RED / 128));
			write_data(spi, (LCD_RED % 128));
		}
	}
	
	for(int x = 0; x < 128; x++){
		for(int y = 0; y < 128; y++) {
			write_data(spi, (LCD_GREEN / 128));
			write_data(spi, (LCD_GREEN % 128));
		}
	}
	
	for(int x = 0; x < 128; x++){
		for(int y = 0; y < 128; y++) {
			write_data(spi, (LCD_BLUE / 128));
			write_data(spi, (LCD_BLUE % 128));
		}
	}
}

void lcd_reset() {
	HAL_GPIO_WritePin(LCD_PORT, LCD_RST, GPIO_PIN_RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(LCD_PORT, LCD_RST, GPIO_PIN_SET);
	HAL_Delay(150);
}

void write_command(SPI_HandleTypeDef* spi, uint8_t data) {
	HAL_GPIO_WritePin(LCD_PORT, LCD_CS, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_PORT, LCD_A0, GPIO_PIN_RESET);
	HAL_SPI_Transmit(spi, &data, 1, 100);
	while(!((spi->Instance->SR) & SPI_SR_TXE));
	HAL_GPIO_WritePin(LCD_PORT, LCD_CS, GPIO_PIN_SET);
}

void write_data(SPI_HandleTypeDef* spi, uint8_t data) {
	HAL_GPIO_WritePin(LCD_PORT, LCD_CS, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_PORT, LCD_A0, GPIO_PIN_SET);
	HAL_SPI_Transmit(spi, &data, 1, 100);
	while(!((spi->Instance->SR) & SPI_SR_TXE));
	HAL_GPIO_WritePin(LCD_PORT, LCD_CS, GPIO_PIN_SET);
}

