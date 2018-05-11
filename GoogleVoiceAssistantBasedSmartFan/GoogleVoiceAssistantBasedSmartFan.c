/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : GoogleVoiceAssistantBasedSmartFan
//
//  Target Board : atmega32
//
//  Date Created : 10-May-18 11:56:40 AM
//
//  Libraries Included : -->wifiadvanced 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<avr/io.h>
#include<util/delay.h>
#include"setup.h"
#include "SmartFansetup.h"
#include "serial.h"
#include "clobous.h"
#include "DS18B20.h"
#include "lcd.h"

int main()
{
	complete_setup();
	wifi_connect("asus","asus1234");
    lcd_string("wifi cntd");
	_delay_ms(1000);
	ds18b_init(porta,0);
	int a;
	while (1)
	{
	
	    
		data_retrieve("vr",data);
		lcd_clear();
		lcd_string(data);
		if(compare(data,"manual"))
		{
			while(1)
			{
				data_retrieve("vr",data);
				lcd_clear();
				lcd_string(data);
				if(compare(data,"auto"))
				{
					break;
				}
				if(compare(data,"slow")||compare(data,"fan_on"))
				{
					
					slow();
				}	
			
			
				if(compare(data,"medium"))
				{
					
					medium();
				}
			
				if(compare(data,"fast"))
				{
					
					fast();
				}
				
			
				if(compare(data,"fan_off"))
				{
					
					fan_off();
				}
				
			}
			wifi_connect("asus","asus1234");
			 fan_off();
			return 0;
		}
		
		
		
		
		if(compare(data,"auto"))
		{
			while(1)
			{
				data_retrieve("vr",data);
				lcd_clear();
				lcd_string(data);
				if(compare(data,"manual"))
				{
					break;
				}
				lcd_clear();
				a=read_temp();
				lcd_string("temp=");
				lcd_gotoxy(5,0);
				lcd_num(a);
				lcd_string("*");
				_delay_ms(200);
				if(a<27)
				{
						 fan_off();
				}
				
				if((a>=27)&&(a<28))
				{
						slow();
				}
			
				if((a>=29)&&(a<30))
				{
						medium();
				}
				if(a>=30)
				{
						 fast();
				}
	
				}
				
			 fan_off();	
			 wifi_connect("asus","asus1234");
			return 0;
		}
		
	}	

}