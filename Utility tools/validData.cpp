#include "library.h"
int validData(string value)
{
    int len=value.size();
	char data[len];
	strcpy(data,value.c_str());

		for(unsigned int i=0;i<len;i++)
		{
			if(data[i]!='0' && data[i]!='1' && data[i]!='2' && data[i]!='3' && data[i]!='4' && data[i]!='5' && data[i]!='6' && data[i]!='7' && data[i]!='8' && data[i]!='9' && data[i]!='A' && data[i]!='B' && data[i]!='C' && data[i]!='D' && data[i]!='E' && data[i]!='F')
				return 0;

		}
		return 1;


}
