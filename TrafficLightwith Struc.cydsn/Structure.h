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
#ifndef STRUCTURE_H
#define STRUCTURE_H
    
#define RED    1
#define AMBER  2
#define GREEN  4

#define RED_DURATION     39
#define AMBER_DURATION   03
#define GREEN_DURATION   10
    
typedef struct tDefTLSide1Values{
     uint8 FCount;
     uint8 CurrentState;
     uint8 NextState;
    
}tDefTLSide1Values;

typedef struct tDefTLSide2Values{
     uint8 RCount;
     uint8 CurrentState;
     uint8 NextState;
    
}tDefTLSide2Values;

typedef struct tDefTLSide3Values{
     uint8 DCount;
     uint8 CurrentState;
     uint8 NextState;
    
}tDefTLSide3Values;

typedef struct tDefTLSide4Values{
     uint8 LCount;
     uint8 CurrentState;
     uint8 NextState;
    
}tDefTLSide4Values;

    /*Define your macro callbacks here */
    /*For more information, refer to the Writing Code topic in the PSoC Creator Help.*/

    
#endif /* STRUCTURE_H */   

/* [] END OF FILE */
