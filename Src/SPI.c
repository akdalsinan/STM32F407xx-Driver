
#include "SPI.h"

/*
 * @brief SPI_Init,Configures the SPI peripheral
 *
 * @param SPI_Handle=User config structure
 *
 * @retval void
 */
void SPI_Init(SPI_HandleTypedef_t *SPI_Handle)
{
	uint32_t tempValue = 0;
	tempValue=SPI_Handle->Instance->CR1;
	tempValue |= (SPI_Handle->Init.Baudrate) | (SPI_Handle->Init.CPHA) | (SPI_Handle->Init.CPOL) | (SPI_Handle->Init.DFF_Format)| \
			  (SPI_Handle->Init.Mode)| (SPI_Handle->Init.FrameFormat)| (SPI_Handle->Init.BusConfig) | (SPI_Handle->Init.SSM_Cmd);
}


/*
 * @brief SPI_PeriphCmd,ENABLE or DISABLE SPI periphal
 *
 * @param SPI_Handle=User config structure
 * @param stateOfSPI=ENABLE or DISABLE
 *
 * @retval void
 */
void SPI_PeriphCmd(SPI_HandleTypedef_t *SPI_Handle,FunctionalState_t stateOfSPI)
{
	if (stateOfSPI== ENABLE)
	{
		SPI_Handle->Instance->CR1 |=  (0X1U << SPI_C1_SPE);
	}
	else
	{
		SPI_Handle->Instance->CR1 &=~ (0X1U << SPI_C1_SPE);
	}
}


/*
 * @brief SPI_TransmitData,Transmit data to the slave
 *
 * @param SPI_Handle=User config structure
 * @param *pData= Address of data to send
 * @param sizeOfData= Length of your data in bytes
 *
 * @retval void
 */
void SPI_TransmitData(SPI_HandleTypedef_t *SPI_Handle,uint8_t *pData, uint16_t sizeOfData)
{
	if(SPI_Handle->Init.DFF_Format==SPI_DFF_16BIT)
	{
		while(sizeOfData > 0)
		{
			if ((SPI_Handle->Instance->SR >> 1U) & 0x1U) // SR register--> TX bit(1.bit)==1 mi? (flag control)
			{
				SPI_Handle->Instance->DR = *((uint16_t *)pData);
				pData += sizeof(uint16_t);
				sizeOfData -= 2;
			}
		}
	}
	else
	{
		while(sizeOfData > 0)
		{
			if ((SPI_Handle->Instance->SR >> 1U) & 0x1U) //Status Register (SR)--> TX bit(1.bit)==1 mi? (flag control)
			{
				SPI_Handle->Instance->DR = *pData;
				pData += sizeof(uint8_t);
				sizeOfData --;
			}
		}
	}

	while ((SPI_Handle->Instance->SR >> 7U) & 0X1U); 	 //Status Register(SR) --> BSY bit(7.bit)==1 ise SPI hattı mesguldur.
													 	 //bunun icin bu while yazılmıştır.
}
