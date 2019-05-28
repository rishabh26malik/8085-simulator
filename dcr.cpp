
#include "library.h"
#include "tools.h"
extern string reg[7],memory[65535];
extern int flag[5],pc;
void dcr(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : "<<pc<<": invalid no. of args"<<endl;
    else
    {
        if(validRegister(cmd[1])==0)
            cout<<" error :"<<pc<<": invalid register"<<endl;
        else
        {
            int dec;
            if(cmd[1]=="m")
            {
                string addr=reg[5]+reg[6];
                int decAddr=hexToDec(addr);
                dec=hexToDec(memory[decAddr]);
                if(dec>1)
                {
                    dec--;
                    memory[decAddr]=decToHex(dec);
                    reverse(memory[decAddr].begin(),memory[decAddr].end());
                }
                else if(dec==1)
                    memory[decAddr]="00";
                else
                    memory[decAddr]="FF";
                cout<<"memory["<<addr<<"] = "<<memory[decAddr]<<endl;

                if(dec<16)
                {
                    memory[decAddr].erase(0,1);
                    //memory[decAddr]="0"+memory[decAddr];
                }
            }
            else
            {
                int regNo=registerNumber(cmd[1]);
                dec=hexToDec(reg[regNo]);
                if(dec>1)
                {
                    dec--;
                    reg[regNo]=decToHex(dec);
                    string str=reg[regNo];
                    reverse(str.begin(),str.end());
                    reg[regNo]=str;
                    flag[4]=0;    //CARRY FLAF OFF
                    flag[1]=0;      // ZERO FLAG

                    if(dec<16)
                        reg[regNo]="0"+reg[regNo];
                }
                else if(dec==1)
                {
                    reg[0]="00";
                    flag[4]=0;    //CARRY FLAF OFF
                    flag[1]=1;      // ZERO FLAG

                }
                else
                {
                    reg[regNo]="FF";
                    flag[4]=1;    //CARRY FLAF ON
                    flag[1]=0;
                }

            }
        }
    }
}

