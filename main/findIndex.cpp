#include "library.h"
#include "tools.h"

extern vector<string> address;
extern int start;

int  findIndex(string addr)
{

    int i=0,len;
    len=address.size();
    if(start==0)
    {

        for(i=0;i<len;i++)
        {

            if(address[i]==addr)
              {
                 return i;
              }
        }
        return -1;
    }
    else
    {

        for(i=0;i<len;i++)
        {

            if(address[i]==addr)
              {
                 return i;
              }
        }
        return -1;
    }

}
