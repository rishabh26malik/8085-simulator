#include "library.h"
#include "commands.h"
#include "arithmetic.h"
#include "jump.h"

extern int pc;

void runprog(string cmd[],int len )
{
	if(cmd[0]=="mvi")
	{
		mvi(cmd,len);
	}
	else if(cmd[0]=="mov")
	{
		mov(cmd,len);
	}

	else if(cmd[0]=="sta")
	{
		sta(cmd,len);
	}
	else if(cmd[0]=="lda")
	{
		lda(cmd,len);
	}
	else if(cmd[0]=="inr")
	{
		inr(cmd,len);
	}
	else if(cmd[0]=="dcr")
	{
		dcr(cmd,len);
	}
	else if(cmd[0]=="lhld")
	{
		lhld(cmd,len);
	}
	else if(cmd[0]=="shld")
	{
		shld(cmd,len);
	}
    else if(cmd[0]=="lxi")
	{
		lxi(cmd,len);
	}
	else if(cmd[0]=="stax")
	{
		stax(cmd,len);
	}
	else if(cmd[0]=="xchg")
	{
		xchg(cmd,len);
	}
	else if(cmd[0]=="inx")
	{
		inx(cmd,len);
	}
	else if(cmd[0]=="dcx")
	{
		dcx(cmd,len);
	}
	else if(cmd[0]=="add")
	{
		add(cmd,len);
	}
	else if(cmd[0]=="adi")
	{
		adi(cmd,len);
	}
	else if(cmd[0]=="sub")
	{
		sub(cmd,len);
	}
	else if(cmd[0]=="sui")
	{
		sui(cmd,len);
	}
    else if(cmd[0]=="jmp")
	{
		jmp(cmd,len);
	}
	else if(cmd[0]=="jnz")
	{
		jnz(cmd,len);
	}
	else if(cmd[0]=="jz")
	{
		jz(cmd,len);
	}
	else if(cmd[0]=="jnc")
	{
		jnc(cmd,len);
	}
	else if(cmd[0]=="jc")
	{
		jc(cmd,len);
	}
	else if(cmd[0]=="cmp")
	{
		cmp(cmd,len);
	}
	else if(cmd[0]=="dad")
	{
		dad(cmd,len);
	}
	else if(cmd[0]=="store")
	{
		store(cmd,len);
	}
	else if(cmd[0]=="cma")
	{
		cma(cmd,len);
	}
	else if(cmd[0]=="hlt")
	{

	}
	else
    {
        cout<<"error "<<pc<<" : invalid command"<<endl;
    }
}
