#include "library.h"
#include "tools.h"

extern string reg[7];

void xchg(string cmd[],int len)
{
    if(len!=1)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        string temp;
        temp=reg[3];
        reg[3]=reg[5];
        reg[5]=temp;
        temp=reg[4];
        reg[4]=reg[6];
        reg[6]=temp;
    }
}
