
#include "library.h"
#include "tools.h"

extern string reg[7],memory[65535];
extern int flag[5];

void sub(string cmd[], int len)
{
        if(len!=2)
            cout<<"error : invalid no. of args"<<endl;
        else
        {
            if(validRegister(cmd[1])==0)
                cout<<"error : invalid register"<<endl;
            else
            {
                char temp1,temp2;
                int num1,num2,regNo;
                if(cmd[1]=="m")
                {
                    string addr=reg[5]+reg[6];
                    int decAddr=hexToDec(addr);
                    num2=hexToDec(memory[decAddr]);
                    temp2=memory[decAddr][1];
                }
                else
                {
                    regNo=registerNumber(cmd[1]);
                    num2=hexToDec(reg[regNo]);
                    temp2=reg[regNo][1];
                }
                num1=hexToDec(reg[0]);
                temp1=reg[0][1];          // FOR FLAG

                temp2=reg[regNo][1];       // FOR FLAG
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
                /*cout<<reg[0]<<endl;
                if(cmd[1]=="m")
                    reg[0].erase(0,1);
                */
                //FLAGS
                int AuxCarry=0;

                if(temp1>='0' || temp1<='9')
                    AuxCarry+=(int)temp1-48;
                else
                    AuxCarry+=(int)temp1-55;
                if(temp2>='0' || temp2<='9')
                    AuxCarry+=(int)temp2-48;
                else
                    AuxCarry+=(int)temp2-55;

                if(AuxCarry>15)
                    flag[2]=1;           // AC ON
                //cout<<"ac "<<AuxCarry<<endl;
                flags();
                }

            }
        }



