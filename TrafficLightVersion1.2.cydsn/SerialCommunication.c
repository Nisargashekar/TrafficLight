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
#include <project.h>
#include <SerialCommunication.h>
#include <STDIO.H>



char acuartrxbuffer[UART_RxBuffersize];
uint8 auiuartrxarray[UART_Arraysize];
uint8 auimodbusrxarry[Modbus_Command_Size];
char acuarttxbuffer[UART_TxBuffersize];
uint8 auiresponseerror[ErrorRespArraySize];
uint8 auiresposearray[Responsesize];
uint8 Startindex = 0;
uint8 Bytecount = 0;
uint16 Singlewritevalue = 0;
uint16 Multiplewritevalue = 0;
uint8 uint8to16conversionflag = 0;
uint8 LoopCounterSerial;
uint16 Buffersize = 0;
uint8 Errorflag = 0;

extern uint16 auigreenduration[];
extern uint8 EEPROMWriteFlag;
extern volatile uint8 UART_rxBuffer[UART_RX_BUFFER_SIZE];

/*******************************************************************************
* Function Name: UART_Start_Operation
********************************************************************************
*
* Summary:
*  
* This function starts UART and enables rx and tx     
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_Start_Operation(){
    
    UART_Start();
    UART_EnableRxInt();
    UART_EnableTxInt();
    UART_ClearRxBuffer();
    UART_ClearTxBuffer();
}

/*******************************************************************************
* Function Name: UART_Read
********************************************************************************
*
* Summary:
*  
* This function copies the UART data to array  acuartrxbuffer    
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_Read(){
    
    Check_For_Proper_Response();
    
    Buffersize = UART_GetRxBufferSize();
    
    if(Buffersize > (UART_Stringsize - 1)){
        if(UART_rxBuffer[UART_Stringsize-1] != '#'){
            UART_ClearRxBuffer();
        }else{
            memset(acuartrxbuffer , 0 , UART_Stringsize);
            memcpy(acuartrxbuffer , (char *)UART_rxBuffer ,UART_Stringsize);
            UART_ClearRxBuffer();
            UART_RxChar_to_ByteConversion();
        }
    }
    
}

/*******************************************************************************
* Function Name: UART_RxChar_to_ByteConversion
********************************************************************************
*
* Summary:
*  
* This function converts the rx char string to byte data and stores in auiuaertrx array
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_RxChar_to_ByteConversion(void){
    
    char ASCIIHex[2] = "00";
    uint8 Stringcounter = 1;
    uint8 Arraycounter = 0;
    uint8 Conversion = 0;
    
    if((acuartrxbuffer[UART_Startindex] == '$') & (acuartrxbuffer[UART_Endindex] == '#')){
        
        for(Stringcounter = 1; Stringcounter <UART_Endindex;){
            if(acuartrxbuffer[Stringcounter] == ','){
                
                Stringcounter++;
            }else{
                
                ASCIIHex[0] = acuartrxbuffer[Stringcounter++];
                ASCIIHex[1] = acuartrxbuffer[Stringcounter++];
                Conversion = ASCII_to_HexConversion(ASCIIHex);
                auiuartrxarray[Arraycounter++] = Conversion;
            }
            
        }
        
        Modbuslike_Process();
    }else{
        
        UART_ClearRxBuffer();
    }
    
    
    
}

/*******************************************************************************
* Function Name: ASCII_to_HexConversion
********************************************************************************
*
* Summary:
*  
* This function converts ACSII to Hex value  
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
uint8 ASCII_to_HexConversion(char ASCIIHex[]){
    
    char cCharlowernibble;
    char cCharhighernibble;
    uint8 Hexbyte;
    
    cCharhighernibble = ASCIIHex[0];
    cCharlowernibble =  ASCIIHex[1];
    
    if(cCharhighernibble > '9'){
        
        cCharhighernibble = cCharhighernibble - 7;
    }
    
    cCharhighernibble =cCharhighernibble - '0';
    
    Hexbyte = cCharhighernibble;
    Hexbyte = Hexbyte << 4;
    
    if(cCharlowernibble > '9'){
        
        cCharlowernibble = cCharlowernibble - 7;   
    }
    
    cCharlowernibble = cCharlowernibble - '0';
    
    Hexbyte = Hexbyte | cCharlowernibble;
    
    return Hexbyte;
    
}

/*******************************************************************************
* Function Name: Modbuslike_Process
********************************************************************************
*
* Summary:
*  
* This function processing the modbus data  
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

void Modbuslike_Process(void){
    
    uint8  ByteSent = 0;  
    uint16 CRCResult = 0;
    uint16 Twobyte1 = 0;
    uint16 Twobyte2 = 0;
   
    if(auiuartrxarray[13] != DeviceID){
        
        //UART_ClearRxBuffer();
        
    }else{
        
        ByteSent = auiuartrxarray[12];
        
        for(LoopCounterSerial = 13; LoopCounterSerial < (13+ByteSent);LoopCounterSerial++){
            
            auimodbusrxarry[LoopCounterSerial - 13] = auiuartrxarray[LoopCounterSerial];
        }
        
        CRCResult = CalculateCRC16(auimodbusrxarry,ByteSent);
        uint8to16conversionflag = 1;
        if(CRCResult == Uint8_to_Uint16Conversion( 19, 20)){
            
            uint8to16conversionflag = 2;
            Twobyte1 = Uint8_to_Uint16Conversion( 2, 3);
            Twobyte2 = Uint8_to_Uint16Conversion( 4, 5);
            
            if((auimodbusrxarry[1] != FunctionCode) &&(auimodbusrxarry[1] != SingleWrite) &&(auimodbusrxarry[1] != MultipleWrite)){
                
                Errorflag = FunctionCodeError;
                Modbus_Error_Response(auimodbusrxarry , 1);
                
            }else if(auimodbusrxarry[1] == SingleWrite){
                if((Twobyte1 < StartRegisterAdd)|| ( Twobyte1 > EndRegisterAdd)){
                    
                    
                    Errorflag = InvalidRegisterAdd;
                    Modbus_Error_Response(auimodbusrxarry , 1);
                    
                }else{
                    
                    Modbus_Single_Write(Twobyte1 , Twobyte2);
                }
                    
                
            }else if(auimodbusrxarry[1] == MultipleWrite){
                
                Modbus_Multiple_Write();
                
            }else if( (Twobyte1 < StartRegisterAdd)|| ((Twobyte1 + Twobyte2) > EndRegisterAdd)){
                
                if((Twobyte1 + Twobyte2) > EndRegisterAdd){
                    
                    Errorflag = InvalidRegisterAdd;
                    Modbus_Error_Response(auimodbusrxarry , 1);
                }else{
                    
                    Errorflag = InvalidRegisterAdd;
                    Modbus_Error_Response(auimodbusrxarry , 1);
                }
                
            }else if (auimodbusrxarry[1] == FunctionCode){
                
                Modbus_Response(Twobyte1,Twobyte2);
            }
            else{
                
                
            }
        }else{
             
            Errorflag = CRCError;
        }
    }

}

/*******************************************************************************
* Function Name: Uint8_to_Uint16Conversion
********************************************************************************
*
* Summary:
*  
* This function converts byte to two bytes 
*  
*
* Parameters:
*  firstindex,secondindex, index
*
* Return:
*  None
*
*******************************************************************************/
uint16 Uint8_to_Uint16Conversion(uint8 firstindex, uint8 lastindex){

    uint16 Hex2bytes;
    
    if(uint8to16conversionflag == 1){
         
        for(LoopCounterSerial = firstindex; LoopCounterSerial < lastindex;LoopCounterSerial++){
            
            Hex2bytes = auiuartrxarray[LoopCounterSerial]; 
            Hex2bytes = Hex2bytes << Shift_8_bits;
            LoopCounterSerial++;
            Hex2bytes |= auiuartrxarray[LoopCounterSerial];

        }
    } else if(uint8to16conversionflag == 2){
        
            for(LoopCounterSerial = firstindex; LoopCounterSerial < lastindex;LoopCounterSerial++){
            
            Hex2bytes = auimodbusrxarry[LoopCounterSerial]; 
            Hex2bytes = Hex2bytes << Shift_8_bits;
            LoopCounterSerial++;
            Hex2bytes |= auimodbusrxarry[LoopCounterSerial];

        }       
    }
    
   return Hex2bytes;
}
/*******************************************************************************
* Function Name: Modbus_Error_Response
********************************************************************************
*
* Summary:
*  
* This function processess the UART Error   
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Modbus_Error_Response(uint8 modbusarray[] , uint8 index){
    
    char Fucntioncodeerror;
    uint16 CRC;
    auiresponseerror [0] = DeviceID;
    
    if(Errorflag == FunctionCodeError){
      
        Fucntioncodeerror = modbusarray[index];
        Fucntioncodeerror = Fucntioncodeerror | 0x80;  
        auiresponseerror [1] = Fucntioncodeerror;
        auiresponseerror [2] = 01;
        CRC = CalculateCRC16(auiresponseerror,3);
        auiresponseerror [3] = CRC >> Shift_8_bits;
        auiresponseerror [4] = CRC;
        Modbusresponse_Generation(1);
        
    }else if(Errorflag == InvalidRegisterAdd){
        
        Fucntioncodeerror = modbusarray[index];
        Fucntioncodeerror = Fucntioncodeerror | 0x80;  
        auiresponseerror [1] = Fucntioncodeerror;
        auiresponseerror [2] = 02;
        CRC = CalculateCRC16(auiresponseerror,3);
        auiresponseerror [3] = CRC >> Shift_8_bits;
        auiresponseerror [4] = CRC;
        Modbusresponse_Generation(1);
        
    }    

}

/*******************************************************************************
* Function Name: Modbus_Single_Write
********************************************************************************
*
* Summary:
*  
* This function writes to array   
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Modbus_Single_Write(uint16 RegAdd, uint16 value){
    
    auigreenduration[(RegAdd-100)] = value; 
    EEPROMWriteFlag = 2;
    EEPROM_WriteFunction((RegAdd - 100));
    
    Modbus_Response( RegAdd ,Singlewriteflag);
//    Modbusresponse_Generation(3);
}

/*******************************************************************************
* Function Name: Modbus_Multiple_Write
********************************************************************************
*
* Summary:
*  
* This function writes to array   
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Modbus_Multiple_Write(){
    
    
    
}
/*******************************************************************************
* Function Name: Modbus_Response
********************************************************************************
*
* Summary:
*  
* This function generates the valid Modbus response   
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Modbus_Response(uint16 StartAddress, uint16 RegCount){
   
    uint8 LoopCounter1 = 0;
    uint8 LoopCounter2 = 0;
    uint16 RegisterAddress =(StartAddress - 100);
    uint8 index1 = 3;
    uint8 Responselenght = 0;
    uint16 CRC = 0;
    auiresposearray[0] = DeviceID;
    if(RegCount == Singlewriteflag){
        index1 = 1;
        EEPROM_Read(RegisterAddress , auigreenduration[RegisterAddress] );  
        auiresposearray[index1++] = SingleWrite;
        auiresposearray[index1++] = StartAddress >> Shift_8_bits;
        auiresposearray[index1++] = StartAddress;
        auiresposearray[index1++] = auigreenduration[RegisterAddress] >> Shift_8_bits;
        auiresposearray[index1++] = auigreenduration[RegisterAddress];
        
        Responselenght = 6;
        Bytecount = Responselenght;
        CRC = CalculateCRC16(auiresposearray ,Responselenght);
        auiresposearray[index1++] = CRC >> Shift_8_bits;   
        auiresposearray[index1++] = CRC;
        
   
        for(LoopCounter2 = (index1+1); LoopCounter2 < Responsesize; LoopCounter2 ++ ){
            
            auiresposearray[index1] = 0;
            index1++;
            auiresposearray[index1] = 0;
            index1++;  
        }
        
        Modbusresponse_Generation(3);
        
    }else if(RegCount == Multiplewriteflag){
        
        auiresposearray[1] = MultipleWrite;
        auiresposearray[2] = RegisterAddress;
    }else{
        EEPROM_Read(RegisterAddress , RegCount);
        
        auiresposearray[1] = FunctionCode;
        auiresposearray[2] = (RegCount*2);
        for(LoopCounter1 = RegisterAddress; LoopCounter1 <(RegisterAddress + RegCount); LoopCounter1++){
        
                   auiresposearray[index1] = auigreenduration[LoopCounter1] >> Shift_8_bits;
                   index1++;
                   auiresposearray[index1] = auigreenduration[LoopCounter1]; 
                   index1++;
        }
        Responselenght = ((RegCount*2) + 3);
        Bytecount = Responselenght;
        CRC = CalculateCRC16(auiresposearray ,Responselenght);
        auiresposearray[index1] = CRC >> Shift_8_bits;
        index1++;
        auiresposearray[index1] = CRC;
        index1++;
        
            for(LoopCounter2 =index1; LoopCounter2 < Responsesize; LoopCounter2 ++ ){
            
            
                
                auiresposearray[index1] = 0;
                index1++;
                auiresposearray[index1] = 0;
                index1++;  
            }
            
        Modbusresponse_Generation(2);
    }
    
}

/*******************************************************************************
* Function Name: Modbusresponse_Generation
********************************************************************************
*
* Summary:
*  
* This function generating response string  
*  
*
* Parameters:
*  fucntioncodeerror
*
* Return:
*  None
*
*******************************************************************************/
void Modbusresponse_Generation(uint8 Responseflag){
    uint16 LoopCounterSerial;
    uint8 index = 29;
    //for(LoopCounter =0; LoopCounter < 5; LoopCounter++){
        if(Responseflag == 1){
            Bytecount = 3;
            UART_TxDefault_Values();
            for(LoopCounterSerial = 0; LoopCounterSerial < ErrorRespArraySize; LoopCounterSerial++){
                
                ASCII_Conversion(auiresponseerror[LoopCounterSerial], index);
                index =index + 2;
                
            }     
            
        }else if((Responseflag == 2) || (Responseflag == 3)){
            
            UART_TxDefault_Values();
            for(LoopCounterSerial = 0; LoopCounterSerial < Responsesize; LoopCounterSerial++){
                
                ASCII_Conversion(auiresposearray[LoopCounterSerial], index);
                index =index + 2;
                
            }
            
        }
        
        if(Responseflag == 1){
            
            LoopCounterSerial = TxRespErrStartindex;
            
        }else if(Responseflag == 2){
            
            LoopCounterSerial = TxRespStartindex;
        }
        
        
        for( ; LoopCounterSerial < UART_TxBuffersize; LoopCounterSerial++){
            
                if(LoopCounterSerial == (UART_TxBuffersize - 1)){
                    
                    acuarttxbuffer[LoopCounterSerial] = '#';
                    //LoopCounterSerial++;
                }
                else{
                    
                    acuarttxbuffer[LoopCounterSerial] = '0';
                    
                }
        }
        
        UART_TxOperation(acuarttxbuffer,UART_TxBuffersize);

}

/*******************************************************************************
* Function Name: UART_TxDefault_Values
********************************************************************************
*
* Summary:
*  
* This function fills the default char to txbuffer array   
*  
*
* Parameters:
*  firstindex,secondindex, index
*
* Return:
*  None
*
*******************************************************************************/
void UART_TxDefault_Values(void){
    
    acuarttxbuffer[0] = '$';
    
    ASCII_Conversion( 0, 1);
    ASCII_Conversion( 1, 3);
    ASCII_Conversion( 3, 5);
    acuarttxbuffer[7] = ',';
    ASCII_Conversion( 1, 8);
    ASCII_Conversion( 4, 10);
    ASCII_Conversion( 0, 12);
    ASCII_Conversion( 1, 14);
    ASCII_Conversion( 0x2C, 16);
    ASCII_Conversion( 3, 18);
    ASCII_Conversion( 0, 20);
    ASCII_Conversion( 0, 22);
    ASCII_Conversion( 0, 24);
    acuarttxbuffer[26] = ',';
    ASCII_Conversion(Bytecount,27);

    
}

/*******************************************************************************
* Function Name: ASCII_Conversion
********************************************************************************
*
* Summary:
*  
* This function converts Hex to ASCII value  
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ASCII_Conversion(uint8 hexbytevalue, uint8 index){
    
    char CharecterValue[2];
    
    sprintf(CharecterValue,"%02X",(uint16)hexbytevalue);
    acuarttxbuffer[index] = CharecterValue[0];
    index++;
    acuarttxbuffer[index] = CharecterValue[1];

}

/*******************************************************************************
* Function Name: UART_TxOperation
********************************************************************************
*
* Summary:
*  
* This function put the array data into tx buffer     
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_TxOperation(char arraydata[] , uint16 size){
    
    uint16 loopcounter = 0;
     
    while((arraydata[loopcounter]!= (char) 0) & (loopcounter < size)){
        
        UART_PutChar((uint8 )arraydata[loopcounter]);
        loopcounter++;
        while(!(UART_ReadTxStatus() & UART_TX_STS_COMPLETE));
    }
    
    UART_ClearTxBuffer();
//    UART_PutArray( array , size);
//     CyDelay(1000);     
}

/*******************************************************************************
* Function Name: UART_RxOperation
********************************************************************************
*
* Summary:
*  
* This function receives the data and stores it into array  
*  
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

void UART_RxOperation(uint16 size){
        
        Bytecount = Startindex + size ;
        for(LoopCounterSerial = Startindex ; LoopCounterSerial < Bytecount; LoopCounterSerial++){
                
            acuartrxbuffer[LoopCounterSerial] = UART_ReadRxData();
            
        }
        Startindex = Bytecount;
        Uint8_to_Uint16Conversion( Startindex , Bytecount);
    
}

/*****************************************************************************
*** Modbus CRC calculation as per specification given in MODBUS.ORG
*** Uses table for polynomial 1010 0000 0000 0001 = 0xA0001
*** Can be used for string received or string to be transmitted
*** MsgStartAddr - Starting address of the message
*** MsgLength    - Length of the message (excluding CRC)
*** Returns a 16 bit CRC value
*****************************************************************************/

uint16 CalculateCRC16(uint8 *MsgStartAddr, uint8 MsgLength){
    uint16 ui16Response=0;
    uint8 index;
	
    uint8 CRCtmpHi = 0xFF;                      // Initialize CRC register to 0xFFFF
    uint8 CRCtmpLo = 0xFF;

    while(MsgLength--)                                  // Find CRC for each byte of the string
    {
        index = CRCtmpLo ^ *MsgStartAddr++;
        CRCtmpLo = CRCtmpHi ^ TabCRCHi[index];
        CRCtmpHi = TabCRCLo[index];
    }
	
    ui16Response = CRCtmpLo;
    ui16Response = ui16Response << 8;
    ui16Response = ui16Response | CRCtmpHi;
    CRC.Byte.Hi = CRCtmpHi;                             // Update the CRC registers
    CRC.Byte.Lo = CRCtmpLo;
    
    return ui16Response;
}


/*******************************************************************************
* Function Name: Check_For_Proper_Response
********************************************************************************
*
* Summary:
*  
* This function checks for $ at the first index of rx buffer, if it is not present 
* clears the buffer 
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Check_For_Proper_Response(void){
    if(UART_GetRxBufferSize()){
        if(UART_rxBuffer[0] != '$'){
            UART_ClearRxBuffer();
        }
    }
}
/* [] END OF FILE */
