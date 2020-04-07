#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,m;
cin>>t;
m=0;
while(m<t)
{
int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++)
cin>>a[i];

int current_sum=0,max_sum=INT_MIN;
for(int i=0;i<n;i++)
{   current_sum=0;
    int current_number=0;
    int j=i;
   while(current_number<n)
     {
         if(j<n)
        current_sum =a[j]+current_sum;

        else if(j>=n)
        {
          current_sum = current_sum+a[j-n];

        }

        if(current_sum>max_sum)
        max_sum=current_sum;

        else if(current_sum<0)
        current_sum=0;

        current_number++;
        j++;
}

     }

cout<<max_sum<<endl;






m++;
}
}
