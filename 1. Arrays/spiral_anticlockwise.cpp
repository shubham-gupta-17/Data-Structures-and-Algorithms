#include<iostream>
using namespace std;
int main() {

	int n,m;
	int a[100][100];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<m;j++)
	{
	  cin>>a[i][j];
	}
	}
	  int rowfirst=0,rowlast=n-1,columnfirst=0,columnlast=m-1;
	while(rowfirst<=rowlast && columnfirst<=columnlast){
	    int i,j;

      for( i=rowfirst;i<=rowlast;i++)
	  cout<<a[i][columnfirst]<<", ";
	      columnfirst++;

	   for( j=columnfirst;j<=columnlast;j++)
	   cout<<a[rowlast][j]<<", ";   ///i fixed j change
	     rowlast--;

	   for(i=rowlast;i>=rowfirst;i--)
	     cout<<a[i][columnlast]<<", ";
	     columnlast--;

	     for(j=columnlast;j>=columnfirst;j--)
	     cout<<a[rowfirst][j]<<", ";
	     rowfirst++;

	   }
       cout<<"END";

	return 0;
}
