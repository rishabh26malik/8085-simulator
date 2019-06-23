#include "library.h"
#include "tools.h"

extern string reg[7];

void lxi(string cmd[], int len)
{
    string data=cmd[2];
    if(len!=3)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(cmd[1]=="a" || cmd[1]=="c" || cmd[1]=="e" || cmd[1]=="l" || validRegister(cmd[1])==0)
            cout<<"error : invalid register"<<endl;
        else
        {
            //cout<<data.size()<<endl;
            if(data.size()!=4)
                cout<<"error : invalid data length"<<endl;
            else
            {
                if(validData(data)==0)
                    cout<<"error : invalid data"<<endl;
                else
                {
                    int regNo=registerNumber(cmd[1]);
                    string str1="",str2="";
                    int i;
                    for(i=0;i<2;i++)
                    {
                        str1+=data[i];
                        str2+=data[i+2];
                    }
                    //cout<<str1<<" "<<str2<<endl;
                    reg[regNo]=str1;
                    reg[regNo+1]=str2;
                }
            }
        }
    }
}

