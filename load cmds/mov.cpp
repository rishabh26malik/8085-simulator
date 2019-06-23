#include "library.h"
#include "tools.h"

extern int pc;
extern string reg[7],memory[65535];

void mov(string cmd[], int len)
{
	if(len!=3)
	{
		cout<<"error : invlaid no. of args"<<endl;
	}
	else
	{
		if(!validRegister(cmd[1]) || !validRegister(cmd[2]))
			cout<<"error : invalid register(s)"<<endl;
		else
		{

		    if(cmd[2]=="m" || cmd[1]=="m")
            {
                 string addr;
                int regNo;
                if(cmd[2]=="m")
                {
                    regNo=registerNumber(cmd[1]);
                    addr=reg[5]+reg[6];
                    int decAddr=hexToDec(addr);
                    reg[regNo]=memory[decAddr];
                }
                else
                {
                    regNo=registerNumber(cmd[2]);
                    addr=reg[5]+reg[6];
                    int decAddr=hexToDec(addr);
                    memory[decAddr]=reg[regNo];
                    cout<<"memory["<<addr<<"] = "<<reg[regNo]<<endl;
                }
            }
            else
            {
                int reg1,reg2;
                reg1=registerNumber(cmd[1]);
                reg2=registerNumber(cmd[2]);
                string temp;
                reg[reg1]=reg[reg2];
            }
		}
	}
}
