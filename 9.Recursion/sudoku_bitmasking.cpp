#include<bits/stdc++.h>
using namespace std;
vector<int>row(9,0);
vector<int> column(9,0);
vector<vector<int>>subgrid(3,vector<int>(3,0));
int countt=0;
void solvesudoku(int box_number,int n,vector<vector<int>>&a)
{
    if(box_number==81)
    {   cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";

            cout<<endl;
        
        }
        cout<<endl;
        countt++;
      return  ;

    }
    int i=box_number/9;
    int j=box_number%9;
    bool res=false;
    if(a[i][j]==0){
    for(int number=1;number<=9;number++)
    {  
        int mask=(1<<number);
        if((row[i]&mask)==0 && (column[j]&mask)==0 && (subgrid[i/3][j/3]&mask)==0)
        {  
            row[i] ^=mask;
            column[j] ^=mask;
            subgrid[i/3][j/3] ^=mask;
            a[i][j]=number;
            // cout<<a[i][j]<<" "<<i<<","<<j<<" "<<box_number<<endl;
             solvesudoku(box_number+1,n,a);
            a[i][j]=0;
            row[i]^=mask;
            column[j]^=mask;
            subgrid[i/3][j/3] ^=mask;
            
        }
           
    }
    
    }
    else 
    {
        solvesudoku(box_number+1,n,a);
    }

    return ;
}
bool find_valid_sudoku(vector<vector<int>> &a)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]!=0)
            {
                int mask=(1<<a[i][j]);
                if((row[i]&mask)==0 && (column[j]&mask)==0 && (subgrid[i/3][j/3]&mask)==0)
                {
                    row[i] |=mask;
                    column[j] |=mask;
                    subgrid[i/3][j/3] |=mask;
                
                }
            }
            
            
           // else return false;
        }
    }

    return true;
}

int main()
{
  vector<vector<int>> a = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  
    cout<<find_valid_sudoku(a);
    solvesudoku(0,9,a);
    cout<<endl<<countt;

}