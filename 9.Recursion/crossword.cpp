#include<bits/stdc++.h>
using namespace std;
bool is_safe(vector<vector<int>>&board,int r,int c)
{	
	vector<vector<int>> dir={{0,-1},{-1,0},{-1,-1},{-1,1}};
	for(int d=0;d<4;d++)
	{
		for(int j=1;j<=board.size();j++)
		{
			int nr=r+ j*dir[d][0];
			int nc=c+ j*dir[d][1];
			if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() &&board[nr][nc]==1)
				return false;

		}
	}
	return true;

}
vector<vector<string>> ans;
void nqueen(vector<vector<int>>&board,int r,int c,int n,int tq)
{
	if(n==tq){
		vector<string> as;
		for(int i=0;i<n;i++)
		{	string s="";
		for(int j=0;j<n;j++){

			if(board[i][j]==1)
			{
				s+="Q";
			}
			else
			s+=".";
		}
		as.push_back(s);
		}
		ans.push_back(as);
		return;
	}

	for(int col=0;col<n;col++)
	{
		if(is_safe(board,r,col))
		{
			board[r][col]=1;
			nqueen(board,r+1,col,n,tq+1);
			board[r][col]=0;
		}
	}
	return ;
}
int main()
{	
	int n=4;
	vector<vector<int>> board(n,vector<int>(n,0));
	nqueen(board,0,0,n,0);
	
	for(vector<string>s:ans)
	{
		for(string a : s)
			cout<<a<<endl;

		cout<<endl;
	}

	return 0;
}