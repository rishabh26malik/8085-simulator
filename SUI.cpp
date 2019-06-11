
#include "library.h"
#include "tools.h"

extern string reg[7];
extern int flag[5];

void sui(string cmd[], int len)
{
        if(len!=2)
            cout<<"error : invalid no. of args"<<endl;
        else
        {
            if(validData(cmd[1])==0 || cmd[1].size()>2)
                cout<<"error : invalid data"<<endl;
            else
            {
                int num1=hexToDec(reg[0]);
                //cout<<num1<<endl;
                int num2=hexToDec(cmd[1]);
                //cout<<num2<<endl;
                if(num1>=num2)
                {
                    num1-=num2;
                    flag[4]=0;
                }
                else
                {
                    flag[4]=1;
                    num1=num2-num1;
                }
                reg[0]=decToHex(num1);
                reverse(reg[0].begin(),reg[0].end());
                if(num1<16)
                    reg[0]="0"+reg[0];
                flags();
                }
            }
        }



