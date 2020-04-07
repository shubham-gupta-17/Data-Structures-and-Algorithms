#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5};
   // cin>>a;
   int n=sizeof(a)/sizeof(int);
   cout<<n<<endl;
    for(int i=0;i<n;i++)
       cout<<a[i];



       char b[]={'h','e','l','l','o'};
       cout<<endl<<b<<endl;

       // we can also print b using loops

       char c[100];
       cin.getline(c,100,'.');   // it will read entire line till dot


       string s;
       getline(cin,s);
       cout<<s<<endl;
       cout<<c;

}
