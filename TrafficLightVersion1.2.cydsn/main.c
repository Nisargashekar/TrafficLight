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
//#include <SerialCommunication.h>
//#include <UART.c>
#include <STDIO.H>
#include <MATH.H>

#define ON               1
#define OFF              0
#define Normal           0
#define Afterhours       1
#define ThreeDigitNumber 100
#define Index            12 




#define IDEAL_DURATION   02
#define GREEN_DURATION   10
#define AMBER_DURATION   02
#define DEFAULT_DURATION 10
#define Sizeoffarray     46
#define Setting_Mode     01
#define Working_Mode     02

void Start_AllModules();
void Settingmode_Operation();
void Workingmode_Operation();
void Initialize();
void LCD_Print();
void TrafficLight_Operation();
void Afterhours_Operation();
void LED_Operation(uint8 onoff);
void RedDuration_Calculation();
void SettingModeLED_Operation();
void Mode_Selection();
void EEPROM_WriteFunction(uint16 EepromAddress);
void EEPROM_Read(uint16 EepromAddress , uint16 RegCount);

void UART_Read();
void UART_Start_Operation();

enum {STATE_1,STATE_2, STATE_3,STATE_4, STATE_5, STATE_6,STATE_7,STATE_8,STATE_9,STATE_10,STATE_11,STATE_12};
//uint8 TimeInState;
uint8 CurrentState;
uint8 OneSecondFlag;
uint16 FGREEN_DURATION = DEFAULT_DURATION;
uint16 RGREEN_DURATION = DEFAULT_DURATION;
uint16 DGREEN_DURATION = DEFAULT_DURATION;
uint16 LGREEN_DURATION = DEFAULT_DURATION;
uint16 auigreenduration[Sizeoffarray]={DEFAULT_DURATION,DEFAULT_DURATION,DEFAULT_DURATION,DEFAULT_DURATION,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16 auiredduration[4]={0,0,0,0};

uint16 Ftimer ;
uint16 Rtimer ;
uint16 Dtimer ;
uint16 Ltimer ;
uint8 Switch1CaptureFlag = 0;
uint8 Switch2CaptureFlag = 0;
uint8 LightSettingFlag =0;
uint8 Switch1PressCount = 0;
uint8 Mode = 0;

uint8 LightCurrentState;
uint8 LightPreviousState;
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
uint8 LoopCounter;
uint16 EepromAddress = 0;
uint8 EEPROMWriteFlag =0;
uint16 my_ADC_counts;
char8 result_str[16u];
float result_in_volts;

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  
* This function starts ADC,Timer,ISR, EEPROM,LCD. Check for switch press         
* 
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

int main(void)
{
     
    CyGlobalIntEnable; /* Enable global interrupts. */
    Start_AllModules();

    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    
    for(;;)
    {
            
        UART_Read();   
            
        if(CurrentState == Afterhours){
            
            if(Switch2CaptureFlag){
                Switch2CaptureFlag=0;
            }
            
        }else{
            if(Switch2CaptureFlag){
                Switch2CaptureFlag=0;
                LightSettingFlag++;
                SW_ISR2_ClearPending();
                Mode_Selection();           
            }
        }
        

        if(Mode == Setting_Mode){
            
            Settingmode_Operation();
            
            SettingModeLED_Operation();
            
        }else if(Mode == Working_Mode){
           
             Workingmode_Operation();
        }
       
    }
}

/*******************************************************************************
* Function Name: Start_AllModules
********************************************************************************
*
* Summary:
*  
* Starts ADC,Timer,Interrupt,EEMPROm,UART,LCD 
* 
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

void Start_AllModules(){
    
    ADC_Start();
    ADC_StartConvert();
    LED_UpdateTimer_Start();
    LED_UpdateISR_Start();
    EEPROM_Start();
    SW_ISR1_Start();
    SW_ISR2_Start();
    UART_Start_Operation();
    LCD_Start();
    Initialize();
    
}

/*******************************************************************************
* Function Name: Mode_Selection
********************************************************************************
*
* Summary:
*  
* Set the mode of operation  to setting mode by checking LightSettingFlag and stores the   
* auigreenduration array value to eeprom
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Mode_Selection(){
    
    if(LightSettingFlag == 1){
        
            Mode = Setting_Mode;
            SettingModeLED_Operation();
            LCD_ClearDisplay();
            LCD_Print();
            
        }
    else if(LightSettingFlag == 3){
        
            LightSettingFlag =0;
            Switch1PressCount =0;
            EEPROMWriteFlag = 1;
            auigreenduration[4] = EEPROMWriteFlag;
            EEPROM_WriteFunction(0);
            LCD_ClearDisplay();
            Initialize();
    }
}
/*******************************************************************************
* Function Name: Initialize
********************************************************************************
*
* Summary:
*  
* This function sets the default states, mode of operation and reads the eeprom values    
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

void Initialize(){
    
    CurrentState =  Normal;
    Mode = Working_Mode;
    LightCurrentState = STATE_1;
    LightPreviousState = STATE_1;
    InitialCount = 1;
//    Ftimer = 02;
//    Rtimer = 16;
//    Dtimer = 30;
//    Ltimer = 44;
    EEPROM_Read(0,5);
    
    if(auigreenduration[4] == 0){
        
        EEPROM_WriteFunction(0);
    }

    RedDuration_Calculation();
    Front_Red_LED_Write(ON);
    FRedLEDState = ON;
    Right_Red_LED_Write(ON);
    RRedLEDState = ON;
    Red_LED_Write(ON); 
    DRedLEDState = ON;
    Left_Red_LED_Write(ON);
    LRedLEDState = ON;
    
}


/*******************************************************************************
* Function Name: LED_Operation
********************************************************************************
*
* Summary:
*  
* This function turns on/off the LED depending on the arguments passed inside the fucntion   
*  
*
* Parameters:
*  onoff
*
* Return:
*  None
*
*******************************************************************************/
void LED_Operation(uint8 onoff ){
    
    Front_Red_LED_Write(onoff);
    Front_Amber_LED_Write(onoff);
    Front_Green_LED_Write(onoff);
    
    Right_Red_LED_Write(onoff);
    Right_Amber_LED_Write(onoff);
    Right_Green_LED_Write(onoff);
    
    Red_LED_Write(onoff);
    Amber_LED_Write(onoff);
    Green_LED_Write(onoff);
    
    Left_Red_LED_Write(onoff);
    Left_Amber_LED_Write(onoff);
    Left_Green_LED_Write(onoff);
}

/*******************************************************************************
* Function Name: LED_Status
********************************************************************************
*
* Summary:
*  
* This function check for currentstate of operation of trafficlight and write      
* the state of each LED 
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

void LED_Status(){
    
    if(CurrentState == Normal){
        LightPreviousState = LightCurrentState;
        LCD_ClearDisplay();
        CurrentState = Afterhours;
        LCD_Print();
        
    }else if(CurrentState == Afterhours){
         
         CurrentState = Normal;
         LightCurrentState = LightPreviousState;         
        
        
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
         
    }else {
        
        
    }
    
}

/*******************************************************************************
* Function Name: mapf
********************************************************************************
*
* Summary:
*  
* This function check for currentstate of operation of trafficlight and write      
* the state of each LED 
*
* Parameters:
* POT voltage, min vtg, max vtg, min value, max value 
*
* Return:
* Value or Number between 10 to 150 
*
*******************************************************************************/

double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*******************************************************************************
* Function Name: DurationSetting_Operation
********************************************************************************
*
* Summary:
*  
* This function read the ADC value and converts it into voltage      
*  
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void DurationSetting_Operation(){
    
        while(!ADC_IsEndConversion(ADC_WAIT_FOR_RESULT));
        my_ADC_counts = ADC_GetResult16();
        result_in_volts = ADC_CountsTo_Volts(my_ADC_counts);
        //sprintf((char *)result_str,"%1.2fv",result_in_volts);
        
}

/*******************************************************************************
* Function Name: Settingmode_Operation
********************************************************************************
*
* Summary:
*  
* This function perfomes setting mode operation       
*   
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void Settingmode_Operation(){
    
    if(Switch1CaptureFlag){
                Switch1PressCount++;
                Switch1CaptureFlag =0;
                SW_ISR1_ClearPending();
            }
            if(Switch1PressCount == 1){
                
                DurationSetting_Operation();
                if(LightSettingFlag == 2){
                    LightSettingFlag = 1;
//                    ExitflagFront = 1;
//                    Switch2PressCountFront++;
                    FGREEN_DURATION = mapf(result_in_volts, 0, 3.3, 10, 150);
                    auigreenduration[0]=FGREEN_DURATION; 
                    
                }
//                if((Switch2PressCountFront == 2) && (ExitflagFront == 1)){
//                    Switch2PressCountFront++;
//                    ExitflagFront = 0;
//                    Mode_Selection();
//                }else{
//                    
//                }
                LCD_ClearDisplay(); 
                LCD_Print();
                             
            }else if (Switch1PressCount == 2){
                
                DurationSetting_Operation();
                if(LightSettingFlag == 2){
                    LightSettingFlag = 1;
                    RGREEN_DURATION = mapf(result_in_volts, 0, 3.3, 10, 150);
                    auigreenduration[1]=RGREEN_DURATION;   
                    
                }
                LCD_ClearDisplay(); 
                LCD_Print();
                
            }else if(Switch1PressCount == 3){
                
                DurationSetting_Operation();
                if(LightSettingFlag == 2){
                    LightSettingFlag = 1;
                    DGREEN_DURATION = mapf(result_in_volts, 0, 3.3, 10, 150);
                    auigreenduration[2]=DGREEN_DURATION;
                 
                } 
                LCD_ClearDisplay(); 
                LCD_Print();
                 
            }else if(Switch1PressCount == 4){
                
                DurationSetting_Operation();
                if(LightSettingFlag == 2){
                    LightSettingFlag = 1;
                    LGREEN_DURATION = mapf(result_in_volts, 0, 3.3, 10, 150);
                    auigreenduration[3]=LGREEN_DURATION;
                    
                }
                LCD_ClearDisplay(); 
                LCD_Print();
                  
            }else{
                Switch1PressCount=0;
            }
}

/*******************************************************************************
* Function Name: Workingmode_Operation
********************************************************************************
*
* Summary:
*  
* This function perfomes working mode operation       
*   
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void Workingmode_Operation(){
    
    if(Switch1CaptureFlag){
        Switch1CaptureFlag=0;
        SW_ISR1_ClearPending();
        LED_Status();
    }
    if(CurrentState == Normal){
        TrafficLight_Operation();
        
    }else if(CurrentState == Afterhours){
        
        Afterhours_Operation();
        
    }else{
        
    }
    
}

/*******************************************************************************
* Function Name: TrafficLight_Operation
********************************************************************************
*
* Summary:
*  
* This function performce the LED On/off function based on the LightCurrentState      
* and timer values of each lane  
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void TrafficLight_Operation(){
    
    switch(LightCurrentState){
        case STATE_1:{
             if(Ftimer == 0){
                if(InitialCount){
                    InitialCount =0;
                }else{
                    Ltimer = auiredduration[3];
                }
                Ftimer = AMBER_DURATION;
                if(Ftimer == AMBER_DURATION){

                    Front_Red_LED_Write(OFF);
                    FRedLEDState = OFF;

                    Front_Amber_LED_Write(ON);
                    FAmberLEDState = ON;

                    LightCurrentState = STATE_2;
                }
            }
            break;
        }case STATE_2:{
            if(Ftimer == 0){
                Ftimer = auigreenduration[0];
                 if(Ftimer == auigreenduration[0]){

                    Front_Amber_LED_Write(OFF);
                    FAmberLEDState = OFF;

                    Front_Green_LED_Write(ON);
                    FGreenLEDState = ON;

                    LightCurrentState = STATE_3;
                }
            }
           
            break;
        }case STATE_3:{
            if(Ftimer == 0){
                Ftimer = IDEAL_DURATION;
                if(Ftimer == IDEAL_DURATION){
                
                    Front_Green_LED_Write(OFF);
                    FGreenLEDState = OFF;

                    Front_Red_LED_Write(ON);
                    FRedLEDState = ON; 

                    LightCurrentState = STATE_4;
                }
            }
            
            break;
        }case STATE_4:{
            if(Rtimer == 0){
                Ftimer = auiredduration[0];
                Rtimer = AMBER_DURATION;
                if(Rtimer == AMBER_DURATION){

                    Right_Red_LED_Write(OFF);
                    RRedLEDState = OFF;

                    Right_Amber_LED_Write(ON);
                    RAmberLEDState = ON;

                    LightCurrentState = STATE_5;
                }
            }
            break;
        }case STATE_5:{
            if(Rtimer == 0){
                Rtimer = auigreenduration[1];
                if(Rtimer == auigreenduration[1]){

                    Right_Amber_LED_Write(OFF);
                    RAmberLEDState = OFF;

                    Right_Green_LED_Write(ON);
                    RGreenLEDState = ON;

                    LightCurrentState = STATE_6;
                }
            }
            break;
        }case STATE_6:{
            if(Rtimer == 0){
                Rtimer = IDEAL_DURATION;
                if(Rtimer == IDEAL_DURATION){

                    Right_Green_LED_Write(OFF);
                    RGreenLEDState = OFF;

                    Right_Red_LED_Write(ON);
                    RRedLEDState = ON;

                    LightCurrentState = STATE_7;
                }
            }
            break;
        }case STATE_7:{
            if(Dtimer == 0){
                Rtimer = auiredduration[1];
                Dtimer = AMBER_DURATION;
                if(Dtimer == AMBER_DURATION){

                    Red_LED_Write(OFF);
                    DRedLEDState = OFF;

                    Amber_LED_Write(ON);
                    DAmberLEDState = ON;

                    LightCurrentState = STATE_8;
                }
            }
            break;
        }case STATE_8:{
             if(Dtimer == 0){
                Dtimer = auigreenduration[2];
                if(Dtimer == auigreenduration[2]){

                    Amber_LED_Write(OFF);
                    DAmberLEDState = OFF;

                    Green_LED_Write(ON);
                    DGreenLEDState = ON;

                    LightCurrentState = STATE_9;
                }
            }
            break;
        }case STATE_9:{
             if(Dtimer == 0){
                Dtimer = IDEAL_DURATION;
                if(Dtimer == IDEAL_DURATION){

                    Green_LED_Write(OFF);
                    DGreenLEDState = OFF;

                    Red_LED_Write(ON);
                    DRedLEDState = ON;

                    LightCurrentState = STATE_10;
                }
            }
            break;
        }case STATE_10:{
            if(Ltimer == 0){
                Dtimer = auiredduration[2];
                Ltimer = AMBER_DURATION;
                if(Ltimer == AMBER_DURATION){

                    Left_Red_LED_Write(OFF);
                    LRedLEDState = OFF;

                    Left_Amber_LED_Write(ON);
                    LAmberLEDState = ON;

                    LightCurrentState = STATE_11;
                }
            }
            break;
        }case STATE_11:{
            if(Ltimer == 0){
                Ltimer = auigreenduration[3];
                if(Ltimer == auigreenduration[3]){

                    Left_Amber_LED_Write(OFF);
                    LAmberLEDState = OFF;

                    Left_Green_LED_Write(ON);
                    LGreenLEDState = ON;

                    LightCurrentState = STATE_12;
                }
            }
            break;
        }case STATE_12:{
            if(Ltimer == 0){
                Ltimer = IDEAL_DURATION;
                if(Ltimer == IDEAL_DURATION){

                    Left_Green_LED_Write(OFF);
                    LGreenLEDState = OFF;

                    Left_Red_LED_Write(ON);
                    LRedLEDState = ON;

                    LightCurrentState = STATE_1;
                }
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

/*******************************************************************************
* Function Name: SettingModeLED_Operation
********************************************************************************
*
* Summary:
*  
* This function switches off all the LED's if the mode of operation is setting mode       
*  
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void SettingModeLED_Operation(){
    
    if(Switch1PressCount == 0){
        
        Front_Green_LED_Write(OFF);
        Front_Red_LED_Write(OFF);
        Right_Green_LED_Write(OFF);
        Right_Red_LED_Write(OFF);
        Left_Green_LED_Write(OFF);
        Left_Red_LED_Write(OFF);
        Green_LED_Write(OFF);
        Red_LED_Write(OFF);
        Front_Amber_LED_Write(OFF);
        Right_Amber_LED_Write(OFF);
        Left_Amber_LED_Write(OFF);
        Amber_LED_Write(OFF);
    }
    
    if(Switch1PressCount == 1){
        Left_Green_LED_Write(OFF);
        Front_Green_LED_Write(ON);
        CyDelay(100);
        Front_Green_LED_Write(OFF);
        CyDelay(100);
    }else if(Switch1PressCount == 2){
        Front_Green_LED_Write(OFF);
        Right_Green_LED_Write(ON);
        CyDelay(100);
        Right_Green_LED_Write(OFF);
        CyDelay(100);
    }else if(Switch1PressCount == 3){
        Right_Green_LED_Write(OFF);
        Green_LED_Write(ON);
        CyDelay(100);
        Green_LED_Write(OFF);
        CyDelay(100);
    }else if(Switch1PressCount == 4){
        Green_LED_Write(OFF);
        Left_Green_LED_Write(ON);
        CyDelay(100);
        Left_Green_LED_Write(OFF);
        CyDelay(100);
        
    }else{
        
    }
    
}

/*******************************************************************************
* Function Name: Afterhours_Operation
********************************************************************************
*
* Summary:
*  
* This function switches off and on the amber LED in the afterhour mode i.e,night mode       
*  
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/
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

/*******************************************************************************
* Function Name: EEPROM_WriteFunction
********************************************************************************
*
* Summary:
*  
* This function writes the set green duration values into eeprom        
*  
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/
void EEPROM_WriteFunction(uint16 EepromAddress){
    
    if(EEPROMWriteFlag == 2){
        
        EEPROM_WriteByte(auigreenduration[EepromAddress],EepromAddress);
        
    }else{
        
        for(LoopCounter = 0;LoopCounter < Sizeoffarray; LoopCounter++){

            EEPROM_WriteByte(auigreenduration[LoopCounter],EepromAddress);
            EepromAddress++;
        }
        
    }
}

/*******************************************************************************
* Function Name: EEPROM_Read
********************************************************************************
*
* Summary:
*  
* This function reads the stored set duration value form eeprom         
*  
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void EEPROM_Read(uint16 EepromAddress , uint16 RegCount){
        
    
    if(EEPROMWriteFlag == 2){
        
        auigreenduration[EepromAddress] = EEPROM_ReadByte(EepromAddress);
        
    }else{
        
        
        for(LoopCounter = EepromAddress ; LoopCounter < (EepromAddress + RegCount); LoopCounter++){        
           auigreenduration[LoopCounter] = EEPROM_ReadByte(LoopCounter);
//            EepromAddress++;
        }   
    }
        
        
        
}

/*******************************************************************************
* Function Name: RedDuration_Calculation
********************************************************************************
*
* Summary:
*  
* This function calculates the red duration for all for timers during start of the          
* program and stores the red duration value in auiredduration array
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void RedDuration_Calculation(){
    
    if(InitialCount){
        Ftimer = IDEAL_DURATION;
        Rtimer = auigreenduration[0]+AMBER_DURATION+(IDEAL_DURATION*2);
        Dtimer = auigreenduration[0]+ auigreenduration[1]+ (AMBER_DURATION*2)+(IDEAL_DURATION*3);
        Ltimer = auigreenduration[0]+ auigreenduration[1]+ auigreenduration[2]+(AMBER_DURATION*3)+(IDEAL_DURATION*4);
    }
    auiredduration[0] = auigreenduration[1] + auigreenduration[2] + auigreenduration[3] + (AMBER_DURATION*3) + (IDEAL_DURATION*3);
    auiredduration[1] = auigreenduration[0] + auigreenduration[2] + auigreenduration[3] + (AMBER_DURATION*3) + (IDEAL_DURATION*3);
    auiredduration[2] = auigreenduration[0] + auigreenduration[1] + auigreenduration[3] + (AMBER_DURATION*3) + (IDEAL_DURATION*3);
    auiredduration[3] = auigreenduration[0] + auigreenduration[1] + auigreenduration[2] + (AMBER_DURATION*3) + (IDEAL_DURATION*3);
    
}


/*******************************************************************************
* Function Name: LCD_Clearindex
********************************************************************************
*
* Summary:
*  
* This function clears the third index of the number or parameter, when the number          
* decreases from three digit to two digit. In other words trasition from three digit
* to two or one digit, the clear operation for the second or third digit is done
*
*
* Parameters:
* Value 
*
* Return:
* None
*
*******************************************************************************/

void LCD_Clearindex(uint16 Value){
    
    if(CurrentState == Normal){
        
        if(Value < ThreeDigitNumber ){
            LCD_Position(0,5);
            LCD_PrintString("   ");
            LCD_Position(0,5);
            LCD_PrintNumber(Ftimer);
        }else{
                
            LCD_Position(0,5);
            LCD_PrintNumber(Ftimer);
        }
         if(Value < ThreeDigitNumber ){
            LCD_Position(0,13);
            LCD_PrintString("   ");
            LCD_Position(0,13);
            LCD_PrintNumber(Rtimer);
        }else{
                
            LCD_Position(0,13); 
            LCD_PrintNumber(Rtimer);
        }
         if(Value < ThreeDigitNumber ){
            LCD_Position(1,13);
            LCD_PrintString("   ");
            LCD_Position(1,13); 
            LCD_PrintNumber(Dtimer);
        }else{
                
            LCD_Position(1,13);  
            LCD_PrintNumber(Dtimer);
        }
         if(Value < ThreeDigitNumber ){
            LCD_Position(1,5);
            LCD_PrintString("   ");
            LCD_Position(1,5); 
            LCD_PrintNumber(Ltimer);
        }else{
                
            LCD_Position(1,5); 
            LCD_PrintNumber(Ltimer);
        }
        
    }
//    else if(LightSettingFlag){
//        
//        if(Value < ThreeDigitNumber ){
//            LCD_Position(1,0);
//            LCD_PrintString("   ");
//            LCD_Position(1,0);
//            LCD_PrintDecUint16(Value);
//            LCD_Position(1,6);
//            LCD_PrintString("   ");
//            LCD_Position(1,6);
//        }else{
//                        
//            LCD_Position(1,0);
//            LCD_PrintDecUint16(Value);
//            LCD_Position(1,6); 
//        }
//        
//    }
        else{
        
        
    }
    
    
}




/*******************************************************************************
* Function Name: LCD_Print
********************************************************************************
*
* Summary:
*  
* This function performces timley operation of LCD write based on the operationg mode          
* 
*
* Parameters:
* None 
*
* Return:
* None
*
*******************************************************************************/

void LCD_Print(){
    
    uint16 duration; 
    
        if(LightSettingFlag){
            
             if(Switch1PressCount == 0){
                
                LCD_Position(0,0);
                LCD_PrintString("Setting Mode:  ");
                
            }
            
            if(Switch1PressCount == 1){
                
                LCD_Position(0,0);
                LCD_PrintString("FrontLaneGreenDur  ");
//                if(LightSettingFlag){
//                }
                duration =  mapf(result_in_volts, 0, 3.3, 10, 150);
                if(duration < ThreeDigitNumber ){
                    LCD_Position(1,0);
                    LCD_PrintString("   ");
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6);
                    LCD_PrintString("   ");
                    LCD_Position(1,6);
                }else{
                                
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6); 
                }
                LCD_PrintNumber(auigreenduration[0]);
                LCD_Position(1,9);
                LCD_PrintString("PresLeftBut");
                
            } else if(Switch1PressCount == 2){
                
                LCD_Position(0,0);
                LCD_PrintString("RightLaneGreenDur  ");
                duration =  mapf(result_in_volts, 0, 3.3, 10, 150);
                if(duration < ThreeDigitNumber ){
                    LCD_Position(1,0);
                    LCD_PrintString("   ");
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6);
                    LCD_PrintString("   ");
                    LCD_Position(1,6);
                }else{
                                
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6); 
                }
                LCD_PrintNumber(auigreenduration[1]);
                LCD_Position(1,9);
                LCD_PrintString("PressLeftBut");
                
            }else if(Switch1PressCount == 3){
                
                LCD_Position(0,0);
                LCD_PrintString("DownLaneGreenDur  ");
                duration =  mapf(result_in_volts, 0, 3.3, 10, 150);
                if(duration < ThreeDigitNumber ){
                    LCD_Position(1,0);
                    LCD_PrintString("   ");
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6);
                    LCD_PrintString("   ");
                    LCD_Position(1,6);
                }else{
                                
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6); 
                }
                LCD_PrintNumber(auigreenduration[2]);
                LCD_Position(1,9);
                LCD_PrintString("PressLeftBut");
                
            }else if(Switch1PressCount == 4){
                
                LCD_Position(0,0);
                LCD_PrintString("LeftLaneGreenDur  ");
               duration =  mapf(result_in_volts, 0, 3.3, 10, 150);
                if(duration < ThreeDigitNumber ){
                    LCD_Position(1,0);
                    LCD_PrintString("   ");
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6);
                    LCD_PrintString("   ");
                    LCD_Position(1,6);
                }else{
                                
                    LCD_Position(1,0);
                    LCD_PrintDecUint16(duration);
                    LCD_Position(1,6); 
                }
                LCD_PrintNumber(auigreenduration[3]);
                LCD_Position(1,9);
                LCD_PrintString("PressLeftBut");
                
            }else{
                
                
            }

        }else if(CurrentState == Normal){
            
            
            if(Front_Green_LED_Read()== ON){
                LCD_Position(0,0);
                LCD_PrintString("FTG: ");
                LCD_Clearindex(Ftimer);
                
            } else if(Front_Red_LED_Read()== ON){
                LCD_Position(0,0);
                LCD_PrintString("FTR: ");
                LCD_Clearindex(Ftimer);
     
            }else if(Front_Amber_LED_Read()== ON){
                LCD_Position(0,0);
                LCD_PrintString("FTA: ");
                LCD_Clearindex(Ftimer);
                
            }
            
            if(Right_Green_LED_Read()== ON){
                LCD_Position(0,8);
                LCD_PrintString("RTG: ");
                LCD_Clearindex(Rtimer);
                
            }else if(Right_Red_LED_Read()== ON){
                LCD_Position(0,8);
                LCD_PrintString("RTR: ");
                LCD_Clearindex(Rtimer);
                
            }else if(Right_Amber_LED_Read()== ON){
                LCD_Position(0,8);
                LCD_PrintString("RTA: ");
                LCD_Clearindex(Rtimer);
                
            }
            
            if( Left_Green_LED_Read() == ON){
                LCD_Position(1,0);
                LCD_PrintString("LTG: ");
                LCD_Clearindex(Ltimer);
                
            }else if( Left_Red_LED_Read() == ON){
                LCD_Position(1,0);
                LCD_PrintString("LTR: ");
                LCD_Clearindex(Ltimer);
                
            }else if( Left_Amber_LED_Read() == ON){
                LCD_Position(1,0);
                LCD_PrintString("LTA: ");
                LCD_Clearindex(Ltimer);
                
            }
            
            if( Green_LED_Read()== ON){
                LCD_Position(1,8);
                LCD_PrintString("DTG: ");
                LCD_Clearindex(Dtimer);
                
            }else if( Red_LED_Read()== ON){
                LCD_Position(1,8);
                LCD_PrintString("DTR: ");
                LCD_Clearindex(Dtimer);
                
            }else if(Amber_LED_Read()== ON){
                LCD_Position(1,8);
                LCD_PrintString("DTA: ");
                LCD_Clearindex(Dtimer);
                
            }
             
        } 
        else if(CurrentState == Afterhours){
            
                LCD_Position(0,3);
                LCD_PrintString("Night Mode");
        }

        
}
/* [] END OF FILE */
