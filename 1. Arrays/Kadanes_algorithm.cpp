
#include<iostream>
#include<climits>
using namespace std;
int main() {
int n;
    int *a=new int[n];
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int current_sum=0, max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
       current_sum +=a[i];
        max_sum=max(current_sum,max_sum);
         if(current_sum<0)
          current_sum=0;

    }

    return 0;
}
