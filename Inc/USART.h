
#ifndef INC_USART_H_
#define INC_USART_H_

#include "stm32f407xx.h"

#define __USART_DIV_8(__pClock,__BaudRate)					(25U * (uint32_t)(__pClock)) / (uint32_t) (4U *(__BaudRate))
#define __USART_DIV_16(__pClock,__BaudRate)					(25U * (uint32_t)(__pClock)) / (uint32_t) (2U *(__BaudRate))

/*
 * @def_group_mode_types
 */
#define USART_MODE_Tx								((uint32_t)(0x00000008)) 	//CR1 Register--> 3. bit=1
#define USART_MODE_Rx								((uint32_t)(0x00000004)) 	//CR1 Register--> 2. bit=1
#define USART_MODE_Tx_Rx							((uint32_t)(0x0000000C))	//CR1 Register--> 2 ve 3. bit=1

/*
 * @def_group_WordLength_types
 */
#define USART_WORDLENGTH_8Bits						((uint32_t)(0x00000000)) 	//CR1 Register--> 12. bit=0
#define USART_WORDLENGTH_9Bits						((uint32_t)(0x00001000)) 	//CR1 Register--> 12. bit=1

/*
 * @def_group_parity_modes
 */
#define USART_PARİTY_NONE							((uint32_t)(0x00000000))
#define USART_PARİTY_EVEN							((uint32_t)(0x00000400))	//CR1 Register--> 10. bit=1
#define USART_PARİTY_Odd							((uint32_t)(0x00000600))	//CR1 Register--> 10 ve 9. bit=1

/*
 * @def_group_stop_bits
 */
#define USART_STOPBITS_1							((uint32_t)(0x00000000))	//(1)   CR2 Register--> 12 ve 13. bit=0
#define USART_STOPBITS_Half							((uint32_t)(0x00001000))	//(0.5) CR2 Register--> 12.bit=1, 13. bit=0
#define USART_STOPBITS_2							((uint32_t)(0x00002000))	//(2)   CR2 Register--> 12.bit=0, 13. bit=1
#define USART_STOPBITS_1_Half						((uint32_t)(0x00003000))	//(1.5) CR2 Register--> 12 ve 13. bit=1

/*
 * @def_group_oversampling_modes
 */
#define USART_OVERSAMPLE_16							((uint32_t)(0x00000000))	//CR1 register-->15.bit=0
#define USART_OVERSAMPLE_8							((uint32_t)(0x00008000))	//CR1 register-->15.bit=1

/*
 * @def_group_HardWareFlowControl_modes
 */
#define USART_HW_NONE								((uint32_t)(0x00000000))	//CR3 register-->
#define USART_HW_CTS								((uint32_t)(0x00000200))	//CR3 register--> 9.bit=1
#define USART_HW_RTS								((uint32_t)(0x00000100))	//CR3 register--> 8.bit=1
#define USART_HW_CTS_RTS							((uint32_t)(0x00000300))	//CR3 register--> 8 ve 9. bit=1

typedef struct
{
	uint32_t OverSampling;   				//over sampling modes				@def_group_oversampling_modes
	uint32_t BaudRate;
	uint32_t WordLength;					//8 bits & 9 bits 					@def_group_WordLength_types
	uint32_t Parity;						//even and Odd parity 				@def_group_parity_modes
	uint32_t StopBits;						//Stop bits modes				 	@def_group_stop_bits
	uint32_t HardWareFlowControl;			//Hard Ware Flow Control modes		@def_group_HardWareFlowControl_modes
	uint32_t Mode;					 		//transmission and reception mode 	@def_group_mode_types

}USART_InitTypedef_t;


typedef struct
{
	USART_Typedef_t * Instance;
	USART_InitTypedef_t Init;



}USART_HandleTypedef_t;

void USART_Init(USART_HandleTypedef_t *USART_Handle);     //CR1,CR2,CR3

void USART_PeriphCMD(USART_HandleTypedef_t *USART_Handle,FunctionalState_t stateOfUSART);

void USART_TransmitData (USART_HandleTypedef_t *USART_Handle,uint8_t *pData, uint16_t sizeOfData );




#endif /* INC_USART_H_ */
