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
#define ON  1
#define OFF 0

//void LCD_Print();
#define IDEAL_DURATION  03
#define GREEN_DURATION  10
#define AMBER_DURATION  02
//#define DURATION        25

enum {STATE_1,STATE_2, STATE_3,STATE_4, STATE_5, STATE_6,STATE_7,STATE_8, Ideal};
uint8 TimeInState;
//uint8 Ftimer ;
//uint8 Rtimer ;
//uint8 Dtimer ;
//uint8 Ltimer ;
//uint8 FtimerFlag = 2;
//uint8 RtimerFlag = 2;
//uint8 DtimerFlag = 2;
//uint8 LtimerFlag = 2;
uint8 CurrentState;
uint8 InitialCount=0;
uint8 directionflag = 0;

int main(void)
{
     
    CyGlobalIntEnable; /* Enable global interrupts. */

    CurrentState = STATE_1 ;
    InitialCount = 1;
   
    Front_Red_LED_Write(ON);
    Right_Red_LED_Write(ON);
    Red_LED_Write(ON); 
    Left_Red_LED_Write(ON);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  LED_UpdateTimer_Start();
  LED_UpdateISR_Start();
  //LCD_Start();

    for(;;)
    {
        /* Place your application code here. */
         switch(CurrentState){
            case STATE_1:{
                if(InitialCount){
                    
                    CyDelay(1000);
                    Front_Amber_LED_Write(ON);
                    Front_Red_LED_Write(OFF);   
                }
                 if(TimeInState == AMBER_DURATION){
                    TimeInState =0;
                    directionflag = 0;
                    
                    //FtimerFlag = 1; 
                    //Ftimer = GREEN_DURATION ;
                    Front_Green_LED_Write(ON);
                    Front_Amber_LED_Write(OFF);   
                    
                    CurrentState = STATE_2;                   
                }
                if(InitialCount == 0){
                    
                    Front_Red_LED_Write(OFF);   
                }

                break;
            }
            case STATE_2:{
                if(TimeInState == GREEN_DURATION){
                    TimeInState =0;
                    directionflag = 1;
                    CurrentState = Ideal;
                }
                
                break;
            }
            case STATE_3:{
                
                if(TimeInState == AMBER_DURATION){
                    TimeInState =0;
                    
                    //Rtimer = GREEN_DURATION ;
                    //RtimerFlag = 1;
                    Right_Green_LED_Write(ON);
                    Right_Amber_LED_Write(OFF);
                
                    CurrentState = STATE_4;
                }
                
                Right_Red_LED_Write(OFF);
               
                break;
            }
            case STATE_4:{
                if(TimeInState == GREEN_DURATION){
                    TimeInState =0;
             
                    directionflag = 2;
                    CurrentState = Ideal;
                }
               
                break;
            }
            case STATE_5:{
                 if(TimeInState == AMBER_DURATION){
                    TimeInState =0;
                    
                    //Dtimer = GREEN_DURATION ;
                    //DtimerFlag = 1;
                    Green_LED_Write(ON);
                    Amber_LED_Write(OFF);
                
                    CurrentState = STATE_6;
                }
                
                Red_LED_Write(OFF);
                
                break;
            }
            case STATE_6:{
              if(TimeInState == GREEN_DURATION){
                    TimeInState =0;
                    
                    directionflag = 3;
                    CurrentState = Ideal;
                }
      
                break;
            }
            case STATE_7:{
              if(TimeInState == AMBER_DURATION){
                    TimeInState =0;
                    
                    //Ltimer = GREEN_DURATION ;
                    //LtimerFlag = 1;
                    Left_Amber_LED_Write(OFF);
                    Left_Green_LED_Write(ON);

                    CurrentState = STATE_8;
                }
                
                Left_Red_LED_Write(OFF);

                break;
            }
            case STATE_8:{
              if(TimeInState == GREEN_DURATION){
                    TimeInState =0;
                    
                    InitialCount = 0;
                    directionflag = 4;                    
                    CurrentState = Ideal;
                }
            
                break;
            }
            case Ideal:{
                if(directionflag == 1){
                    
                    if(TimeInState == IDEAL_DURATION){
                        TimeInState =0;
                        directionflag = 0; 
                        Right_Amber_LED_Write(ON);
                        CurrentState = STATE_3;
                    }   
                    Front_Green_LED_Write(OFF);
                    Front_Red_LED_Write(ON);
                    //Ftimer = DURATION;  
                    //FtimerFlag = 2;
                }else if(directionflag == 2){
                    
                    if(TimeInState == IDEAL_DURATION){
                        TimeInState =0;
                        directionflag = 0;
                        Amber_LED_Write(ON);
                        CurrentState = STATE_5;
                    }  
                    Right_Green_LED_Write(OFF);
                    Right_Red_LED_Write(ON);
                    //Rtimer = DURATION;
                    //RtimerFlag = 2;
                }else if(directionflag == 3){
                    if(TimeInState == IDEAL_DURATION){
                        TimeInState =0;
                        directionflag = 0;
                        Left_Amber_LED_Write(ON);
                        CurrentState = STATE_7;
                    }  
                    Green_LED_Write(OFF);
                    Red_LED_Write(ON);
                    //Dtimer = DURATION;
                   // DtimerFlag = 2;
                }else if(directionflag == 4){
                    if(TimeInState == IDEAL_DURATION){
                        TimeInState =0;
                        directionflag = 0;
                        Front_Amber_LED_Write(ON);
                        CurrentState = STATE_1;
                    } 
                    Left_Green_LED_Write(OFF);
                    Left_Red_LED_Write(ON);
                    //Ltimer=DURATION;
                    //LtimerFlag = 2;
                }
//                else if((directionflag == 5) && (InitialCount == 1) ){
//                      if(TimeInState == IDEAL_DURATION){
//                        TimeInState =0;
//                        directionflag = 0;
//                        Front_Amber_LED_Write(ON);
//                        CurrentState = STATE_1;
//                    }  
//
//                }
                    
                break;    
            }
        }  
    }
}

//void LCD_Print(){
//    
//        LCD_ClearDisplay();
//        LCD_Position(0,0);
//        LCD_PrintString("FT: ");
//        LCD_PrintNumber(Ftimer);
//        LCD_Position(0,8);
//        LCD_PrintString("RT: ");
//        LCD_PrintNumber(Rtimer);
//        LCD_Position(1,0);
//        LCD_PrintString("DT: ");
//        LCD_PrintNumber(Dtimer);
//        LCD_Position(1,8);
//        LCD_PrintString("LT: ");
//        LCD_PrintNumber(Ltimer);
//}
/* [] END OF FILE */
