/**
  ******************************************************************************
  * @file    simulate_spi.c
  * @author  Iam670
  * @version V0.0.1
  * @date    2016-10-15
  * @brief   模拟SPI程序
  *          等效于 SPI_FirstBit_MSB SPI_CPOL_Low SPI_CPHA_1Edge       
  *          
  *           
  */  
/*clk*/
#define set_clk_pin_output()
/*miso*/
#define set_miso_pin_input()
/*mosi*/
#define set_mosi_pin_output()
/*cs*/
#define set_cs_pin_output()

#define write_gpio_high()  
#define write_gpio_low()
#define write_clk_high()
#define write_clk_low()

#define cs_high()
#define cs_low()

#define read_gpio()

#define udelay(x)   

#define _SPI_DELAY_TIME_US_ 1

/**/
void simulate_spi_init(void)
{
	/*clk*/
	set_clk_pin_output();
	/*miso*/
	set_miso_pin_input();
	/*mosi*/
	set_mosi_pin_output();
	/*cs*/
	set_cs_pin_output();
}

/**/
void simulate_spi_write_byte(unsigned char tx_data)
{
	int i = 0;
	for(i = 7;i >= 0;i--)
	{		
		if(tx_data & (1 << i))
		{
			write_gpio_high();
		}
		else
		{
			write_gpio_low();
		}

		write_clk_high();
		udelay(_SPI_DELAY_TIME_US_);
		write_clk_low();
		udelay(_SPI_DELAY_TIME_US_);		
	}
}


/**/
unsigned char simulate_spi_read_byte(void)
{
	int i = 0;
	unsigned char rx_data = 0;
	int gpio_read = 0;
	for(i = 7;i >= 0;i--)
	{
		gpio_read = read_gpio();
		
		if(gpio_read)
		{
			rx_data |= (1<<i);
		}
		write_clk_high();
		udelay(_SPI_DELAY_TIME_US_);
		
		write_clk_low();
		udelay(_SPI_DELAY_TIME_US_);		
	}
	
	return rx_data;
}

