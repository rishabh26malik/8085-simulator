#include "library.h"
#include "tools.h"
extern string reg[7];
extern int flag[5];

void flags()
{
    string data=reg[0];
    int i,binary[8],dec;
    int parity=0;
    dec=hexToDec(data);
    //cout<<"a "<<reg[0]<<endl;
    //cout<<"flag dec "<<dec<<endl;
    if(dec==0)    //ZERO
        flag[1]=1;
    else
        flag[1]=0;
    for(i=7;i>=0;i--)
    {
        if(dec>0)
        {
            binary[i]=dec%2;
            dec/=2;
            if(binary[i]==1)
                parity++;

        }
        else
        {
            binary[i]=0;
        }
        //cout<<binary[i];
    }
    //cout<<endl;
    if(parity%2==0)
        parity=1;
    else
        parity=0;

    flag[0]=binary[0];    // SIGN
    flag[3]=parity;     //PARITY

}
