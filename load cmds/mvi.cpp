#include "library.h"
#include "tools.h"
//#include "database.h"

extern string memory[65535];
extern int pc,start;
extern string reg[7];

void mvi(string cmd[],int len)
{
		if(len!=3 )
			cout<<"error : invalid no. of args"<<endl;
		else
		{
		    if(!validRegister(cmd[1]))
                cout<<"error : invalid register"<<endl;
            else
            {
                if(cmd[2].size()>2 || validData(cmd[2])==0 )
                    cout<<"error : invalid data"<<endl;
                else
                {
                    /*int dec=hexToDec(cmd[2]);
                    if(dec<16 && cmd[2].size()==1)
                        cmd[2]="0"+cmd[2];*/
                    if(cmd[1]=="a") {
                        //i=0;
                        reg[0]=cmd[2];
                            }
                    else if(cmd[1]=="b") {
                        //i=1;
                        reg[1]=cmd[2];
                            }
                    else if(cmd[1]=="c") {
                        //i=2;
                        reg[2]=cmd[2];
                            }
                    else if(cmd[1]=="d") {
                        //i=3;
                        reg[3]=cmd[2];
                            }
                    else if(cmd[1]=="e") {
                        //i=4;
                        reg[4]=cmd[2];
                           }
                    else if(cmd[1]=="h") {
                        //i=5;
                        reg[5]=cmd[2];
                           }
                    else if(cmd[1]=="l") {
                        //i=6;
                        reg[6]=cmd[2];
                          }
                    else
                        cout<<"error : wrong"<<endl;

                }
            }
		}
}

