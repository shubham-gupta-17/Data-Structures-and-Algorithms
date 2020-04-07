#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a[100][100];

   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
       cin>>a[i][j];
   }


   for(int j=0;j<n;j++)
   {
      for(int i=n-1;i>=0;i--)
      cout<<a[i][j]<<" ";

      cout<<endl;
   }
   /// if we want to do rotate the matrix in the original one
   ///1. do transpose of the matrix
   ///2. make mirror image of that

   /// transpose
   for(int i=0;i<n;i++)
   {
      for(int j=i;j<n;j++)
      {
          if(i!=j)
          swap(a[i][j],a[j][i]);

      }
   }

  ///to make mirror image of the transpose matrix
   for(int i=0;i<n;i++)
   {
      int first=0;
      int last =n-1;
      while(first<last)
      {
         swap(a[i][first],a[i][last]);
         first++;
         last--;
      }
   }
   cout<<endl<<endl;

   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
       cout<<a[i][j]<<" ";

       cout<<endl;
   }


}
