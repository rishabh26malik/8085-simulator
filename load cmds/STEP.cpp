#include "library.h"
#include "debug.h"
#include "tools.h"

void step(string instr , int lineNo)
{
    //int len;
    int j=0;
    string cmd[10];
    stringstream iss(instr);
		while(iss >> instr)
			cmd[j++]=instr;
    //len=strlen(cmd);
    runprog(cmd,j);
}

