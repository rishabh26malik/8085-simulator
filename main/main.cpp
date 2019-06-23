#include "library.h"
#include "tools.h"
#include "arithmetic.h"

string memory[65535];
int start=0;
string pc;
string reg[7]={"00","00","00","00","00","00","00"}; //a,b,c,d,e,h,l
int flag[5]={0,0,0,0,0};   // SIGN, ZERO, AC, PARITY, CARRY
vector<string> vect;
vector<string> address;

int main(int argc, char** argv)
{
    char ch[7]={'a','b','c','d','e','h','l'};
    string carry[5]={"S ","Z ","AC","P ","CY"};
	int i=0,lineNo=0;
	string temp,str;
    cout<<"ENTER STARTING ADDRESS"<<endl;
    getline (cin, pc);
        if(argc==2)
        {
            start=1;
            string text;
            ifstream myfile;
            myfile.open(argv[1]);
            if(!myfile.is_open())
            {
                cout<<"error : file not open or invalid file"<<endl;
                exit(0);
            }
            else if(argc>2)
            {
                cout<<"error : invalid no. of args in cmd line"<<endl;
                exit(0);
            }
            else
            {
                while(getline(myfile,text))
                {
                    stringstream iss(text);
                    iss >> str;
                    cout<<"["<<lineNo<<"] : "<<pc<<" ";
                    lineNo++;
                    address.push_back(pc);
                    vect.push_back(text);
                    programCounter(str);
                    cout << text << endl;
                    i++;
                }
            }
        }
    else
    {
        //cout<<pc<<" ";
        i=0;
        cout<<"["<<lineNo<<"] : "<<pc<<" ";
        while(getline(cin,temp))
        {
            lineNo++;
            address.push_back(pc);
            stringstream iss(temp);
            iss >> str;
            programCounter(str);
            if(temp.compare("hlt")==0)
                break;
            vect.push_back(temp);
             cout<<"["<<lineNo<<"] : "<<pc<<" ";

        }
    }
	execution(vect);
	//display registers content
	for(i=0;i<7;i++){
		cout<<ch[i]<<" = "<<reg[i]<<endl;

	}
	// CARRY FLAGS
	for(i=0;i<5;i++)
    {
        cout<<carry[i]<<" : "<<flag[i]<<endl;
    }
	char choice;
	cout<<"Do you want to debug your program (Y/N)   ";
	cin>>choice;
	if(choice=='y' || choice=='Y')
        debugger();
    else
        exit(0);
	//display registers content
	for(i=0;i<7;i++){
		cout<<ch[i]<<" = "<<reg[i]<<endl;

	}
	// CARRY FLAGS
	for(i=0;i<5;i++)
    {
        cout<<carry[i]<<" : "<<flag[i]<<endl;
    }
	return 0;
}



