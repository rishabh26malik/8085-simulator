#include "library.h"
#include "tools.h"

extern vector<string> vect;
extern string pc;
extern int pointer;

void jmp(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(validAddress(cmd[1])==0 || cmd[1].size()>4 )
            cout<<" error :"<<pc<<"invalid address"<<endl;
        else
        {
           // cout<<"pointer "<<pointer<<endl;
            //cout<<"cmd[1] "<<cmd[1]<<endl;
                pointer=findIndex(cmd[1]);
                if(pointer==-1)
                {
                     cout<<"error : "<<pc<<"wrong address in jump"<<endl;
                     exit(0);
                }

            //}

        }
    }
}
