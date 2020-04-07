#include<iostream>
using namespace std;
int factorial(int number )
{    int ans=1;
  for (int i=1;i<=number;i++)
  {
     ans=i*ans;
  }
  cout<<ans<<" ,";
  return ans;
}
int main()
{
 int n,r;
 cin>>n>>r;
 int fact;
 cout<<factorial(n)/(factorial(n-r)*factorial(r));
 
}

