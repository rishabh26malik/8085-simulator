#include "library.h"
#include "tools.h"

extern string pc;

string programCounter(string cmd)
{
    int adder;
	if(cmd=="mvi")
		adder=3;
	else if(cmd=="mov")
		adder=1;
    else if(cmd=="inr")
		adder=1;
    else if(cmd=="dcr")
		adder=1;
    else if(cmd=="inx")
		adder=1;
    else if(cmd=="dcx")
		adder=1;
    else if(cmd=="lhld")
		adder=3;
    else if(cmd=="shld")
		adder=3;
    else if(cmd=="sta")
		adder=3;
    else if(cmd=="lda")
		adder=3;
    else if(cmd=="add")
		adder=2;
    else if(cmd=="adi")
		adder=2;
    else if(cmd=="sub")
		adder=2;
    else if(cmd=="sui")
		adder=2;
    else if(cmd=="jmp")
		adder=3;
    else if(cmd=="cmp")
		adder=1;
    else if(cmd=="lxi")
		adder=3;
    else if(cmd=="stax")
		adder=3;
    else if(cmd=="dad")
		adder=1;
    else if(cmd=="store")
		adder=4;
    else if(cmd=="cmp")
		adder=1;
    else if(cmd=="jnz")
		adder=3;
    else if(cmd=="jz")
		adder=3;
    else if(cmd=="jnc")
		adder=3;
    else if(cmd=="jc")
		adder=3;
	else if(cmd=="xchg")
		adder=1;
    else if(cmd=="cma")
		adder=1;

    int decPC=hexToDec(pc);
    decPC+=adder;
    pc=decToHex(decPC);
    reverse(pc.begin(),pc.end());
    return pc;
}
