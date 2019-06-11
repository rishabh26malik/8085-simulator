#include "library.h"

string decToHex(int num)
{
    char hex[2];
    int temp=0,i=0;
   // if(num<=255)
    //{
        while(num!=0)
        {
            temp=num%16;
            if(temp<10)
                hex[i++]=temp+48;
            else
                hex[i++]=(char)(temp+55);
            num/=16;
        }
        return hex;
/*
    }
    else
    {
        return "00";
    }  */
}
