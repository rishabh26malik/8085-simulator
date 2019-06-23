#include "library.h"
#include "debug.h"
#include "tools.h"

extern string reg[7],memory[65535];
extern int flag[5];

void print()
{
    int len;
    string toPrint;
    cin>>toPrint;
    len=toPrint.length();
    if(len==1)
    {
        if(!validRegister(toPrint))
            cout<<"invalid register"<<endl;
        else
        {
            int regNo=registerNumber(toPrint);
            cout<<toPrint<<" = "<<reg[regNo]<<endl;
        }
    }
    else if(len==4)
    {
        if(!validAddress(toPrint))
            cout<<"invalid address"<<endl;
        else
        {
            int decAddr=hexToDec(toPrint);
            cout<<"memory["<<toPrint<<"] = "<<memory[decAddr]<<endl;
        }
    }
    else
    {
        cout<<"You are trying to print wrong data"<<endl;
    }
}


