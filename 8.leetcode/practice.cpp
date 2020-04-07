#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
vector<string> path={"R","L","D","U"};
int jump=1;
bool is_safe(vector<vector<int>> &box,int r,int c)
{
    if(r>=box.size() || c>=box.size()|| r<0||c<0 || box[r][c])
    return false;

    return true;
}
void floodfill(vector<vector<int>>&box,int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc==ec)
    {   cout<<ans<<endl;
        return;
    }
    
    box[sr][sc]=1;
    for(int i=0;i<dir.size();i++)
    {   int nsr=sr+jump*dir[i][0];
        int nsc=sc+jump*dir[i][1];

        if(is_safe(box,nsr,nsc))
        {
            floodfill(box,nsr,nsc,box.size()-1,box[0].size()-1,ans+path[i]);
        }
    }
    box[sr][sc]=0;
    return ;
}
int main()
{   vector<vector<int>> box(3,vector<int>(3,0));
     cout<<box.size()<<box[0].size();
    floodfill(box,0,0,box.size()-1,box[0].size()-1," ");
    return 0;
}