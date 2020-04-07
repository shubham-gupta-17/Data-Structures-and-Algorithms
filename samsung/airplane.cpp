#include<iostream>
using namespace std;
int a[100][5],b[100][5];
void detonate(int row)
{
	if(row-5<0)
		return;

	for(int i=row;i>row-5;i--)
	{
		for(int j=0;j<5;j++)
		{
			b[row-i][j]=0;
			if(a[row][j]==2)
			{
				a[i][j]=0;
				b[row-i][j]=2;
			}
		}
	}
	return ;
}

void undetonate(int row)
{
	for(int i=row;i>row-5;i--)
	{
		for(int j=0;j<5;j++)
		{
			if(b[row-i][j]==2)
				a[i][j]=2;
		}
	}
}
void get_max(int position,int coins,int n,int &max_coins)
{
	if(position<0 || position>4 || coins<0)
		return ;

	if(a[n-1][position]==2) coins-=1;
	else if(a[n-1][position]==1) coins+=1;

	if(n==1) 
	{
		if(coins>max_coins) max_coins=coins;
		return ;
	}
	else 
	{
		get_max(position+1,coins,n-1,max_coins);
		get_max(position-1,coins,n-1,max_coins);
		get_max(position,coins,n-1,max_coins);
		return;

	}

}
int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n,coins=-1,max_coins=-1;
		cin>>n;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<5;j++)
				cin>>a[i][j];
		}

		for(int i=n-1;i>=0;i--)
		{
			//detonate
			coins=-1;
			detonate(i);
			get_max(2,0,n,coins);
			undetonate(i);

			if(coins>max_coins) max_coins=coins;
		}

		cout<< ((max_coins<0) ? -1:max_coins)<<endl;
        t--;
	}
}