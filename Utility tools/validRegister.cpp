#include "library.h"
int validRegister(string reg)
{
	if(reg=="a" || reg=="b" || reg=="c" || reg=="d" || reg=="e" || reg=="h" || reg=="l" || reg=="m")
		return 1;
	else
		return 0;

}
