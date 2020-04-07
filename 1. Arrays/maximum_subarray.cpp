#include<iostream>
using namespace std;
void printsubarray(int *arrayaddress,int n)
{    int current_sum =0, greatest_sum=0;
      int left_index =0 , right_index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {      current_sum=0;

                // for printing all the subarrays

              current_sum = *(arrayaddress+j) - *(arrayaddress-(i-1)); // we are using 3 loops : for changing value of array(i), for setting last element (j), for printing(k)


            // for printing the maximum sum of among all subarray but this will have time complexity of n cube.
            if (current_sum>greatest_sum)
            {
                greatest_sum=current_sum;
                  left_index =i;
                  right_index =j;

            }
            //cout<<endl;
        }

    }
    cout<<"Greatest Sum of array is:"<<greatest_sum<<endl;

    cout<<"greatest subarray :";
    for(int k=left_index;k<=right_index;k++){
        cout<<*(arrayaddress+k);  // for printing the subarray with the maximum sum
    }
}
int main()
{
    int a[10];
    int n;
    cin>>n;
    int csum[10]={0};
    cin>>a[0];
    csum[0]=a[0];
    for(int i=1;i<n;i++){

        cin>>a[i];
        csum[i]=csum[i-1]+a[i];
    }
    for(int i=0;i<n;i++)
    cout<<csum[i]<<",";
   printsubarray(csum,n);


   // print max_sum using csum and time complexity n square
  int current_sum=0,greatest_sum=0;
   for(int i=0;i<n;i++)
   {
       for(int j=i;j<n;j++)
       {    current_sum=0;
            current_sum= csum[j]-csum[i-1];

       if(greatest_sum<current_sum)
       {
           greatest_sum=current_sum;
       }
       }
   }
   cout<<endl<<greatest_sum;
    return 0;
}
