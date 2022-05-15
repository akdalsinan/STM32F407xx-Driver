#ifndef SRC_RCC_C_
#define SRC_RCC_C_

#include "RCC.h"

/*
 *
 * RCC->CFGR registerin HPRE biti(7,4);
 *
 * 0xxx: system clock not divided
 * 1000: system clock divided by 2		dizinin 8. elemanı
 * 1001: system clock divided by 4		dizinin 9. elemanı
 * 1010: system clock divided by 8		dizinin 10. elemanı
 * 1011: system clock divided by 16		dizinin 11. elemanı
 * 1100: system clock divided by 64		dizinin 12. elemanı
 * 1101: system clock divided by 128	dizinin 13. elemanı
 * 1110: system clock divided by 256	dizinin 14. elemanı
 * 1111: system clock divided by 512	dizinin 15. elemanı
 *
 */
const uint8_t AHB_Prescaler[ ]={0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

/*
 *
 *
 *
 * 0xx: AHB clock not divided
 * 100: AHB clock divided by 2		dizinin 4. elemanı
 * 101: AHB clock divided by 4		dizinin 5. elemanı
 * 110: AHB clock divided by 8		dizinin 6. elemanı
 * 111: AHB clock divided by 16		dizinin 7. elemanı
 *
 */
const uint8_t APB_Prescaler[ ]={0, 0, 0, 0, 1, 2, 3, 4};


/*
 *
 *
 *
 *
 * hangi clock kullanıldığını anlamak için bu fanksiyon yazılmıştır.
 *
 * RCC->CFGR registerin SWS biti(3,2);
 *
 *00--> HSI oscilator used as the system clock
 *01--> HSE oscilator used as the system clock
 *10--> PLL used as the system clock
 *11--> Not applicable
 *
 */
uint32_t RCC_GetSystemClock(void)
{
	uint32_t SystemCoreClock=0;
	uint8_t clockSource=0;
	clockSource= ((RCC->CFGR >> 2U) & 0x3U );

	switch(clockSource)
	{
	case 0  : SystemCoreClock= 16000000; break; //HSI oscilator used as the system clock (16 Mhz)
	case 1  : SystemCoreClock=  8000000; break; //HSE oscilator used as the system clock (8 Mhz)
	default : SystemCoreClock= 16000000;
	}

	return SystemCoreClock;
}


uint32_t RCC_GetHClock(void)
{
	uint32_t AHB_PeriphClock=0;
	uint32_t SystemCoreClock=0;
	uint8_t HPRE_Value=0;
	uint8_t tempValue=0;

	SystemCoreClock=RCC_GetSystemClock();
	HPRE_Value= ((RCC->CFGR >> 4U)& 0xFU);
	tempValue=AHB_Prescaler[HPRE_Value];
	AHB_PeriphClock=(SystemCoreClock >> tempValue);  //bölme işlemi burada gerçekleşir

	return AHB_PeriphClock;
}


/*
 * RCC->CFGR registerin HPRE biti(12,10)
 */
uint32_t RCC_GetAPB1Clock(void)
{
	uint32_t APB1_PeriphClock=0;
	uint32_t HClock=0;
	uint8_t HPRE1_Value=0;
	uint8_t tempValue=0;

	HClock= RCC_GetHClock();
	HPRE1_Value= ((RCC->CFGR >> 10U ) & 0x7U);
	tempValue= APB_Prescaler[HPRE1_Value];
	APB1_PeriphClock = (HClock >> tempValue);

	return APB1_PeriphClock;
}

/*
 * RCC->CFGR registerin HPRE biti(15,13)
 */
uint32_t RCC_GetAPB2Clock(void)
{
	uint32_t APB2_PeriphClock=0;
	uint32_t HClock=0;
	uint8_t  HPRE2_Value=0;
	uint8_t  tempValue=0;

	HClock= RCC_GetHClock();
	HPRE2_Value= ((RCC->CFGR >> 13U ) & 0x7U);
	tempValue= APB_Prescaler[HPRE2_Value];
	APB2_PeriphClock = (HClock >> tempValue);

	return APB2_PeriphClock;
}

#endif /* SRC_RCC_C_ */
