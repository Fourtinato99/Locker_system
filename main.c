/*
 * locker_system.c
 *
 * Created: 8/25/2022 4:44:46 PM
 * Author : effic
 */

#include "STD_MACROS.h"
#include "LCD.h"
#include "EEPROM.h"
#include "KEYPAD_2.h"
#include "BUZZER_ACTIVE.h"



int main(void)
{


    //******************************************************
    //initiate LCD on port B pins 0->5 more detail in LCD.h
    LCD_init_4();
    LCD_write_command(0x80);
    LCD_write_command(0x0f);
    //*****************************************************




    //password in EEPROM

    /******************************************************
    the password will be stored in the EEPROM in location 10 ,11,12,13

    first , we check if these location contain 255 which means that is the first time and

    we will reset the value to 0 0 0 0 else we store the password in array (password array)

    */

    //EEPROM_write_8(10, '0');
   // EEPROM_write_8(11, '0');
    ///EEPROM_write_8(12, '0');
   /// EEPROM_write_8(13, '0');
	
    uint8 password[4];
    password[0] = EEPROM_read_8(10);
    password[1] = EEPROM_read_8(11);
    password[2] = EEPROM_read_8(12);
    password[3] = EEPROM_read_8(13);


    if (password[0] == 255 && password[1] && password[2] && password[3]) {
        EEPROM_write_8(10, '0');
        EEPROM_write_8(11, '0');
        EEPROM_write_8(12, '0');
        EEPROM_write_8(13, '0');
    }


    //******************************************************************************


    //******************************************************************************
    //initiate  keypad
    // keypad_char  :: variable stores the return value from KEYPAD_read() function


    KEYPAD_init();
    uint8 keypad_char;
    //******************************************************************************





    //******************************************************************************
    //init buzzer

    BUZZER_init();
    BUZZER_run_1();






    //************************************************
    //some variable used to manage 
    uint8 enter_pass_mode = 1;
    uint8 change_pass_mode = 0;
    uint8 next_num = 0;
    uint8 temp_pass[4] = {'0' ,'0' , '0' ,'0'};
		
    LCD_write_command(0x80);
    LCD_write_string("enter the password");
    LCD_write_command(0xc0);


	/* my program work with two mode 
	
	 1-first mode is normal mode or wait the user enter the password
	 2-second mode is change password mode 
	 
	 controlling these mode using two variable 
	   1-enter_pass_mode 
	   2-change_pass_mode
	   
	  */
    while (1)
    {


        keypad_char = KEYPAD_read();



        if (keypad_char != 0)
        {
			BUZZER_run_1();
			
			//
			
			if(keypad_char == '*') //close the locker
			{
				enter_pass_mode = 1;
				change_pass_mode = 0;
				next_num = 0;
				
				LCD_clear();
				LCD_write_command(0x80);
				LCD_write_string("locker closed");
				_delay_ms(200);
				LCD_clear();
				LCD_write_command(0x80);
				LCD_write_string("enter the password");
				LCD_write_command(0xc0);
				
				
			}


            //*******************************************************************************************************************
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
            // enter password mode 
			
            else if (enter_pass_mode && keypad_char != '/') //enter the "enter password mode"
            {
                if (next_num < 4)
                {
                    LCD_write_chararcter('*');
                    temp_pass[next_num++] = keypad_char;
                }

                if (next_num == 4) // after entering all characters checking correct password
                {
					password[0] = EEPROM_read_8(10);
					password[1] = EEPROM_read_8(11);
					password[2] = EEPROM_read_8(12);
					password[3] = EEPROM_read_8(13);
					
                    if (*(uint32*)password == *(uint32*)temp_pass)
                    {
                        LCD_clear();
                        LCD_write_command(0x80);
                        LCD_write_string("locker opened");
						
						enter_pass_mode = 0;
						change_pass_mode = 0;
						


                    }
                    else
                    {
                        LCD_clear();
                        LCD_write_command(0x80);
                        LCD_write_string("Try again");
						
						_delay_ms(220);
						
						 next_num = 0;
						 
						 LCD_clear();
						 LCD_write_command(0x80);
						 LCD_write_string("enter the password");
						 LCD_write_command(0xc0);


                    }
					
                    

                }
            }
			
			
			
			
			
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			
			// change password mode

            else if (change_pass_mode && keypad_char != '/')
            {
                if (next_num < 4) //enter the character by character until enter all password 
                {
                    temp_pass[next_num++] = keypad_char;
                    LCD_write_chararcter(keypad_char);
                    
                }

            }
			
			//////////////////////////////////////////////////////////////////////////



            else if (keypad_char == '/' && change_pass_mode )	 // second "/" to save the new password and set  the controller variable to start 
            {												// the enter password mode
                
            
            //1-save password 

                EEPROM_write_8(10, temp_pass[0]);
                EEPROM_write_8(11, temp_pass[1]);
                EEPROM_write_8(12, temp_pass[2]);
                EEPROM_write_8(13, temp_pass[3]);

                //2-display password changed successfully
                LCD_write_command(0x80);
                LCD_write_string("password changed");
                LCD_write_command(0xc0);
                LCD_write_string("successfully");

                //3-run the buzzer for 300ms
                BUZZER_run_3();
                _delay_ms(200);


                //4-reset contoller variables to enter password mode
                enter_pass_mode = 1;
                change_pass_mode = 0;
                next_num = 0;
				LCD_clear();

                LCD_write_command(0x80);
                LCD_write_string("enter the password");
                LCD_write_command(0xc0);

            }
            
			//////////////////////////////////////////////////////////////////////////
			
            else if (keypad_char == '/')  // first  "/" to start change password mode 
            {
                //

                //1-display that we want to change the password

                LCD_write_command(0x80);
                LCD_write_string("change password");
                LCD_write_command(0xc0);
				BUZZER_run_3();

                //2-set the variable to enter the change password mode
                enter_pass_mode = 0;
                change_pass_mode = 1;
                next_num = 0;
            }
			//////////////////////////////////////////////////////////////////////////



        }  //end of if condition (keypad_char != '/')






    }
}







