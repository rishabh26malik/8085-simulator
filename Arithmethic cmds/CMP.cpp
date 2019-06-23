#include "library.h"
#include "tools.h"
extern string reg[7],memory[65535];
extern int flag[5],pc;

void cmp(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : "<<pc<<": invalid no. of args"<<endl;
    else
    {
        if(validRegister(cmd[1])==0)
            cout<<" error :"<<pc<<": invalid register"<<endl;
        else
        {
            int num1,num2;
            num1=hexToDec(reg[0]);
            if(cmd[1]=="m")
            {
                string addr=reg[5]+reg[6];
                int decAddr=hexToDec(addr);
                string temp=memory[decAddr];
                num2=hexToDec(temp);

            }
            else
            {
                num2=hexToDec(reg[registerNumber(cmd[1])]);
            }
            if(num1<num2)
                {
                    flag[4]=1;
                    flag[1]=0;
                }
                else if(num1==num2)
                {
                    flag[4]=0;
                    flag[1]=1;
                }
                else
                {
                    flag[4]=0;
                    flag[1]=0;
                }
        }
    }
}
