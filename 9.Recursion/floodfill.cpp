#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
vector<string> dir_path={"R","L","D","U"};
int jump=1; 
bool is_safe(vector<vector<int>>&board,int r,int c)
{
    if(r<0 || c<0 || r>=board.size() || c>=board.size() || board[r][c])
    return false;

    return true;
}
void floodfill(vector<vector<int>>&board,int sr,int sc,int er,int ec,string ans)
{ 
    if(sr==er && sc==ec){
    cout<<ans<<endl;
      return ;
    }
    
   board[sr][sc]=1;
    for(int i=0;i<dir.size();i++)
    {   
        int nsr=sr+jump*dir[i][0];
        int nsc=sc+jump*dir[i][1];

        if(is_safe(board,nsr,nsc))
        {    
            floodfill(board,nsr,nsc,2,2,ans+dir_path[i]);
        }
    }
    board[sr][sc]=0;
    return;

}
int main()
{
    vector<vector<int>> board(3,vector<int>(3,0));
    string ans=" ";
    floodfill(board,0,0,2,2,ans);
    return 0;   
    
}