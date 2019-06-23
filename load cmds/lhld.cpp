
#include "library.h"
#include "tools.h"

extern string memory[65535];
extern string reg[7];

void lhld(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(validAddress(cmd[1])==0)
            cout<<"error : invalid address"<<endl;
        else
        {
                int addr=hexToDec(cmd[1]);
                reg[6]=memory[addr];
                addr++;
                reg[5]=memory[addr];
        }
    }
}
