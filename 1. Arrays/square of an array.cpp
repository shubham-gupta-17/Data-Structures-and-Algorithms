// square each element of an array
#include<iostream>
using namespace std;
int main()
{
  int a[10];
   for (int i=0;i<10;i++)
{
  cin>>a[i];
}

for(int i=0;i<10;i++)
{
 a[i]=a[i]*a[i];
cout<<a[i];
}

return 0;
}

