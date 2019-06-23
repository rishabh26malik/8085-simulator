#include "library.h"
#include "tools.h"

extern string reg[7];
extern int flag[5],pc;

void adi(string cmd[], int len)
{
        if(len!=2)
            cout<<"error : "<<pc<<": invalid no. of args"<<endl;
        else
        {
            if(validData(cmd[1])==0 || cmd[1].size()>2)
                cout<<"error : "<<pc<<": invalid data"<<endl;
            else
            {
                int AuxCarry=0;
                int num1=hexToDec(reg[0]);
                char temp1=reg[0][1];
                char temp2=cmd[1][1];
                //cout<<num1<<endl;
                int num2=hexToDec(cmd[1]);
                //cout<<num2<<endl;
                num1+=num2;
                //cout<<num1<<endl;
                if(num1<=255)
                {
                    flag[4]=0;  //CARRY  OFF
                    reg[0]=decToHex(num1);
                    reverse(reg[0].begin(),reg[0].end());
                }
                else
                {
                    cout<<num1<<endl;
                    flag[4]=1;  //CARRY  ON
                    //reg[0]=decToHex(num1);
                    string str=decToHex(num1);
                    str.erase(2);
                    reverse(str.begin(),str.end());
                    reg[0]=str;

                }
                if(num1<16)
                    reg[0]="0"+reg[0];
                //FLAGS


                if(temp1>='1' || temp1<='9')
                    AuxCarry+=(int)temp1-48;
                else
                    AuxCarry+=(int)temp1-55;

                if(temp2>='1' || temp2<='9')
                    AuxCarry+=(int)temp2-48;
                else
                    AuxCarry+=(int)temp2-55;

                if(AuxCarry>15)
                    flag[2]=1;           // AC ON
                flags();
            }
        }
}

