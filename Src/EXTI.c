
#include "EXTI.h"

/*
 * @brief EXTI_Init
 *
 * @param PortSource=port value A-I @def_group PORT_Values
 * @param EXTI_LineSource= Pin numbers & Line numbers @def_group LINE_Values
 *
 * @retval void
 */

void EXTI_Init(EXTI_InitypeDef_t* EXTI_InitStruct){

	uint32_t tempValue=0;
	tempValue=(uint32_t)EXTI_BASE_ADDR;
	EXTI->IMR &=~ (0X1U << EXTI_InitStruct->EXTI_LineNumber); // IMR clear etme
	EXTI->EMR &=~ (0X1U << EXTI_InitStruct->EXTI_LineNumber); // EMR clear etme

	if(EXTI_InitStruct-> EXTI_LineCmd != DISABLE)
	{
		tempValue += EXTI_InitStruct->EXTI_Mode;
		*((__IO uint32_t*)tempValue) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue=(uint32_t)EXTI_BASE_ADDR;
		EXTI->RTSR &=~ (0X1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR &=~ (0X1U << EXTI_InitStruct->EXTI_LineNumber);
		if (EXTI_InitStruct->TriggerSelection == EXTI_Trigger_RF) //Rising ve falling ikisi de aktif mi?
		{
			EXTI->RTSR |= (0X1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (0X1U << EXTI_InitStruct->EXTI_LineNumber);
		}
		else
		{
			tempValue += EXTI_InitStruct->TriggerSelection;
			*((__IO uint32_t*)tempValue) |=(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}

	}
	else
	{
		tempValue=(uint32_t)EXTI_BASE_ADDR;
		tempValue += EXTI_InitStruct->EXTI_Mode;
		*((__IO uint32_t*)tempValue) &=~ (0x1U << EXTI_InitStruct->EXTI_LineNumber);
	}


}


/*
 * @brief SYSCFG için ilgli portu konfigre eder
 *
 * @param PortSource=port value A-I @def_group PORT_Values
 * @param EXTI_LineSource= Pin numbers & Line numbers @def_group LINE_Values
 *
 * @retval void
 */
void EXTI_LineConfig(uint8_t PortSource,uint8_t EXTI_LineSource)
{
	uint32_t tempValue;
	tempValue= SYSCFG->EXTI_CR[EXTI_LineSource >> 2U]; //4'e bölme islemi yapıldı
	tempValue &=~ (0XFU << (EXTI_LineSource & 0X3U)*4); //4'e göre mod alma isemi yapıldı
	tempValue =(PortSource << (EXTI_LineSource & 0X3U)*4);
	SYSCFG->EXTI_CR[EXTI_LineSource >> 2U]=tempValue;

}

/*
 * @brief NVIC_EnableInterrupt
 *
 * @param IRQNumber=IRQ Number of line
 *
 * @retval void
 */
void NVIC_EnableInterrupt(IRQNumber_Typedef_t IRQNumber){


	uint32_t tempValue=0;
	tempValue= *((IRQNumber >> 5U ) + NVIC_ISER0);	//IRQNumber'ı 32'ye böldük ve pointer aritmetiğinden faydalanarak NVIC_ISER0 ile topladık
	tempValue &=~ (0x1U << (IRQNumber & 0x1FU));    //clear islemi yapar
	tempValue |=  (0x1U << (IRQNumber & 0x1FU));
	*((IRQNumber >> 5U ) + NVIC_ISER0)=tempValue;



}
