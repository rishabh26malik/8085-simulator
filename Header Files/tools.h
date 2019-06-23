#ifndef _TOOLS_H
#define _TOOLS_H

int validRegister(string );
int hexToDec(string );
int registerNumber(string );
int validAddress(string );
int validData(string );
string programCounter(string );
void runprog(string [],int );
void execution(vector<string> );
void flags();
string decToHex(int);
int findIndex(string );
void debugger();

#endif

