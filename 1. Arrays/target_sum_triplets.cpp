#include<iostream>
#include<algorithm>
using namespace std;
void findsum(int *a,int n,int key)
{
 for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[i]+a[j]+a[k]==key)
				cout<<a[i]<<", "<<a[j]<<" and "<<a[k]<<endl;
			}
		}
	}
}
void findsum2(int *a,int n,int key)
{
  for(int i=0;i<n;i++)
  {  int left =i+1,right=n-1;
    while(left<right)
    {
       if(a[i]+a[left]+a[right]==key)
         {
           cout<<a[i]<<", "<<a[left]<<" and "<<a[right]<<endl;
           left++;
           right--;
         }

         else if(a[i]+a[left]+a[right]>key)
         right--;

         else if(a[i]+a[left]+a[right]<key)
         left++;
    }

  }
}
int main() {
	int n,a[1000],key;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];

	cin>>key;
	sort(a,a+n);
	//findsum(a,n,key);  //using 3 loops
	findsum2(a,n,key);  // using 2 loops
  return 0;
}
