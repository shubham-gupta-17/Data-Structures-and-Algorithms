#include<bits/stdc++.h>
using namespace std;
int main()
{

 int n;
 cin>>n;
 string *a=new string [n];
 for(int i=0;i<n;i++)
 cin>>a[i];
  for(int i=0;i<n-1;i++)
  {    int c=0;
    for(int j=0;j<n-i-1;j++)
    {
       if((int)a[j][0]==(int)a[j+1][0])
       {     c=1;
          int n=min(a[j].length(),a[j+1].length());
          for(int k=1;k<n;k++)
          {
             if(a[j][k]==a[j+1][k])
               c++;
          }
          if(c==n && a[j].length()<a[j+1].length())
          swap(a[j],a[j+1]);

          else if(a[j]>a[j+1])
          swap(a[j],a[j+1]);
       }

       else if((int)a[j][0]>(int)a[j+1][0])
       swap(a[j],a[j+1]);
    }
  }
 for(int i=0;i<n;i++)
 cout<<a[i]<<endl;
}
