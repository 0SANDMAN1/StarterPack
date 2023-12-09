/*
* LCD Calculator.c
*
* Created: 01-Nov-23 8:51:12 PM
* Author : Eslam Ehab
*/

#include "STD_Types.h"
#include "DIO.h"
#include "LCD.h"
#include "Keypad.h"
#define NOTPRESSED 0

void LCD_NumberToString(u32 data);

int main(void)
{
	/* Replace with your application code */
	DIO_Init();
	Keypad_Init();
	LCD_Init();
	label:	LCD_Init();
	Keypad_Init();
	u8 arr[6]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED} ;
	u8 res ;
	u8 counter=0 ;
	while(1)
	{
		do
		{
			arr[counter]=GetKey();
			
		} while(arr[counter]==NOTPRESSED);
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_Clear();
			goto label ;
		}
		else
		{
			LCD_Char(arr[counter]);
		}
		counter++;
		_delay_ms(20);
		do
		{
			arr[counter]=GetKey();
			
		}while(arr[counter]==NOTPRESSED);
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_Clear();
			goto label ;
		}
		else
		{
			LCD_Char(arr[counter]);
		}
		counter++;
		_delay_ms(20);
		
		do
		{
			arr[counter]=GetKey();
			
		}while(arr[counter]==NOTPRESSED);
		
		if(arr[counter]=='A'||arr[counter]=='=')
		{
			LCD_Clear();
			goto label ;
		}
		else
		{
			LCD_Char(arr[counter]);
		}
		counter++;
		_delay_ms(20);
		do
		{
			arr[counter]=GetKey();
			
		}while(arr[counter]==NOTPRESSED);
		
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_Clear();
			goto label ;
		}
		else
		{
			LCD_Char(arr[counter]);
		}
		counter++;
		_delay_ms(20);
		do
		{
			arr[counter]=GetKey();
			
		}while(arr[counter]==NOTPRESSED);
		
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_Clear();
			goto label ;
		}
		else
		{
			LCD_Char(arr[counter]);
		}
		counter++;
		_delay_ms(20);
		
		
		do
		{
			arr[counter]=GetKey();
			
		}while(arr[counter]==NOTPRESSED);
		
		if(arr[counter]=='=')
		{
			LCD_Char(arr[counter]);
			
			
			switch(arr[counter-3])
			{
				case '+':
				res=(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
				if(res>=100&&res<1000)
				{
					LCD_Char((res/100)+48);
					LCD_Char(((res/10)%10)+48);
					LCD_Char((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_Char((res/10)+48);
					LCD_Char((res%10)+48);
				}
				else if(res<10)
				{
					LCD_Char(res+48);
				}
				break;
				case '-' :
				res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(res>=100&&res<1000)
				{
					LCD_Char((res/100)+48);
					LCD_Char(((res/10)%10)+48);
					LCD_Char((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_Char((res/10)+48);
					LCD_Char((res%10)+48);
				}
				else if(res<10)
				{
					LCD_Char(res+48);
				}
				break;
				case '*':
				res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(res>=1000&&res<10000)
				{
					LCD_Char((res/1000)+48);
					LCD_Char(((res/100)%10)+48);
					LCD_Char(((res/10)%10)+48);
					LCD_Char((res%10)+48);
					
				}
				else if(res>=100&&res<1000)
				{
					LCD_Char((res/100)+48);
					LCD_Char(((res/10)%10)+48);
					LCD_Char((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_Char((res/10)+48);
					LCD_Char((res%10)+48);
				}
				else if(res<10)
				{
					LCD_Char(res+48);
				}
				break;
				case '/':
				res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(res>=100&&res<1000)
				{
					LCD_Char((res/100)+48);
					LCD_Char(((res/10)%10)+48);
					LCD_Char((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_Char((res/10)+48);
					LCD_Char((res%10)+48);
				}
				else if(res<10)
				{
					LCD_Char(res+48);
				}
				break;
				default : break;
				
			}
		}
		else
		{
			LCD_Clear();
			goto label ;
		}
		_delay_ms(20);
	}
}

