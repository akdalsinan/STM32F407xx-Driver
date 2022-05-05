

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f407xx.h"

/*
 * @def_group GPIO_Pins
 */
#define GPIO_PIN_0			(uint16_t)(0x0001) // 0000 0000 0000 0001 //gpio pin 1 selected
#define GPIO_PIN_1			(uint16_t)(0x0002) // 0000 0000 0000 0010
#define GPIO_PIN_2			(uint16_t)(0x0004) // 0000 0000 0000 0100
#define GPIO_PIN_3			(uint16_t)(0x0008) // 0000 0000 0000 1000
#define GPIO_PIN_4			(uint16_t)(0x0010) // 0000 0000 0001 0000
#define GPIO_PIN_5			(uint16_t)(0x0020) // 0000 0000 0010 0000
#define GPIO_PIN_6			(uint16_t)(0x0040) // 0000 0000 0100 0000
#define GPIO_PIN_7			(uint16_t)(0x0080) // 0000 0000 1000 0000
#define GPIO_PIN_8			(uint16_t)(0x0100) // 0000 0001 0000 0000
#define GPIO_PIN_9			(uint16_t)(0x0200) // 0000 0010 0000 0000
#define GPIO_PIN_10			(uint16_t)(0x0400) // 0000 0100 0000 0000
#define GPIO_PIN_11			(uint16_t)(0x0800) // 0000 1000 0000 0000
#define GPIO_PIN_12			(uint16_t)(0x1000) // 0001 0000 0000 0000
#define GPIO_PIN_13			(uint16_t)(0x2000) // 0010 0000 0000 0000
#define GPIO_PIN_14			(uint16_t)(0x4000) // 0100 0000 0000 0000
#define GPIO_PIN_15			(uint16_t)(0x8000) // 1000 0000 0000 0000
#define GPIO_PIN_ALL		(uint16_t)(0xFFFF) // 1111 1111 1111 1111

/*
 * @def_group GPIO_Pin_Modes
 * MODER register(32bıt) ıcın tanımlanmıstır.
 */
#define GPIO_MODE_INPUT			(0X0U) //00: Input (reset state)
#define GPIO_MODE_OUTPUT			(0X1U) //01: General purpose output mode
#define GPIO_MODE_AF			(0X2U) //10: Alternate function mode
#define GPIO_MODE_ANALOG		(0X3U) //11: Analog mode

/*
 * @def_group GPIO_OUTYPE_Modes
 * OTYPER register(32bıt) ıcın tanımlanmıstır.
 */
#define GPIO_OTYPE_PP			(0X0U) //0: Output push-pull (reset state)
#define GPIO_OTYPE_OD			(0X1U) //1: Output open-drain

/*
 * @def_group GPIO_SPEED_Modes
 * SPEED register(32bıt) ıcın tanımlanmıstır.
 */
#define GPIO_SPEED_LOW			(0X0U) //00: Low speed
#define GPIO_SPEED_MEDIUM		(0X1U) //01: Medium speed
#define GPIO_SPEED_HIGH			(0X2U) //10: High speed
#define GPIO_SPEED_VERYHIGH		(0X3U) //11: Very high speed

/*
 * @def_group GPIO_PuPd_Modes
 * pull-up/pull-down register(32bıt) ıcın tanımlanmıstır.
 */
#define GPIO_PUPD_NOPULL			(0X0U) //00: No pull-up, pull-down
#define GPIO_PUPD_PULLUP			(0X1U) //01: Pull-up
#define GPIO_PUPD_PULLDOWN		    (0X2U) //10: Pull-down

/*
 * GPIO_AF_Modes
 */
#define GPIO_AF0					(0x0U)
#define GPIO_AF1					(0x1U)
#define GPIO_AF2					(0x2U)
#define GPIO_AF3					(0x3U)
#define GPIO_AF4					(0x4U)
#define GPIO_AF5					(0x5U)
#define GPIO_AF6					(0x6U)
#define GPIO_AF7					(0x7U)
#define GPIO_AF8					(0x8U)
#define GPIO_AF9					(0x9U)
#define GPIO_AF10					(0xAU)
#define GPIO_AF11					(0xBU)
#define GPIO_AF12					(0xCU)
#define GPIO_AF13					(0xDU)
#define GPIO_AF14					(0xEU)
#define GPIO_AF15					(0xFU)



typedef enum
{

	GPIO_Pin_Reset = 0x0U,
	GPIO_Pin_Set = !GPIO_Pin_Reset

}GPIO_PinState_t;

typedef struct {
	uint32_t pinNumber;	 	// GPIO pin numbers @def_group GPIO_Pins
	uint32_t Mode;			// @def_group GPIO_Pin_Modes
	uint32_t Otype;     	// @def_group GPIO_OUTYPE_Modes
	uint32_t Pupd;			// @def_group GPIO_PuPd_Modes
	uint32_t Speed;			// @def_group GPIO_SPEED_Modes
	uint32_t Alternate; 	// @def_group GPIO_AF_Modes
}GPIO_InitTypeDef_t;



void GPIO_Init(GPIO_Typedef_t *GPIOx, GPIO_InitTypeDef_t * GPIO_ConfigStruct);			  // Function declaration
void GPIO_WritePin(GPIO_Typedef_t * GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState); // Function declaration
GPIO_PinState_t GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber);				  // Function declaration






#endif /* INC_GPIO_H_ */
