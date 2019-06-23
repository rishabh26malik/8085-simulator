#include "library.h"
#include "tools.h"

extern string memory[65535];
extern string reg[7];

void shld(string cmd[], int len)
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
                memory[addr]=reg[6];
                cout<<"memory["<<cmd[1]<<"] = "<<memory[addr]<<endl;
                addr++;
                string hexAddr=decToHex(addr);
                memory[addr]=reg[5];
                reverse(hexAddr.begin(),hexAddr.end());
                cout<<"memory["<<hexAddr<<"] = "<<memory[addr]<<endl;
        }
    }
}
