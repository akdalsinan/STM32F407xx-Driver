
#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f407xx.h"


/*
 *@def_group PORT_Values
 */
#define EXTI_PortSource_GPIOA			((uint8_t)(0x0)) //0000 0000
#define EXTI_PortSource_GPIOB			((uint8_t)(0x1)) //0000 0001
#define EXTI_PortSource_GPIOC			((uint8_t)(0x2)) //0000 0010
#define EXTI_PortSource_GPIOD			((uint8_t)(0x3)) //0000 0011
#define EXTI_PortSource_GPIOE			((uint8_t)(0x4)) //0000 0100
#define EXTI_PortSource_GPIOF			((uint8_t)(0x5)) //0000 0101
#define EXTI_PortSource_GPIOG			((uint8_t)(0x6)) //0000 0110
#define EXTI_PortSource_GPIOH			((uint8_t)(0x7)) //0000 0111

/*
 * @def_group LINE_Values
 */
#define EXTI_LineSource_0				((unit8_t)(0x0))
#define EXTI_LineSource_1				((unit8_t)(0x1))
#define EXTI_LineSource_2				((unit8_t)(0x2))
#define EXTI_LineSource_3				((unit8_t)(0x3))
#define EXTI_LineSource_4				((unit8_t)(0x4))
#define EXTI_LineSource_5				((unit8_t)(0x5))
#define EXTI_LineSource_6				((unit8_t)(0x6))
#define EXTI_LineSource_7				((unit8_t)(0x7))
#define EXTI_LineSource_8				((unit8_t)(0x8))
#define EXTI_LineSource_9				((unit8_t)(0x9))
#define EXTI_LineSource_10				((unit8_t)(0xA))
#define EXTI_LineSource_11				((unit8_t)(0xB))
#define EXTI_LineSource_12				((unit8_t)(0xC))
#define EXTI_LineSource_13				((unit8_t)(0xD))
#define EXTI_LineSource_14				((unit8_t)(0xE))
#define EXTI_LineSource_15				((unit8_t)(0xF))

/*
 * @def_group EXTI_Modes
 */
#define EXTI_MODE_Interrupt			(0x00U)
#define EXTI_MODE_Event 			(0x04U)

/*
 * @def_group trigger_modes
 */
#define EXTI_Trigger_Rising			(0x08U)
#define EXTI_Trigger_Falling		(0x0CU)
#define EXTI_Trigger_RF				(0x10U)

typedef struct{

	uint8_t EXTI_LineNumber;           //hangi hattan interrupt olacak?
	uint8_t TriggerSelection;		   //düsen kenar mı yükselen kenar mı?		@def_group trigger_modes
	uint8_t EXTI_Mode;				   //event mı interrupt mı? 				@def_group EXTI_Modes
	FunctionalState_t EXTI_LineCmd;	   //o hattı enable mi disable mi yapmak istiyorsun?

}EXTI_InitypeDef_t;

void EXTI_Init(EXTI_InitypeDef_t* EXTI_InitStruct);
void EXTI_LineConfig(uint8_t PortSource,uint8_t EXTI_LineSource);//port bilgisini(GPIOA-B-C-D..-I) ve pin numarasını(0-15) alır.
																//İnterrupt'ın nereden hangi port ve biitten geleceğini burada belirleriz
void NVIC_EnableInterrupt(IRQNumber_Typedef_t IRQNumber); //uygun register üzerinde gezerek IRQ numarasına göre konfig. yapılacak










#endif /* INC_EXTI_H_ */
