#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   float ans;
   int mid;
   int s=0,e=n;
   while(s<=e)
   {   mid=(s+e)/2;



       if(mid*mid==n)
      {  ans=mid;
         break;

      }
      else  if(mid*mid<n)
      {  ans=mid;

         s=mid+1;
      }

      else if(mid*mid>n)
        e=mid-1;


   }

   float inc=0.1,p=0;
   while( p<k)
   {
     while(ans*ans<=n){
     ans= ans+inc;
      }
      ans=ans-inc;
      inc=inc*0.1;
      p++;
   }
cout<<ans;

}
