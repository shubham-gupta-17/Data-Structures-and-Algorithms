#include<bits/stdc++.h>
using namespace std;
int search(int a[],int n,int s,int e,int key)
{
   ///base case
   if(s>e)
   return -1;

   ///recursive case
     int mid=(s+e)/2;
     if(a[mid]==key)
     return mid;

     if(a[mid]>=a[s])
     {
        if(key>=a[s] && key<=a[mid])
        return  search(a,n,s,mid-1,key);

         else
        return  search(a,n,mid+1,e,key);
     }

     else if(a[mid]<=a[e])
     {
        if(key>=a[mid] && key<=a[e])
       return  search(a,n,mid+1,e,key);

        else
        return search(a,n,s,mid-1,key);
     }



}
int main() {
	int n;
	cin>>n;

	int *a=new int[n];
	for(int i=0;i<n;i++)  cin>>a[i];

	int key;
	cin>>key;
	cout<<search(a,n,0,n-1,key);
}
