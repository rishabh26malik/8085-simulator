#include "library.h"
#include "tools.h"
#include "commands.h"

extern int flag[5],pointer;
extern string pc;
extern vector<string> vect;

void jnz(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(validAddress(cmd[1])==0 || cmd[1].size()>4 )
            cout<<" error :"<<pc<<"invalid address"<<endl;
        else
        {
            if(flag[1]==1)
                return;
            else
            {
                jmp(cmd,len);
            }
        }
    }
}

