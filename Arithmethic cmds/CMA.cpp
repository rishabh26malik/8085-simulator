#include "library.h"
#include "tools.h"

extern string reg[7];

void cma(string cmd[],int len)
{
    if(len!=1)
        cout<<"error : invalid no. of args"<<endl;
    else
    {
        int len=2;
        string a=reg[0],complement="";
        cout<<(int)a[0]<<" "<<(int)a[1]<<endl;
        for(int i=0;i<len;i++)
        {
            if(a[i]>='0'&&a[i]<='9')
            {
                int diff=15-(a[i]-'0');
                if(diff>=0&&diff<=9)
                    complement+=('0'+diff);
                else if(diff>=10&&diff<=15)
                    complement+=('A'+(diff-10));
            }
            if(a[i]>='A'&&a[i]<='F')
            {
                int value=a[i]-'A';
                int diff=15-value;
                if(diff>=0&&diff<=9)
                    complement+=('0'+diff);
                else if(diff>=10&&diff<=15)
                    complement+=('0'+(diff-10));
            }
        }
        reg[0]=complement;

    }
}
