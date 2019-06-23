#include "library.h"
int validAddress(string address)
{
	char addr[4];
	strcpy(addr,address.c_str());
	if(strlen(addr)==4)
	{
		for(int i=0;i<4;i++)
		{
			if(addr[i]!='0' && addr[i]!='1' && addr[i]!='2' && addr[i]!='3' && addr[i]!='4' && addr[i]!='5' && addr[i]!='6' && addr[i]!='7' && addr[i]!='8' && addr[i]!='9' && addr[i]!='A' && addr[i]!='B' && addr[i]!='C' && addr[i]!='D' && addr[i]!='E' && addr[i]!='F')
				return 0;
		}
		return 1;
	}
	else
		return 0;
}
