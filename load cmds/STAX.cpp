
#include "library.h"
#include "tools.h"

extern string reg[7];
extern string memory[65535];
void stax(string cmd[], int len)
{
    string data=cmd[2];
    if(len!=2)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        if(cmd[1]=="a" || cmd[1]=="c" || cmd[1]=="e" || cmd[1]=="l" || validRegister(cmd[1])==0)
            cout<<"error : invalid register"<<endl;
        else
        {
                    int regNo;
                    if(cmd[1]=="m")
                        regNo=registerNumber("h");
                    else
                        regNo=registerNumber(cmd[1]);
                    string str1="",str2="";
                    str1=reg[regNo];
                    str2=reg[regNo+1];
                    string addr="";
                    addr=str1+str2;
                    int decAddr=hexToDec(addr);
                    memory[decAddr]=reg[0];
                    cout<<"memory["<<reg[regNo]<<reg[regNo+1]<<"] = "<<memory[decAddr]<<endl;

            }
    }

}

