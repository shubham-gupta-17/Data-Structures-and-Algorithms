#include<bits/stdc++.h>
using namespace std;
//Generating by formula
int dp[100]={0};
int fact(int n)
{
    if(n==1)
        
    return 1;

    if(n==0)
    return 1;

   long long int ans=n*fact(n-1);
    return ans;
}
long long int catalian_series(int n)
{
   long long int ans=(fact(2*n)/(fact(n)*fact(n)*(n+1)));
    return ans;
}
// Generating by function
int catalian_series_02(int n)
{
    if(n==0)
    return 1;
    //overlapping cases and optimization
    if(dp[n]!=0)
    return dp[n];

    int ans=0;
    for(int i=1;i<=n;i++)
    ans+=catalian_series_02(i-1)*catalian_series(n-i);

    dp[n]=ans;

    return ans;

}
int main()
{
    int n;
    //cin>>n;
    
    //generating catalian number
  /*  for(int i=0;i<=n;i++)
    {
        cout<<catalian_series(i)<<" ";
    }
    cout<<fact(10)<<endl<<catalian_series(10)<<endl;*/

    cout<<catalian_series_02(15);
    return 0;
}