#include "library.h"
#include "tools.h"
/*
extern string memory[65535];
extern int pc,start,flags[5];
extern string reg[7];
*/

int pointer=0;

void execution(vector<string> vect)
{
	string temp,str;
	int i,len,j=0;
	string cmd[10];
	len=vect.size();
	for(i=0;i<len;i++)
	{
		j=0;
        pointer=i;
		str="";
		temp=vect[i];
		stringstream iss(temp);
		while(iss >> str)
			cmd[j++]=str;

		/*for(int k=0;k<j;k++)
            cout<<cmd[k]<<" ";
        cout<<endl;
    */
		runprog(cmd,j);
        if(pointer!=i)
            i=pointer-1;
	}

}
