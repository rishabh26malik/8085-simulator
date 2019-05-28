#include "library.h"
#include "tools.h"

extern int flag[5],pc;
extern string reg[7];

void dad(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : "<<pc<<": invalid no. of args"<<endl;
    else
    {
        if(validRegister(cmd[1])==0)
            cout<<" error :"<<pc<<": invalid register"<<endl;
        else
        {
            if(cmd[1]=="c" || cmd[1]=="e" || cmd[1]=="l" )
                cout<<" error :"<<pc<<": invalid register"<<endl;
            else
            {
                if(cmd[1]=="m" || cmd[1]=="h")
                {
                    reg[5]="00";
                    reg[6]="00";
                }
                else
                {
                    int num1,num2;
                    int regNo=registerNumber(cmd[1]);
                    int carry=0;
                    num1=hexToDec(reg[6]);
                    num2=hexToDec(reg[regNo+1]);
                    num1+=num2;
                    if(num1<=255)
                    {
                        reg[6]=decToHex(num1);
                        reverse(reg[6].begin(),reg[6].end());
                    }
                    else
                    {
                        reg[6]=decToHex(num1);
                        reg[6].erase(2);
                        reverse(reg[6].begin(),reg[6].end());
                        carry=1;
                    }


                    num1=hexToDec(reg[5]);
                    num2=hexToDec(reg[regNo]);
                    num1+=num2+carry;
                    if(num1<=255)
                    {
                        reg[5]=decToHex(num1);
                        reverse(reg[5].begin(),reg[5].end());
                        flag[4]=0;
                    }
                    else
                    {
                        reg[5]=decToHex(num1);
                        reg[5].erase(2);
                        reverse(reg[5].begin(),reg[5].end());
                        flag[4]=1;
                    }


                }
            }
        }
    }
}
