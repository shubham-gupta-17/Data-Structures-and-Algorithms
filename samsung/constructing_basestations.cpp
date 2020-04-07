#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> even={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,0}};
vector<vector<int>> odd={{0,-1},{-1,0},{0,1},{1,1},{1,0},{1,-1}};
vector<vector<bool>> vis;
int max1=0;
	
void tower(int r,int c,int tower_no,int current_tower,vector<vector<int>> &a,int ans,int n,int m)
{
	if(current_tower==tower_no)
	{
		if(ans>max1) max1=ans;
		return ;
	}

		vis[r][c]=true;
		ans+=a[r][c];
		if(c%2==0){

		for(int j=0;j<6;j++)
		{
			int nr=r+even[j][0];
			int nc=c + even[j][1];
		if(nr>=0 && nr<n && nc>=0 &&nc<m && !vis[nr][nc])
		{
			vis[nr][nc]=true;
			tower(nr,nc,tower_no,current_tower+1,a,ans,n,m);
			vis[nr][nc]=false;
		}
	}
	}
	else{

		for(int j=0;j<6;j++)
		{
			int nr=r+odd[j][0];
			int nc=c + odd[j][1];
		if(nr>=0 && nr<n && nc>=0 &&nc<m && !vis[nr][nc])
		{
			vis[nr][nc]=true;
			tower(nr,nc,tower_no,current_tower+1,a,ans,n,m);
			vis[nr][nc]=false;
		}
	 }
	 }
	return ;

}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a;
	vector<int> b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	int c;
			cin>>c;
			b.push_back(c);
		}
		a.push_back(b);
	}
	vis.resize(n,vector<bool>(m,false));
	tower(0,0,4,0,a,0,n,m);
	cout<<max1;
	return 0;
}