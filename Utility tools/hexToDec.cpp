#include "library.h"

int hexToDec(string addr)
{
    //cout<<"hex="<<addr<<endl;
    char hex[5];

    strcpy(hex,addr.c_str());
    //cout<<hex[0]<<" "<<hex[1]<<endl;
	int i,dec=0;
	int base=1;
	int len=strlen(hex);
	//cout<<"len "<<len<<endl;
	for(i=len-1;i>=0;i--)
	{
	    //cout<<dec<<endl;
		if(hex[i]>='0' && hex[i]<='9')
		{
			dec+=(hex[i]-48)*base;
		}
		else
		{
			dec+=(hex[i]-55)*base;
		}
		base*=16;
	}
	return dec;
}
