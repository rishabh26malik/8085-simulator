#include "library.h"
#include "tools.h"

extern string reg[7],pc;
extern int flag[5],pcs;

void dcx(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : "<<pc<<": invalid no. of args"<<endl;
    else
    {
        if(validRegister(cmd[1])==0)
            cout<<" error :"<<pc<<": invalid register"<<endl;
        else
        {
            int regNo=registerNumber(cmd[1]);
            if(regNo!=1 && regNo!=3 && regNo!=5 && cmd[1]!="m" )
                cout<<" error :"<<pc<<": invalid register"<<endl;
            else
            {
                int dec=hexToDec(reg[regNo+1]);
                if(dec>0)
                {
                    dec--;
                    reg[regNo+1]=decToHex(dec);
                    string str=reg[regNo+1];
                    reverse(str.begin(),str.end());
                    reg[regNo+1]=str;
                }
                else
                {
                    reg[regNo+1]="FF";
                    dec=hexToDec(reg[regNo]);
                    //cout<<"dec "<<dec<<endl;
                    if(dec>0)
                    {
                        if(dec==1)
                            reg[regNo]="00";
                        else
                        {
                            dec--;
                            reg[regNo]=decToHex(dec);
                            string str=reg[regNo];
                            reverse(str.begin(),str.end());
                            reg[regNo]=str;
                        }
                    }
                    else
                    {
                        reg[regNo]="FF";
                    }
                }

            }
        }
    }
}

