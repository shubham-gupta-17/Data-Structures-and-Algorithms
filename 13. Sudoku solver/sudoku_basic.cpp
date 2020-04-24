#include<bits/stdc++.h>
using namespace std;
bool is_true(int **a,int n,int row,int column,int number)
{  
    for(int col=0;col<n;col++)
    {
        if(a[row][col]==number)
        return false;
    }
    for(int ro=0;ro<n;ro++)
    {
        if(a[ro][column]==number)
        return false;
    }

    int start=(row/3)*3;
    int end=(column/3)*3;

    for(int i=start;i<start+3;i++)
    {
        for(int j=end;j<end+3;j++)
        {
            if(a[i][j]==number)
            return false;
        }
    }

    return true;

}
void sudoku(int **a,int n,int box)
{  if(box==n*n)
    {    cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";

            cout<<endl;
        }
        return ;
    }
  
   int row=box/n;
   int column = box%n;
   
   if(a[row][column]==0){
   for(int number=1;number<=9;number++)
   {
       if(is_true(a,n,row,column,number))
       {   a[row][column]=number;
           sudoku(a,n,box+1);
           a[row][column]=0;
       } 

   }
   }
   else sudoku(a,n,box+1);

   return;  

}
int main()
{
    int n;
    cin>>n;
    /*vector<vector<int>> a = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};



     vector<vector<int>> a(3,vector<int>(3,0));  //how to take inputs in vector in 2D
   for(int i=0;i<3;i++)
   {   for(int j=0;j<3;j++)
   {
       int x;
       cin>>x;
       a[i][j]=x;
   }
   */




    
    int **a=new int*[n];
    for(int i=0;i<n;i++)
    a[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }

    
   //fun(a);
   sudoku(a,n,0);
}