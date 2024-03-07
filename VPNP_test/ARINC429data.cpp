#include "ARINC429data.h"

void par2arinc(uint32_t arincWordNo, uint32_t &data)
{
	t429Word value;
	value.ul429Data = 0; 
	value.Fields.ucLabel = aucInvByte[arincWordNo]; // ������������ ��� 277, ���������, ����� ��������������� ���������
	value.Fields.ucSdi = 1;                   // ����� 1
	value.Fields.ulData = data;
	value.Fields.ucStatus = 3;                // NO
	value.Fields.ucParity = parity (value.ul429Data); // ׸������

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