
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
      if(a>b)
      { int temp=b;
         b=a;
         a=temp;}         /// provided B>A ;
    int n=b%a;
    while(n!=0)
    {
      b=a;
      a=n;
      n=b%a;
    }
    cout<<a;
    ///for finding all factors of a number or finding HCF of two numbers
    int a1,b1;
    cin>>a1>>b1;
    int n1=min(a1,b1);
    int c=0;
    for(int i=2;i<=n1;i++)
    {
       while(a1%i==0 && b1%i==0)
       {
            cout<<i<<endl;
            a1/=i;
            b1/=i;
            c++;

       }


    }
    if(c==0)
    cout<<"0";

}
