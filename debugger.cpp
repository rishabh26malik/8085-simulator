#include "library.h"
#include "debug.h"
#include "tools.h"

extern vector<string> vect;
extern vector<string> address;

void debugger()
{
    string cmd[10];
    int lineNo=0,breakLine=-1;
    int i=0,j,len=vect.size();
    int len1;
    string breakNo="";
    string instr;
    string command;
    cout<<endl<<"START DEBUGGING"<<endl;
    do{
        cin>>command;

        if(command=="s" || command=="step")
        {
            instr=vect[lineNo];
            cout<<lineNo<<" : "<<instr<<endl;
            step(instr,lineNo+1);
            lineNo++;
        }
        if(command=="p" || command=="print")
        {
            print();
        }
        if(command=="b" || command=="break")
        {
            cin>>breakNo;
            if(!validAddress(breakNo) || breakNo.size()>4)
            {
                cout<<"wrong line number"<<endl;
                    breakNo="";
                    breakLine=-1;
            }
            else
            {
                breakLine=findIndex(breakNo);
            }
        }
        if(command=="r" || command=="run")
        {
            if(breakLine==-1)
                len1=len;
            else
                len1=breakLine;
            for(i=lineNo;i<len1;i++)
            {
                j=0;
                instr=vect[lineNo];
                cout<<lineNo<<" : "<<instr<<endl;
                stringstream iss(instr);
                while(iss >> instr)
                    cmd[j++]=instr;
                runprog(cmd,j);
                lineNo++;
            }
            i=len1;
            breakLine=-1;
        }
        if(command=="q" || command=="quit")
        {
            exit(0);
        }
        if(command=="help" )
        {
            ifstream myfile;
            myfile.open("help.txt");
            if(!myfile.is_open())
            {
                cout<<"error : file not open or invalid file"<<endl;
                exit(0);
            }
            else
            {
                string text;
                while(getline(myfile,text))
                {
                    cout << text << endl;
                }
            }
        }
    }while(lineNo<len);
}

