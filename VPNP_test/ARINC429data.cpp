#include "ARINC429data.h"

void par2arinc(uint32_t arincWordNo, uint32_t &data)
{
	t429Word value;
	value.ul429Data = 0; 
	value.Fields.ucLabel = aucInvByte[arincWordNo]; // Восьмеричный код 277, инверсный, чтобы соответствовать стандарту
	value.Fields.ucSdi = 1;                   // канал 1
	value.Fields.ulData = data;
	value.Fields.ucStatus = 3;                // NO
	value.Fields.ucParity = parity (value.ul429Data); // Чётность

}
int parity(uint32_t data)
{
	if (data % 2 == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}