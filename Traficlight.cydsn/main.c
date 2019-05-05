/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
//#include <math.h>
//#include<stdio.h>

#define ON  1
#define OFF 0

#define RED_Duration 8
#define GREEN_DURATION 4
#define AMBER_DURATION 2

enum {RED, WAIT_FOR_RED_COMPLETE, AMBER,WAIT_FOR_AMBER_COMPLETE, GREEN, WAIT_FOR_GREEN_COMPLETE };
uint8 TimeInState;
uint8 CurrentState;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    CurrentState = RED ;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  LED_UpdateTimer_Start();
  LED_UpdateISR_Start();

    for(;;)
    {
        /* Place your application code here. */
        switch(CurrentState){
            case RED:{
                Red_LED_Write(ON);
                Green_LED_Write(OFF);
                
                CurrentState = WAIT_FOR_RED_COMPLETE;
                break;
            }
            case WAIT_FOR_RED_COMPLETE:{
                if(TimeInState == RED_Duration){
                    TimeInState =0;
                    CurrentState = AMBER;
                }
                break;
            }
            case AMBER:{
                Red_LED_Write(ON);
                Green_LED_Write(ON);
                CurrentState = WAIT_FOR_AMBER_COMPLETE;
                break;
            }
            case WAIT_FOR_AMBER_COMPLETE:{
                if(TimeInState == AMBER_DURATION){
                    TimeInState =0;
                    CurrentState = GREEN;
                }
                break;
            }
            case GREEN:{
                Red_LED_Write(OFF);
                Green_LED_Write(ON);
                CurrentState = WAIT_FOR_GREEN_COMPLETE;
                break;
            }
            case WAIT_FOR_GREEN_COMPLETE:{
              if(TimeInState == GREEN_DURATION){
                    TimeInState =0;
                    CurrentState = RED;
                }
                break;
            }
        }
    }
}

/* [] END OF FILE */
