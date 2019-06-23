
#include "library.h"
#include "tools.h"

extern string memory[65535];
extern int pc,start;
extern string reg[7];

void sta(string cmd[],int len)
{
    if(len!=2)
        cout<<" error :"<<pc<<"invalid no. of args"<<endl;
    else
    {
        if(cmd[1]!="m" &&(validAddress(cmd[1])==0 || cmd[1].size()>4))
        {
            cout<<" error :"<<pc<<"invalid address"<<endl;
        }
        else
        {
            int addr;
            string hexAddr;
            if(cmd[1]=="m")
            {
                hexAddr=reg[5]+reg[6];
                addr=hexToDec(hexAddr);
                cout<<hexAddr<<endl;
            }
            else
                addr=hexToDec(cmd[1]);

            memory[addr]=reg[0];
            cout<<"memory["<<cmd[1]<<"] = "<<memory[addr]<<endl;
        }
    }
}
