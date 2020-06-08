#include<iostream>
using namespace std;
int main()
{
    int array1[100], n,c_sum[100];
    cin>>n;
   // int current_sum=0;
    cin>>array1[0];
    c_sum[0]=array1[0];
    for(int i=1;i<n;i++)
    {
        cin>>array1[i];
       c_sum[i] = c_sum[i-1]+array1[i];
    }
    int left =0 , right =0;
    int current_sum=0, max_sum =0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
              current_sum=0;
              current_sum = c_sum[j]- c_sum[i-1];

              if(current_sum > max_sum)
              {
              max_sum = current_sum;
              left =i;
              right = j;
              }

        }
    }
    cout<<"Maximum sum : "<<max_sum<<endl<<"Subarray with maximum sum :";

    for(int i=left;i<=right;i++)
    {
        cout<<array1[i];
    }


    return 0;
}
