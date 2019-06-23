#include "library.h"
#include "tools.h"

extern string memory[65535];
extern int pc;
extern string reg[7];

void lda(string cmd[],int len)
{
    if(len!=2)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(validAddress(cmd[1])==0 || cmd[1].size()>4)
            cout<<"error : invalid address"<<endl;
        else
        {
            int addr=hexToDec(cmd[1]);
            //cout<<"addr "<<addr<<endl;
            reg[0]=memory[addr];
        }
    }
}
