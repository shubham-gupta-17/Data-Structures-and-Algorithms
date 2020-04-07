#include<iostream>
using namespace std;
int main()
 {
   char a[508];
   cin>>a;
   //int n=sizeof(a)/sizeof(char);
   cout<<a++<<endl;
   for(int i=0;a[i]!='\0';i++)
      cout<<a[i];
      return 0;
}
