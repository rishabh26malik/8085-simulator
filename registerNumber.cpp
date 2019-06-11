#include "library.h"

int registerNumber(string reg)
{
	if(reg=="a")
		return 0;
	else if(reg=="b")
		return 1;
	else if(reg=="c")
		return 2;
	else if(reg=="d")
		return 3;
	else if(reg=="e")
		return 4;
	else if(reg=="h" || reg=="m")
		return 5;
	else
		return 6;
}
