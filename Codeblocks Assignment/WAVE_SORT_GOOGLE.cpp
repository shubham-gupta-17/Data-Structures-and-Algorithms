#include<bits/stdc++.h>
using namespace std;
int main()
{     /// All assumptions are unique and no two numbers are in repeation
  int n;
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
  cin>>*(a+i);

  for(int i=0;i<n;i++)
  {
      if(i%2==0)
      {    if(a[i]<a[i+1])
           swap(a[i],a[i+1]);
      }

      else
      {
          if(a[i]>a[i+1])
            swap(a[i],a[i+1]);

      }
  }
  for(int i=0;i<n;i++)
  cout<<a[i]<<" ";


  ///2nd method

  for(int i=0;i<n;i+=2)
  {
     if(i>0 && a[i-1]>a[i])
       swap(a[i],a[i-1]);

     if(i<n-1 && a[i+1]>a[i])
     swap(a[i],a[i+1]);
  }

  for(int i=0;i<n;i++)
  cout<<endl<<a[i]<<" ";

}
