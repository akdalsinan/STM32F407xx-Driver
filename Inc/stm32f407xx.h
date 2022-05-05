
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * Mıcroprocessor Defines (ARM Cortex M4 makro tanımlamaları)
 */
#define NVIC_ISER0				((uint32_t*)(0XE000E100UL)) //adresiyle tanımlanması ileride islem yaparken kolaylık saglamsaı icin yapıldı.




#define __IO volatile


#define SET_BIT(REG,BIT)		((REG) |= (BIT))  //uygun register'a uygun biti yaz
#define CLEAR_BIT(REG,BIT)		((REG) &=~ (BIT))
#define READ_BITS(REG,BIT)		((BIT) & (REG))

typedef enum{
	DISABLE=0X0U,
	ENABLE=!DISABLE
}FunctionalState_t;


/*
 * IRQ Numbers of MCU=Vector table
 * reference manuel--> interrupt events
 * 81 Adet interrupt IRQ numarası var hepsi tanımlanmadı, ihityaca göre tanımalamalar yapılır.
 */
typedef enum{

	EXTI0_IRQNumber=6,
	EXTI1_IRQNumber=7,
	EXTI2_IRQNumber=8,
	EXTI3_IRQNumber=9,


}IRQNumber_Typedef_t;





#define UNUSED(x)				(void)x
/*
 * Memory Base Address(memory adreslerin tanimlanmasi)
 */
#define FLASH_BASE_ADDR			(0x08000000UL) //Flash Base Address (1MB)
#define SRAM1_BASE_ADDR			(0X20000000UL) //SRAM1 Base Address (112KB)
#define SRAM2_BASE_ADDR			(0X2001C000UL)  //SRAM2 Base Address (16 KB)(SRAM2=SRAM1+(112*114688)=2001 C000)

/*
 * Peripheral Base Address(Cevresel birim adresleri)
 */
#define PERİPH_BASE_ADDR		(0x40000000UL) //Base addre for all peripherals(Çevresel birimlerin başladığı base adres)
#define APB1_BASE_ADDR			(PERİPH_BASE_ADDR)
#define APB2_BASE_ADDR			(PERİPH_BASE_ADDR+00010000UL)
#define AHB1_BASE_ADDR			(0x40020000UL)
#define AHB2_BASE_ADDR			(0x50000000UL)

/*
 * APB1 Peripherals Base Addresses
 */

#define TIM2_BASE_ADDR			(APB1_BASE_ADDR)			//Tımer2 Base Address
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR+0X0400UL)	//Tımer3 Base Address
#define TIM4_BASE_ADDR			(APB1_BASE_ADDR+0X0800UL)	//Tımer4 Base Address
#define TIM5_BASE_ADDR			(APB1_BASE_ADDR+0X0C00UL)	//Tımer5 Base Address
#define TIM6_BASE_ADDR			(APB1_BASE_ADDR+0X1000UL)	//Tımer6 Base Address
#define TIM7_BASE_ADDR			(APB1_BASE_ADDR+0X1400UL)	//Tımer7 Base Address
#define SPI2_BASE_ADDR			(APB1_BASE_ADDR+0x3800UL)	//SPI2 Base Address
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR+0x3C00UL)	//SPI3 Base Address
#define USART2_BASE_ADDR		(APB1_BASE_ADDR+0x4400UL)	//USART Base Address

/*
 * APB2 Peripherals Base Addresses
 */

#define SYSCFG_BASE_ADDR		(APB2_BASE_ADDR + 0X3800UL)
#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0X3C00UL)
#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0X3000UL)
#define SPI4_BASE_ADDR			(APB2_BASE_ADDR + 0X3400UL)

/*
 * AHB1 Peripherals Base Addresses
 */
#define GPIOA_BASE_ADDR		(AHB1_BASE_ADDR+0x0000UL)	//GPIOA Base Address
#define GPIOB_BASE_ADDR		(AHB1_BASE_ADDR+0x4000UL)	//GPIOB Base Address
#define GPIOC_BASE_ADDR		(AHB1_BASE_ADDR+0x8000UL)	//GPIOC Base Address
#define GPIOD_BASE_ADDR		(0x40020C00)				//GPIOD Base Address
#define RCC_BASE_ADDR		(AHB1_BASE_ADDR+0x3800UL)	//RCC Base Address

/*
 * Peripherals Structure Definitions
 */

typedef struct
{
	volatile uint32_t MODER;    //GPIO port mode register					Address Offset=0x0000
	volatile uint32_t OTYPER;	//GPIO port output type register			Address Offset=0x0004
	volatile uint32_t OSPEEDR;	//GPIO port output speed register			Address Offset=0x0008
	volatile uint32_t PUPDR;	//GPIO port pull up/pull down register		Address Offset=0x000C
	volatile uint32_t IDR;		//GPIO port input data register				Address Offset=0x0010
	volatile uint32_t ODR;		//GPIO port output data register     		Address Offset=0x0014
	__IO uint32_t BSRR;			//GPIO port bit set/reset register  		Address Offset=0x0018
	__IO uint32_t LCKR;			//GPIO port configuration lock register		Address Offset=0x001C
	__IO uint32_t AFR[2];		//GPIO port alternate function register		Address Offset=0x0020

}GPIO_Typedef_t;


typedef struct {
	__IO uint32_t RC;           //
	__IO uint32_t PLLCFGR;		//
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	__IO uint32_t AHB3RSTR;
	__IO uint32_t RESERVED0;
	__IO uint32_t APB1RSTR;
	__IO uint32_t APB2RSTR;
	__IO uint32_t RESERVED1[2];
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
	__IO uint32_t AHB3ENR;
	__IO uint32_t RESERVED2;
	__IO uint32_t APB1ENR;
	__IO uint32_t APB2ENR;
	__IO uint32_t RESERVED3[2];
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
	__IO uint32_t AHB3LPENR;
	__IO uint32_t RESERVED4;
	__IO uint32_t APB1LPENR;
	__IO uint32_t APB2LPENR;
	__IO uint32_t RESERVED5[2];
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	__IO uint32_t RESERVED6[2];
	__IO uint32_t SSCGR;
	__IO uint32_t PLLI2SCFGR;

}RCC_Typedef_t;


typedef struct{
	__IO uint32_t MEMRMP;		// SYSCFG memory remap register						Address Offset=0x00
	__IO uint32_t PMC;			// SYSCFG peripheral mode config. register			Address Offset=0x04
	__IO uint32_t EXTI_CR[4];	//SYSCFG external interrup config. register			Address Offset=0x08
	__IO uint32_t CMPCR;		//compesation cell control register        			Address Offset=0x20

}SYSCFG_Typedef_t;


typedef struct{
	__IO uint32_t IMR;			//EXTI Interrupt mask register					 Address Offset=0x00
	__IO uint32_t EMR;			//EXTI Event mask register 						 Address Offset=0x04
	__IO uint32_t RTSR;			//EXTI Rising trigger selection register 		 Address Offset=0x08
	__IO uint32_t FTSR;			//EXTI Falling trigger selection register		 Address Offset=0x0C
	__IO uint32_t SWIER;		//EXTI Software interrupt event register		 Address Offset=0x10
	__IO uint32_t PR;			//EXTI Pending register							 Address Offset=0x14

}EXTI_Typedef_t;


typedef struct{
	__IO uint32_t CR1;			//SPI control register 1 						 Address Offset=0x00
	__IO uint32_t CR2;			//SPI control register 2  						 Address Offset=0x04
	__IO uint32_t SR;			//SPI status register							 Address Offset=0x08
	__IO uint32_t DR;			//SPI data register								 Address Offset=0x0C
	__IO uint32_t CRCPR;		//SPI CRC polynomial register 					 Address Offset=0x10
	__IO uint32_t RXCRCR;		//SPI RX CRC register							 Address Offset=0x14
	__IO uint32_t TXCRCR;		//SPI TX CRC register	 						 Address Offset=0x18
	__IO uint32_t I2SCFGR;		//SPI_I2S configuration registe					 Address Offset=0x1C
	__IO uint32_t I2SPR;		//SPI_I2S prescaler register					 Address Offset=0x20

}SPI_Typedef_t;







/*
 * Base Addresses Definitions of Port
 * her port için bir adres yapisi olusturuldu.
 */

#define GPIOA							((GPIO_Typedef_t *)   (GPIOA_BASE_ADDR)  )
#define GPIOB							((GPIO_Typedef_t *)   (GPIOB_BASE_ADDR)  )
#define GPIOC							((GPIO_Typedef_t *)   (GPIOC_BASE_ADDR)  )
#define GPIOD							((GPIO_Typedef_t *)   (GPIOD_BASE_ADDR)  )
#define RCC								((RCC_Typedef_t *)    (RCC_BASE_ADDR)    )
#define SYSCFG							((SYSCFG_Typedef_t*)  (SYSCFG_BASE_ADDR) )
#define EXTI 							((EXTI_Typedef_t*)    (EXTI_BASE_ADDR)	 )
#define SPI1							((SPI_Typedef_t*)     (SPI1_BASE_ADDR)	 )
#define SPI2							((SPI_Typedef_t*)     (SPI2_BASE_ADDR)	 )
#define SPI3							((SPI_Typedef_t*)     (SPI3_BASE_ADDR)	 )
#define SPI4							((SPI_Typedef_t*)     (SPI4_BASE_ADDR)	 )

/*
 * maskeleme mantığı ile RCC header file dosyasındaki kullanacağımız veri yolunu aktif edeceğiz
 * Bit Definition
 */

#define RCC_AHB1ENR_GPIOAEN_Pos			(0U)      //AHB1ENR register'ında GPIOA biti ilk bit oldugu icin pozisyonu 0x0u oldu
#define RCC_AHB1ENR_GPIOAEN_Msk			(0x1 << RCC_AHB1ENR_GPIOAEN_Pos) //maskeleme icin GPIOA pozisyonu kadar git ve 1 yaz
#define RCC_AHB1ENR_GPIOAEN             RCC_AHB1ENR_GPIOAEN_Msk //yani bu işlem ile (0x1 << 0) yapmış oluruz. sıfırıncı biti 1 yap

#define RCC_AHB1ENR_GPIOBEN_Pos			(1U)							 //RCC AHB1ENR register GPIOBEN bit position
#define RCC_AHB1ENR_GPIOBEN_Msk			(0x1 << RCC_AHB1ENR_GPIOBEN_Pos) //RCC AHB1ENR register GPIOBEN bit Mask
#define RCC_AHB1ENR_GPIOBEN				RCC_AHB1ENR_GPIOBEN_Msk			 //RCC AHB1ENR register GPIOBEN macro

#define RCC_AHB1ENR_GPIOCEN_Pos			(2U)							//RCC AHB1ENR register GPIOCEN bit position
#define RCC_AHB1ENR_GPIOCEN_Msk			(0x1 << RCC_AHB1ENR_GPIOCEN_Pos)
#define RCC_AHB1ENR_GPIOCEN				RCC_AHB1ENR_GPIOCEN_Msk

#define RCC_AHB1ENR_GPIODEN_Pos			(3U)							//RCC AHB1ENR register GPIODEN bit position
#define RCC_AHB1ENR_GPIODEN_Msk			(0x1 << RCC_AHB1ENR_GPIODEN_Pos)
#define RCC_AHB1ENR_GPIODEN				RCC_AHB1ENR_GPIODEN_Msk

#define RCC_APB2ENR_SYSCFG_Pos			(14U)
#define RCC_APB2ENR_SYSCFG_Msk			(0x1 << RCC_APB2ENR_SYSCFG_Pos)
#define RCC_APB2ENR_SYSCFG				RCC_APB2ENR_SYSCFG_Msk

#define RCC_APB2ENR_SPI1_Pos			(12U)
#define RCC_APB2ENR_SPI1_Msk			(0x1 << RCC_APB2ENR_SPI1_Pos)
#define RCC_APB2ENR_SPI1				RCC_APB2ENR_SPI1_Msk

#define RCC_APB1ENR_SPI2_Pos			(14U)
#define RCC_APB1ENR_SPI2_Msk			(0x1 << RCC_APB1ENR_SPI2_Pos)
#define RCC_APB1ENR_SPI2				RCC_APB1ENR_SPI2_Msk

#define SPI_C1_SPE						(6U)

#include "RCC.h" //
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"

#endif /* INC_STM32F407XX_H_ */
