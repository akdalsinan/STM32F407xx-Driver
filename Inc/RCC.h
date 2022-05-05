#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f407xx.h"

/*
 *  RCC AHB1 peripherals clock control macro definition
 *  AHB1 hattı için clock hatlarını kontrol ettiğimiz makro tanımlamaları
 */
#define RCC_GPIOA_CLK_ENABLE()			do{ uint32_t tempvalue=0;	\
											SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);	\
											tempvalue=READ_BITS(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);\
											UNUSED(tempvalue); 	\
										  }while(0)

#define RCC_GPIOA_CLK_DISABLE			CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN)

#define RCC_GPIOB_CLK_ENABLE()			do{ uint32_t tempValue=0;	\
											SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
											tempValue=READ_BITS(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);\
											UNUSED(tempValue);\
        								   }while(0)

#define RCC_GPIOB_CLK_DISABLE			CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN)

#define RCC_GPIOC_CLK_ENABLE()			do{ uint32_t tempValue=0;	\
											SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
											tempValue=READ_BITS(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);\
											UNUSED(tempValue);\
        								   }while(0)
#define RCC_GPIOC_CLK_DISABLE			CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN)

#define RCC_GPIOD_CLK_ENABLE()			do{ uint32_t tempValue=0;	\
											SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
											tempValue=READ_BITS(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);\
											UNUSED(tempValue);\
        								   }while(0)

#define RCC_GPIOD_CLK_DISABLE			CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN)

/*
 *  RCC APB2 peripherals clock control macro definition
 *  APB2 hattı için clock hatlarını kontrol ettiğimiz makro tanımlamaları
 */

#define RCC_SYSCFG_CLK_ENABLE()			do{ uint32_t tempValue=0;	\
											SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFG);\
											tempValue=READ_BITS(RCC->APB2ENR,RCC_APB2ENR_SYSCFG);\
											UNUSED(tempValue);\
        								   }while(0)

#define RCC_SPI1_CLK_ENABLE()			do{ uint32_t tempValue=0;	\
											SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1);\
											tempValue=READ_BITS(RCC->APB2ENR,RCC_APB2ENR_SPI1);\
											UNUSED(tempValue);\
        								   }while(0)
#define RCC_SP1_CLK_DISABLE			CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1)

/*
 *  RCC APB1 peripherals clock control macro definition
 *  APB1 hattı için clock hatlarını kontrol ettiğimiz makro tanımlamaları
 */

#define RCC_SPI2_CLK_ENABLE()			do{ uint32_t tempValue=0;	\
											SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2);\
											tempValue=READ_BITS(RCC->APB1ENR,RCC_APB1ENR_SPI2);\
											UNUSED(tempValue);\
        								   }while(0)

#define RCC_SP2_CLK_DISABLE			CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2)









#endif /* INC_RCC_H_ */
