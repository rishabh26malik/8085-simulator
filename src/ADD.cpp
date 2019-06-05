#include "library.h"
#include "tools.h"

extern string reg[7];
extern int flag[5],pc;
extern string memory[65535];

void add(string cmd[], int len)
{
        if(len!=2)
            cout<<"error : "<<pc<<": invalid no. of args"<<endl;
        else
        {
            if(validRegister(cmd[1])==0)
                cout<<" error :"<<pc<<": invalid register"<<endl;
            else
            {
                char temp1,temp2;
                int num1,num2,regNo;
                if(cmd[1]=="m")
                {
                    string addr=reg[5]+reg[6];
                    int decAddr=hexToDec(addr);
                    //cout<<decAddr<<endl;
                    num2=hexToDec(memory[decAddr]);
                    //cout<<num2<<endl;
                    temp2=memory[decAddr][1];

                }
                else
                {
                    regNo=registerNumber(cmd[1]);
                    temp2=reg[regNo][1];
                    num2=hexToDec(reg[regNo]);
                }
                num1=hexToDec(reg[0]);
                //cout<<num1<<endl;
                temp1=reg[0][1];
                //cout<<temp1<<endl;
                //cout<<temp2<<endl;
                num1+=num2;
                if(num1<=255)
                {
                    reg[0]=decToHex(num1);
                    reverse(reg[0].begin(),reg[0].end());
                    flag[4]=0;  //CARRY  OFF
                }
                else
                {
                    flag[4]=1;  //CARRY  ON
                    string str=decToHex(num1);
                    str.erase(2);
                    reg[0]=str;
                    reverse(reg[0].begin(),reg[0].end());

                }

                if(num1<16)
                    reg[0]="0"+reg[0];

                //FLAGS
                int AuxCarry=0;
                if(temp1>='0' || temp1<='9')
                    AuxCarry+=(int)temp1-48;
                else
                    AuxCarry+=(int)temp1-55;
               // cout<<"ac "<<AuxCarry<<endl;
                if(temp2>='0' || temp2<='9')
                    AuxCarry+=(int)temp2-48;
                else
                    AuxCarry+=(int)temp2-55;
                //cout<<"ac "<<AuxCarry<<endl;
                if(AuxCarry>15)
                    flag[2]=1;           // AC ON
                else
                    flag[2]=0;
                //cout<<"ac "<<AuxCarry<<endl;
                flags();

            }

        }
}
