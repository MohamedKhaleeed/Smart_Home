#include"Login.h"
#include"std_types.h"
#include"LCD.h"
#include"Keypad.h"
#include"Calculator.h"
#include<util/delay.h>
u8 login (void)
{
	LCD_Init();
	Keypad_Init();
	u8 user,counter=0;
	u8 button;
	u32 password=0;
	LCD_DisplayString("select user");

    do
    {
    	user = Keypad_GetPressedButton();

    }while(user == KEYPAD_BUTTON_INVALID);

    user = Calculator_GetRealNumber(user);
    LCD_Clear();
    LCD_DisplayNumber(user);
    _delay_ms(500);

	if (user == User1)

	{
				LCD_Clear();
				LCD_DisplayString("Enter User1 Password: ");

				for(u8 i=0 ; i<4 ; i++)
				{
				       do
					{
					       button = Keypad_GetPressedButton();

			    	}while(button == KEYPAD_BUTTON_INVALID);

				      if(i==0)
				      {
				    	LCD_Clear();
				      }

				    password = (password*10)+Calculator_GetRealNumber(button);
				    LCD_Clear();
				    LCD_DisplayNumber(password);
				}

				if (password == User1_password)
				{

					LCD_Clear();
				    LCD_DisplayString("Welcome User1");
				    return 'Y';
				}

				else if(password!=User1_password)
				{
					LCD_Clear();
					LCD_DisplayString("Wrong Password ");
					counter++;


					do
					{
						password = 0 ;
						LCD_DisplayString("Enter Correct Password: ");
						for(u8 i=0 ; i<4 ; i++)
							{
							  do
								{
								  button = Keypad_GetPressedButton();
								}while(button == KEYPAD_BUTTON_INVALID);

								 if(i==0)
								  {
									 LCD_Clear();
								  }

							password = (password*10)+Calculator_GetRealNumber(button);
							LCD_Clear();
							LCD_DisplayNumber(password);
							}

						if (password==User1_password)
				        {
							LCD_Clear();
							LCD_DisplayString("Welcome User1");
							return'Y';

				        }

						else if(password!=User1_password)
				        {
							LCD_Clear();
							LCD_DisplayString("Wrong Password ");
							counter++;
				        }

				    }while(counter<3);


				    if (counter==3)
				    {
				    	LCD_Clear();
				    	LCD_DisplayString("you use 3 trails");
				    	LCD_SetCursorPosition(1, 0);
				    	LCD_DisplayString("system closed");
				    	return 'N';
				    }
				}
			}

	else if(user == User2)
	{
		LCD_Clear();
						LCD_DisplayString("Enter User1 Password: ");

						for(u8 i=0 ; i<4 ; i++)
						{
						       do
							{
							       button = Keypad_GetPressedButton();

					    	}while(button == KEYPAD_BUTTON_INVALID);

						      if(i==0)
						      {
						    	LCD_Clear();
						      }

						    password = (password*10)+Calculator_GetRealNumber(button);
						    LCD_Clear();
						    LCD_DisplayNumber(password);
						}

						if (password == User2_password)
						{

							LCD_Clear();
						    LCD_DisplayString("Welcome User2");
						    return'Y';
						}

						else if(password!=User2_password)
						{
							LCD_Clear();
							LCD_DisplayString("Wrong Password ");
							counter++;


							do
							{
								password = 0 ;
								LCD_DisplayString("Enter Correct Password: ");
								for(u8 i=0 ; i<4 ; i++)
									{
									  do
										{
										  button = Keypad_GetPressedButton();
										}while(button == KEYPAD_BUTTON_INVALID);

										 if(i==0)
										  {
											 LCD_Clear();
										  }

									password = (password*10)+Calculator_GetRealNumber(button);
									LCD_Clear();
									LCD_DisplayNumber(password);
									}

								if (password==User2_password)
						        {
									LCD_Clear();
									LCD_DisplayString("Welcome User2");
						        	return'Y';
						        }

								else if(password!=User2_password)
						        {
									LCD_Clear();
									LCD_DisplayString("Wrong Password ");
									counter++;
						        }

						    }while(counter<3);


						    if (counter==3)
						    {
						    	LCD_Clear();
						    	LCD_DisplayString("you use 3 trails");
						    	LCD_SetCursorPosition(1, 0);
						    	LCD_DisplayString("system closed");
						    	return 'N';
						    }
						}
					}
              return 0;
}
