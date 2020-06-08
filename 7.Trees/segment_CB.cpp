#include<iostream>
#include<vector>
using namespace std;
struct segmenttree{

	vector<int> st;
	void build(int n){
		st.resize(4*n,0);
	}
	

	int build(int start,int end,int node,int a[])
	{	
		//leaf node base case
		if(start==end)
			return st[node]=a[start];

		int mid=(start+end)/2;
		//left child
		build(start,mid,2*node+1,a);
		//right child
		build(mid+1,end,2*node+2,a);

		return st[node]=st[2*node+1]+st[2*node+2];
	}
};
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	segmenttree tree;
	tree.build(n);
	tree.build(0,n-1,0,a);

	for(int i=0;i<4*n;i++)
		cout<<tree.st[i]<<" ";

}