
#include "GPIO.h"



/*
 * @brief GPİO_Init,
 *
 * @param GPIOx=GPIO port address(gpıoa,gpıob,gpıoc..)
 * @param GPIO_InitTypeDef_t= user config structures
 *
 * @retval void
 */
void GPIO_Init(GPIO_Typedef_t *GPIOx, GPIO_InitTypeDef_t * GPIO_ConfigStruct)
{
	uint32_t position;
	uint32_t fakePosition=0;
	uint32_t lastPosition=0;
	for (position=0; position<16; position++)
{
		/*MODE Register Config. */
		fakePosition=(0x1 <<position);
		lastPosition=(uint32_t)(GPIO_ConfigStruct -> pinNumber) & fakePosition;

		if(fakePosition==lastPosition)
	{
		uint32_t tempValue= GPIOx->MODER ;//regıster uzerinde direkt olarak islem yapmamak icin değiskene atadık
		tempValue &=~(0x03 << (position*2)); //ilgili biti clear yapma islemi icin
		tempValue|=(GPIO_ConfigStruct->Mode <<(position*2));
		GPIOx->MODER=tempValue;


		if(GPIO_ConfigStruct->Mode== GPIO_MODE_OUTPUT ||GPIO_ConfigStruct->Mode== GPIO_MODE_AF)
		{
			/*OUTPUT TYPE Register Config. */
			tempValue= GPIOx->OTYPER;
			tempValue &=~ (0x1U << position);
			tempValue |= (GPIO_ConfigStruct->Otype << position);
			GPIOx ->OTYPER =tempValue;

			/*OUTPUT SPEED Register Config. */
			tempValue= GPIOx->OSPEEDR;
			tempValue &=~ (0x3U << (position*2));
			tempValue|=(GPIO_ConfigStruct->Speed <<(position*2));
			GPIOx->OSPEEDR=tempValue;
		}

		/*OUTPUT PUSH PULL Register Config. */
		tempValue=GPIOx->PUPDR;
		tempValue &=~(0x03 << (position*2));
		tempValue|=(GPIO_ConfigStruct->Pupd <<(position*2));
		GPIOx ->PUPDR=tempValue;

		if (GPIO_ConfigStruct->Mode == GPIO_MODE_AF)
		{
			tempValue=GPIOx->AFR[position >> 3U];
			tempValue &=~(0xFU << ((position & 0x7U) *4 ) );
			tempValue|=(GPIO_ConfigStruct->Alternate << ((position & 0x7U) * 4 ) );
			GPIOx->AFR[position >> 3U]=tempValue;

		}
	}
}


}




/*
 * @brief GPİO_WritePin, makes pin HIGH or LOW
 *
 * @param GPIOx=GPIO port address(gpıoa,gpıob,gpıoc..)
 * @param pinNumber= GPIO Pin Number 0-15
 * @param pinState= GPIO_Pin_Set or GPIO_Pin_Reset
 *
 * @retval void
 */
void GPIO_WritePin(GPIO_Typedef_t * GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState)
{
if (pinState == GPIO_Pin_Set )
{
   GPIOx ->BSRR=pinNumber;
}
else
{
	GPIOx ->BSRR=(pinNumber << 16);
}
}




/*
 * @brief GPIO_Read_Pin, reads the Pin of GPIOx Port(gpıoa,gpıob... portları için read işlemi yapar)
 *
 * @param GPIOx=GPIO Port base address
 * @param pinNumber=GPIO Pin Number 0-15
 *
 * @retval GPIO_PinState_t
 */

GPIO_PinState_t GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint16_t pinNumber)
{
GPIO_PinState_t bitStatus= GPIO_Pin_Reset;
if ((GPIOx ->IDR & pinNumber) != GPIO_Pin_Reset)
{
	bitStatus= GPIO_Pin_Set;
}
return bitStatus;
}





