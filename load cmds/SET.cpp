#include "library.h"
#include "tools.h"
#include "arithmetic.h"

extern int pc;
extern string memory[65535];

void store(string cmd[], int len)
{
    if(len != 3)
        cout<<" error :"<<pc<<"invalid no. of args"<<endl;
    else
    {
        if(validAddress(cmd[1])==0 || cmd[1].size()>4)
            cout<<" error :"<<pc<<"invalid address"<<endl;
        else
        {
            if(validData(cmd[2])==0 || cmd[2].size()>2)
                cout<<" error :"<<pc<<"invalid data"<<endl;
            else
            {
                int addr=hexToDec(cmd[1]);
                //cout<<"addr"<<addr<<endl;
                memory[addr]=cmd[2];
                cout<<"memory["<<cmd[1]<<"] = "<<cmd[2]<<endl;
            }

        }

    }
}
