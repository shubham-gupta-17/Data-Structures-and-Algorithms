#include<bits/stdc++.h>
using namespace std;
int main()
{
	//int a[][]={{1,4,7,11},{8,9,10,20},{11,12,17,30}};
	int a[][4]={{1,2,3,4},{5,6,7,8},{10,11,12,13}};
	int i=0;
	int start=0;
	int end=11;
	int mid=0;
	int r,c;
	int n=8;
	while(start<=end)
	{
		mid=(start+end)/2;
		r=mid/4;
		c=mid%4;

		if(a[r][c]==n)
		{
			cout<<r<<endl<<c;
			break;
		}

		else if(a[r][c]>n)
		{
			end=mid-1;
		}

		else start=mid+1;


	}
	return 0;
}