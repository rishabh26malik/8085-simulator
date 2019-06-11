#include "library.h"
#include "tools.h"

extern string reg[7];
extern int flag[5],pc;

void inx(string cmd[], int len)
{
    if(len!=2)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(validRegister(cmd[1])==0)
            cout<<" error :"<<pc<<": invalid register"<<endl;
        else
        {
            int regNo=registerNumber(cmd[1]);
            if(regNo!=1 && regNo!=3 && regNo!=5  )
                cout<<" error :"<<pc<<": invalid register"<<endl;
            else
            {
                int dec=hexToDec(reg[regNo+1]);
                if(dec<255)
                {
                    dec++;
                    reg[regNo+1]=decToHex(dec);
                    string str=reg[regNo+1];
                    reverse(str.begin(),str.end());
                    reg[regNo+1]=str;
                }
                else
                {
                    reg[regNo+1]="00";
                    dec=hexToDec(reg[regNo]);
                    //dec++;
                    if(dec<255)
                    {
                        dec++;
                        reg[regNo]=decToHex(dec);
                        string str=reg[regNo];
                        reverse(str.begin(),str.end());
                        reg[regNo]=str;
                    }
                    else
                    {
                        reg[regNo]="00";
                    }
                }

            }
        }
    }
}
