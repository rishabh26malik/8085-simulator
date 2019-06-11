#include "library.h"
#include "tools.h"

extern string reg[7],memory[65535];
extern int flag[5],pc;

void inr(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(validRegister(cmd[1])==0 )
            cout<<" error :"<<pc<<": invalid register"<<endl;
        else
        {
            int dec;
            if(cmd[1]=="m")
            {
                string addr=reg[5]+reg[6];
                int decAddr=hexToDec(addr);
                dec=hexToDec(memory[decAddr]);
                if(dec<255)
                {
                    dec++;
                    memory[decAddr]=decToHex(dec);
                    reverse(memory[decAddr].begin(),memory[decAddr].end());
                }
                else
                    memory[decAddr]="00";
                cout<<"memory["<<addr<<"] = "<<memory[decAddr]<<endl;
            }
            else
            {
                int regNo=registerNumber(cmd[1]);
                dec=hexToDec(reg[regNo]);

                if(dec<255)
                {
                    dec++;
                    reg[regNo]=decToHex(dec);
                    string str=reg[regNo];
                    reverse(str.begin(),str.end());
                    reg[regNo]=str;
                    flag[4]=0;     // CARRY FLAG
                    flag[1]=0;     // zero flag
                }
                else
                {
                    reg[regNo]="00";
                    flag[4]=1;     // CARRY FLAG
                    flag[1]=1;    //ZERO FLAG
                }
            }

        }
    }
}

