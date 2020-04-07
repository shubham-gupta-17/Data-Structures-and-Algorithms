#include<iostream>
#include<algorithm>
using namespace std;
void findpair(int*a,int n,int key)
{
   for(int i=0;i<n;i++)
	{  	for(int j=i;j<n;j++)
		{
			if(a[i]+a[j]==key)
			cout<<a[i]<<" and "<<a[j]<<endl;

		}
	}
}
void findpair2(int *a,int n,int key)
{
  int left=0,right=n-1;
  while(left<right)
  {
   if(a[left]+a[right]==key){
   cout<<a[left]<<" and "<<a[right]<<endl;
   left++;
   right--;

   }

   else if (a[left]+a[right]>key)
   right--;

   else if(a[left]+a[right]<key)
   left++;

  }
}
int main() {
	int n;
	cin>>n;
	int a[1000],key;
	for(int i=0;i<n;i++)
	cin>>a[i];

      cin>>key;
      sort(a,a+n);
      findpair(a,n,key);   // it is a bruteforce method with O(n^2)
      findpair2(a,n,key);   // with complexity O(n)
	return 0;

}
