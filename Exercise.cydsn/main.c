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
#define ON         1
#define OFF        0
#define Normal     0
#define Afterhours 1

void Initialize();
void LCD_Print();
void TrafficLight_Operation();
void Afterhours_Operation();
void LED_Operation();
void RedDuration_Calculation();

#define IDEAL_DURATION  02
#define GREEN_DURATION  10
#define AMBER_DURATION  02
#define RED_DURATION    44

enum {STATE_1,STATE_2, STATE_3,STATE_4, STATE_5, STATE_6,STATE_7,STATE_8, Ideal};
//uint8 TimeInState;
uint8 CurrentState;
uint8 OneSecondFlag;
uint8 auigreenduration[4]={0,0,0,0};
uint8 auiredduration[4]={0,0,0,0};
uint8 greendurationcount;
uint8 reddurationindex = 0;
uint8 Ftimer ;
uint8 Rtimer ;
uint8 Dtimer ;
uint8 Ltimer ;
uint8 Switch1CaptureFlag = 0;
uint8 FtimerFlag = 0;
uint8 RtimerFlag = 0;
uint8 DtimerFlag = 0;
uint8 LtimerFlag = 0;
uint8 FCurrentState;
uint8 RCurrentState;
uint8 DCurrentState;
uint8 LCurrentState;
uint8 FPreviousState;
uint8 RPreviousState;
uint8 DPreviousState;
uint8 LPreviousState;
uint8 FRedLEDState =0;
uint8 FGreenLEDState =0;
uint8 FAmberLEDState =0;
uint8 RRedLEDState =0;
uint8 RGreenLEDState =0;
uint8 RAmberLEDState =0;
uint8 DRedLEDState =0;
uint8 DGreenLEDState =0;
uint8 DAmberLEDState =0;
uint8 LRedLEDState =0;
uint8 LGreenLEDState =0;
uint8 LAmberLEDState =0;
uint8 InitialCount=0;

int main(void)
{
     
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Initialize();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LED_UpdateTimer_Start();
    LED_UpdateISR_Start();
    SW_ISR1_Start();
    LCD_Start();

    for(;;)
    {
        if(Switch1CaptureFlag){
            Switch1CaptureFlag=0;
            SW_ISR1_ClearPending();
            if(CurrentState == Normal){
                FPreviousState = FCurrentState;
                RPreviousState = RCurrentState;
                DPreviousState = DCurrentState;
                LPreviousState = LCurrentState;
                CurrentState = Afterhours;
            }else{
                CurrentState = Normal;
                 FCurrentState = FPreviousState;
                 RCurrentState = RPreviousState;
                 DCurrentState = DPreviousState;
                 LCurrentState = LPreviousState;
                 Front_Red_LED_Write(FRedLEDState);
                 Front_Amber_LED_Write(FAmberLEDState);
                 Front_Green_LED_Write(FGreenLEDState);
                 Right_Red_LED_Write(RRedLEDState);
                 Right_Amber_LED_Write(RAmberLEDState);
                 Right_Green_LED_Write(RGreenLEDState);
                 Red_LED_Write(DRedLEDState);
                 Amber_LED_Write(DAmberLEDState);
                 Green_LED_Write(DGreenLEDState);
                 Left_Red_LED_Write(LRedLEDState);
                 Left_Amber_LED_Write(LAmberLEDState);
                 Left_Green_LED_Write(LGreenLEDState);
                
            }
        }
        if(CurrentState == Normal){
            TrafficLight_Operation();
            
        }else if(CurrentState == Afterhours){
            
            Afterhours_Operation();
        }else{
            
        }
       
 
    }
}

void Initialize(){
    CurrentState =  Normal;
    FCurrentState = STATE_1 ;
    RCurrentState = STATE_1 ;
    DCurrentState = STATE_1 ;
    LCurrentState = STATE_1 ;
    
    FPreviousState = STATE_1 ;
    RPreviousState = STATE_1 ;
    DPreviousState = STATE_1 ;
    LPreviousState = STATE_1 ;
    
    InitialCount = 1;
    Ftimer = 02;
    Rtimer = 16;
    Dtimer = 30;
    Ltimer = 44;
    Front_Red_LED_Write(ON);
    FRedLEDState = ON;
    Right_Red_LED_Write(ON);
    RRedLEDState = ON;
    Red_LED_Write(ON); 
    DRedLEDState = ON;
    Left_Red_LED_Write(ON);
    LRedLEDState = ON;
}

void TrafficLight_Operation(){
    
     switch(FCurrentState){
            case STATE_1:{
                 if((Ftimer == 02)&&(FtimerFlag == 0)){
                    Front_Green_LED_Write(OFF);
                    FGreenLEDState = OFF;
                    Front_Red_LED_Write(ON);
                    FRedLEDState = ON;
                    FCurrentState = STATE_2;
                 }
                break;
            }case STATE_2:{
                if(Ftimer == 0){
                    Ftimer = AMBER_DURATION;
                    FtimerFlag = 1;
                    FCurrentState = STATE_3;
                }
                break;
            }case STATE_3:{
                if((Ftimer == AMBER_DURATION)&&(FtimerFlag == 1)){
                    Front_Amber_LED_Write(ON);
                    FAmberLEDState = ON;
                    Front_Red_LED_Write(OFF);
                    FRedLEDState = OFF;
                    FCurrentState = STATE_4;
                 }

                break;
            }case STATE_4:{
                 if((Ftimer == 0)&& (FtimerFlag == 1)){
                    Ftimer = GREEN_DURATION;
                    FtimerFlag = 2;
                    FCurrentState = STATE_5;
                }
                break;
            }case STATE_5:{
               if ((Ftimer == GREEN_DURATION)&&(FtimerFlag == 2)){
                    Front_Green_LED_Write(ON);
                    FGreenLEDState = ON;
                    Front_Amber_LED_Write(OFF);
                    FAmberLEDState = OFF;
                    FCurrentState = STATE_6;
                }
                break;
            }case STATE_6:{
                if((Ftimer == 0)&& (FtimerFlag == 2)){
                    Ftimer = RED_DURATION;
                    FtimerFlag = 3;
                    FCurrentState = STATE_7;
                }
                break;
            }case STATE_7:{
                if((FtimerFlag == 3)&&(Ftimer == RED_DURATION)){
                   Front_Green_LED_Write(OFF);
                   FGreenLEDState = OFF;
                   Front_Red_LED_Write(ON);
                   FRedLEDState = ON;
                   FCurrentState = STATE_2;
                }
                break;
            }
            
        } 
        switch(RCurrentState){
            case STATE_1:{
                 if((Rtimer == 16)&&(RtimerFlag == 0)){
                    RCurrentState = STATE_2;
                 }
                break;
            }case STATE_2:{
                if(Rtimer == 0){
                    Rtimer = AMBER_DURATION;
                    RtimerFlag = 1;
                    RCurrentState = STATE_3;
                }
                break;
            }case STATE_3:{
                if(Rtimer == AMBER_DURATION){
                    Right_Red_LED_Write(OFF);
                    RRedLEDState = OFF;
                    Right_Amber_LED_Write(ON);
                    RAmberLEDState = ON;
                    RCurrentState = STATE_4;
                 
                }
                break;
            }case STATE_4:{
                if((Rtimer == 0)&& (RtimerFlag == 1)){
                    Rtimer = GREEN_DURATION;
                    RtimerFlag = 2;
                    RCurrentState = STATE_5;
                }
                break;
            }case STATE_5:{
                if ((Rtimer == GREEN_DURATION)&&(RtimerFlag == 2)){
                    Right_Green_LED_Write(ON);
                    RGreenLEDState = ON;
                    Right_Amber_LED_Write(OFF);
                    RAmberLEDState = OFF;
                    RCurrentState = STATE_6;
                }
                break;
            }case STATE_6:{
                if((Rtimer == 0)&& (RtimerFlag == 2)){
                    Rtimer = RED_DURATION;
                    RtimerFlag = 3;
                    RCurrentState = STATE_7;
                }
                break;
            }case STATE_7:{
                if((RtimerFlag == 3) &&(Rtimer == RED_DURATION)){
                    Right_Green_LED_Write(OFF);
                    RGreenLEDState = OFF;
                    Right_Red_LED_Write(ON);
                    RRedLEDState = ON;
                    RCurrentState = STATE_2;
                }
                break;
            }
            
        }
        switch(DCurrentState){
            case STATE_1:{
                 if((Dtimer == 30)&&(DtimerFlag == 0)){
                    DCurrentState = STATE_2;
                 }
                break;
            }case STATE_2:{
                if(Dtimer == 0){
                    Dtimer = AMBER_DURATION;
                    DtimerFlag = 1;
                    DCurrentState = STATE_3;
                }
                break;
            }case STATE_3:{
                if(Dtimer == AMBER_DURATION){
                    Red_LED_Write(OFF);
                    DRedLEDState = OFF;
                    Amber_LED_Write(ON);
                    DAmberLEDState = ON;
                    DCurrentState = STATE_4;
                 
                }
                break;
            }case STATE_4:{
                if((Dtimer == 0)&& (DtimerFlag == 1)){
                    Dtimer = GREEN_DURATION;
                    DtimerFlag = 2;
                    DCurrentState = STATE_5;
                }
                break;
            }case STATE_5:{
                if ((Dtimer == GREEN_DURATION)&&(DtimerFlag == 2)){
                    Green_LED_Write(ON);
                    DGreenLEDState = ON;
                    Amber_LED_Write(OFF);
                    DAmberLEDState = OFF;
                    DCurrentState = STATE_6;
                }
                break;
            }case STATE_6:{
                if((Dtimer == 0)&& (DtimerFlag == 2)){
                    Dtimer = RED_DURATION;
                    DtimerFlag = 3;
                    DCurrentState = STATE_7;
                }
                break;
            }case STATE_7:{
                if((DtimerFlag == 3) &&(Dtimer == RED_DURATION)){
                    Green_LED_Write(OFF);
                    DGreenLEDState = OFF;
                    Red_LED_Write(ON);
                    DRedLEDState = ON;
                    DCurrentState = STATE_2;
                }
                break;
            }
            
        } 
        switch(LCurrentState){
            case STATE_1:{
                 if((Ltimer == RED_DURATION)&&(LtimerFlag == 0)){
                    LCurrentState = STATE_2;
                 }
                break;
            }case STATE_2:{
                if(Ltimer == 0){
                    Ltimer = AMBER_DURATION;
                    LtimerFlag = 1;
                    LCurrentState = STATE_3;
                }
                break;
            }case STATE_3:{
                if(Ltimer == AMBER_DURATION){
                    Left_Red_LED_Write(OFF);
                    LRedLEDState = OFF;
                    Left_Amber_LED_Write(ON);
                    LAmberLEDState = ON;
                    LCurrentState = STATE_4;
                 
                }
                break;
            }case STATE_4:{
                if((Ltimer == 0)&& (LtimerFlag == 1)){
                    Ltimer = GREEN_DURATION;
                    LtimerFlag = 2;
                    LCurrentState = STATE_5;
                }
                break;
            }case STATE_5:{
                if ((Ltimer == GREEN_DURATION)&&(LtimerFlag == 2)){
                    Left_Green_LED_Write(ON);
                    LGreenLEDState = ON;
                    Left_Amber_LED_Write(OFF);
                    LAmberLEDState = OFF;
                    LCurrentState = STATE_6;
                }
                break;
            }case STATE_6:{
                if((Ltimer == 0)&& (LtimerFlag == 2)){
                    Ltimer = RED_DURATION;
                    LtimerFlag = 3;
                    LCurrentState = STATE_7;
                }
                break;
            }case STATE_7:{
                if((LtimerFlag == 3) &&(Ltimer == RED_DURATION)){
                    Left_Green_LED_Write(OFF);
                    LGreenLEDState = OFF;
                    Left_Red_LED_Write(ON);
                    LRedLEDState = ON;
                    LCurrentState = STATE_2;
                }
                break;
            }
            
        } 
        if(OneSecondFlag){
        OneSecondFlag = 0;
        --Ftimer;
        --Rtimer;
        --Dtimer;
        --Ltimer;
    }
        LCD_Print();
}

void LED_Operation(){
    
    
    
}

void RedDuration_Calculation(){
    
//    auiredduration[0] = auigreenduration[1] + auigreenduration[2] + auigreenduration[3] + AMBER_DURATION + IDEAL_DURATION;
//    auiredduration[1] = auigreenduration[0] + auigreenduration[2] + auigreenduration[3] + AMBER_DURATION + IDEAL_DURATION;
//    auiredduration[2] = auigreenduration[0] + auigreenduration[1] + auigreenduration[3] + AMBER_DURATION + IDEAL_DURATION;
//    auiredduration[3] = auigreenduration[0] + auigreenduration[1] + auigreenduration[2] + AMBER_DURATION + IDEAL_DURATION;
    for (greendurationcount = 0;greendurationcount < 4;greendurationcount++){
        if(reddurationindex == greendurationcount){
            greendurationcount++;
        }
        auiredduration[reddurationindex] = auiredduration[reddurationindex] + auigreenduration[greendurationcount];
    }
     auiredduration[reddurationindex] =  auiredduration[reddurationindex] + AMBER_DURATION + IDEAL_DURATION;
}
void Afterhours_Operation(){
    Front_Green_LED_Write(OFF);
    Front_Red_LED_Write(OFF);
    Right_Green_LED_Write(OFF);
    Right_Red_LED_Write(OFF);
    Left_Green_LED_Write(OFF);
    Left_Red_LED_Write(OFF);
    Green_LED_Write(OFF);
    Red_LED_Write(OFF);
    Front_Amber_LED_Write(ON);
    Right_Amber_LED_Write(ON);
    Left_Amber_LED_Write(ON);
    Amber_LED_Write(ON);
    CyDelay(500);
    Front_Amber_LED_Write(OFF);
    Right_Amber_LED_Write(OFF);
    Left_Amber_LED_Write(OFF);
    Amber_LED_Write(OFF);
    CyDelay(500);
}

void LCD_Print(){
        
        if(Front_Green_LED_Read()== ON){
            LCD_Position(0,0);
            LCD_PrintString("FTG: ");
            LCD_PrintString("  ");
            LCD_Position(0,5);
            LCD_PrintNumber(Ftimer);
        } else if(Front_Red_LED_Read()== ON){
            LCD_Position(0,0);
            LCD_PrintString("FTR: ");
            LCD_PrintString("  ");
            LCD_Position(0,5);
            LCD_PrintNumber(Ftimer);
        }else if(Front_Amber_LED_Read()== ON){
            LCD_Position(0,0);
            LCD_PrintString("FTA: ");
            LCD_PrintString("  ");
            LCD_Position(0,5);
            LCD_PrintNumber(Ftimer);
        }
        
        if(Right_Green_LED_Read()== ON){
            LCD_Position(0,8);
            LCD_PrintString("RTG: ");
            LCD_PrintString("  ");
            LCD_Position(0,13);
            LCD_PrintNumber(Rtimer);
        }else if(Right_Red_LED_Read()== ON){
            LCD_Position(0,8);
            LCD_PrintString("RTR: ");
            LCD_PrintString("  ");
            LCD_Position(0,13);
            LCD_PrintNumber(Rtimer);
        }else if(Right_Amber_LED_Read()== ON){
            LCD_Position(0,8);
            LCD_PrintString("RTA: ");
            LCD_PrintString("  ");
            LCD_Position(0,13);
            LCD_PrintNumber(Rtimer);
        }
        
        if( Left_Green_LED_Read() == ON){
            LCD_Position(1,0);
            LCD_PrintString("LTG: ");
            LCD_PrintString("  ");
            LCD_Position(1,5);
            LCD_PrintNumber(Ltimer);
        }else if( Left_Red_LED_Read() == ON){
            LCD_Position(1,0);
            LCD_PrintString("LTR: ");
            LCD_PrintString("  ");
            LCD_Position(1,5);
            LCD_PrintNumber(Ltimer);
        }else if( Left_Amber_LED_Read() == ON){
            LCD_Position(1,0);
            LCD_PrintString("LTA: ");
            LCD_PrintString("  ");
            LCD_Position(1,5);
            LCD_PrintNumber(Ltimer);
        }
        
        if( Green_LED_Read()== ON){
            LCD_Position(1,8);
            LCD_PrintString("DTG: ");
            LCD_PrintString("  ");
            LCD_Position(1,13);
            LCD_PrintNumber(Dtimer);
        }else if( Red_LED_Read()== ON){
            LCD_Position(1,8);
            LCD_PrintString("DTR: ");
            LCD_PrintString("  ");
            LCD_Position(1,13);
            LCD_PrintNumber(Dtimer);
        }else if(Amber_LED_Read()== ON){
            LCD_Position(1,8);
            LCD_PrintString("DTA: ");
            LCD_PrintString("  ");
            LCD_Position(1,13);
            LCD_PrintNumber(Dtimer);
        }
        
}
/* [] END OF FILE */
