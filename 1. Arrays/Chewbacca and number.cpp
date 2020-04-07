#include <iostream>
using namespace std;
void invert(char *a)
{
     for(int i=0;a[i]!='\0';i++)
    {
      if(a[0]!='9' && a[0]>='5' &&i==0)
         a[0]='9'-a[0] +'0';

         else if(a[i]>='5' && i>0)
         a[i]='9'-a[i]+'0';

         cout<<a[i];

    }
}
void invert2(char *a)
{
    int i=0;
    if(a[i]=='9')
    i++;

    for(;a[i]!='\0';i++)
    {
        int digit=a[i]-'0';
        if(digit>=5)
        digit = 9-digit;

        a[i]=digit+'0';

        cout<<a[i];
    }
}
int main() {
    char a[50];
    cin>>a;
    invert(a);   // !st method
    //invert2(a);  // 2nd method

return 0;
}
