#include<iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;

  int a[100];
   for(int i=0;i<n;i++)
   cin>>a[i];

   int key;
   cin>>key;
   int mid,ans=-1;
   int first=0,last=n-1;
   while(first<=last)
   {
       mid=(first+last)/2;
       if(a[mid]==key){
          ans=mid;
          last=mid-1;  /// to find first occurence of number
          first=mid+1; /// to find last occurence of a number

        }

        else if(a[mid]>key)
         last=mid-1;

         else if(a[mid]<key)
         first=mid+1;

   }
   cout<<ans;


}
