#include<bits/stdc++.h>
using namespace std;
long  int kadane(int *a, int n)
{
   long  int current_sum=0,max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        current_sum +=a[i];
        if(current_sum>max_sum)
        max_sum=current_sum;

        if(current_sum<0)
        current_sum=0;

    }
    return max_sum;
}
int main()
{   
    int t;
    cin>>t;
    while(t>0){
    int n,k;
    cin>>n>>k;
    int *a=new  int [n*2];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
     long int first_max =0;
      first_max=kadane(a,n);

       for(int i=n;i<n*2;i++)
         a[i]=a[i-n];
   
   long  int second_max=0,max=0,d=0;
   
   if(k==1)
   {
       max=first_max;
   }

  else if(k==2)
   {
       second_max=kadane(a,n*2);
       d=second_max-first_max;
       max=first_max + (k-1)*d;
   }
  /* else if(k>2)
   {
       third_max=kadane(a,n*3);
       second_max=kadane(a,n*2);
       d=-second_max+third_max;
       max = first_max + (k-1)*d;
   }
*/

   cout<<max<<endl;
   

   
  
    t--;
    }
}