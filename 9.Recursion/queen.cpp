#include<bits/stdc++.h>
using namespace std;
void queen_2D_combination(vector<vector<int>>&box,int total_queens,int current_queen,int current_box,string ans)
{
    if(current_queen==total_queens+1)
    {
        cout<<ans<<endl;
        return ;
    }

    for(int i=current_box;i<box.size()*box[0].size();i++)
    {   int r=i/box.size();
        int c=i%box[0].size();
        if(r>=0 && r<box.size() && c>=0 && c<box[0].size()){
         box[r][c]=1;
        queen_2D_combination(box,total_queens,current_queen+1,i+1,ans+"box"+to_string(i)+" queen"+to_string(current_queen)+" ");
         box[r][c]=0;
        }

    }
    return;
}
void queen_combinations(vector<int> &boxes,int start_box,int current_queen,int total_queens,string ans)
{
    if (current_queen==total_queens+1)
    {
        cout<<ans<<endl;
        return ;
    }

    for(int i=start_box;i<boxes.size();i++)
    {
        queen_combinations(boxes,i+1,current_queen+1,total_queens,ans +"box"+to_string(i)+"queen"+to_string(current_queen));
    }
    return;
}
void queen_2D_permutation(vector<vector<int>>&box,int total_queens,int current_queen,int current_box,string ans)
{
    if(current_queen==total_queens+1)
    {
        cout<<ans<<endl;
        return ;
    }

    for(int i=current_box;i<box.size()*box[0].size();i++)
    {   int r=i/box[0].size();
        int c=i%box[0].size();
        if(r>=0 && r<box.size() && c>=0 && c<box[0].size() && !box[r][c]){
         box[r][c]=1;
        queen_2D_combination(box,total_queens,current_queen+1,0,ans+"box"+to_string(i)+" queen"+to_string(current_queen)+" ");
         box[r][c]=0;
        }

    }
    return;
}
void queen_permutation(vector<int> &boxes,int start_box,int current_queen,int total_queens,string ans)
{
    if (current_queen==total_queens+1)
    {
        cout<<ans<<endl;
        return ;
    }

    for(int i=start_box;i<boxes.size();i++)
    {   if(!boxes[i]){
        boxes[i]=1;
        queen_combinations(boxes,0,current_queen+1,total_queens,ans +"box"+to_string(i)+"queen"+to_string(current_queen));
        boxes[i]=0;
    }

    }
    return;

}

// vector<vector<int>> dir={{-1,0},{0,-1},{-1,1},{-1,-1},{1,0},{0,1},{1,-1},{1,1}};
vector<vector<int>> dir={{0,-1},{-1,0},{-1,-1},{-1,1}};
bool is_safe(vector<vector<int>>&boxes,int r,int c)
{
    for (int d = 0; d < dir.size(); d++)
    {
        for (int jump = 1; jump <= boxes.size(); jump++)
        {
            int nr = r + jump * dir[d][0];
            int nc = c + jump * dir[d][1];

           if (nr >= 0 && nc >= 0 && nr < boxes.size() && nc < boxes[0].size() && boxes[nr][nc])
             return false;

          /* if( nr<0 || nc <0 || nr>=boxes.size() || nc>=boxes[0].size() )
           {
               if(boxes[nr][nc])
               return true
           }*/

        }
    }

    return true;
}
void nqueen(vector<vector<int>> &box,int start_box,int current_queen,int total_queens,string ans)
{
      if(current_queen==total_queens)
      {   cout<<ans<<endl;
          return ;
      }
      for(int i=start_box;i<box.size()*box[0].size();i++)
      {       int nr= i/box.size();
              int nc= i%box[0].size();

              if(is_safe(box,nr,nc) && !box[nr][nc]){
                  box[nr][nc]=1;

          nqueen(box,i+1,current_queen+1,total_queens,ans+"  queen"+to_string(current_queen)+" box"+to_string(nr)+","+to_string(nc));
              box[nr][nc]=0;

      }
      }
      return;
}
int main()
{
    int queens=3;
   vector<vector<int>> box(4,vector<int>(4,0));
    vector<int> boxes(5,0);
    nqueen(box,0,0,4," ");
   // queen_2D_combination(box,queens,1,0," ");
    cout<<endl;
    //queen_combinations(boxes,0,1,3," ");
    cout<<endl;
   // queen_2D_permutation(box,queens,1,0," ");
    cout<<endl;
   // queen_permutation(boxes,0,1,3," ");
    return 0 ;
}
