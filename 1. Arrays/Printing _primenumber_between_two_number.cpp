#include<iostream>
using namespace std;
int main() {
	int k=1;
	int t;
	cin>>t;
	while(k<=t)
	{
		int n,m;
		cin>>n>>m;
		for(int i=n+1;i<=m;i++)
		{  int   count=0;
			for(int j=2;j<i;j++)
			{
				if(i%j==0)
				{   count++;
					break;
				}
               
			}
            if(count==0)
            cout<<i<<",";
		}
        cout<<endl;
		k++;
	}
	return 0;
}