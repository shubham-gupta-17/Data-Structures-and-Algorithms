#include <iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int main() {
	int t=1;
	//cin>>t;
	while(t-->0)
	{
	    int n;
	    cin>>n;
	     int arr[]={40, 20, 30, 10, 30};
	    // for(int i=0;i<n;i++)
	    // cin>>arr[i];
	   vector<vector<int>>dp(n,vector<int>(n,0));
	   vector<vector<string>>sdp(n,vector<string>(n,""));
	     for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i==j-1)
                {
                    dp[i][j]=0;
                    sdp[i][j]=(char)(i+'A') ;
                    continue;
                }
                int min_ans=(int)1e9;
                string ans1="";
                for(int cut=i+1;cut<j;cut++)
                {
                    int ans=dp[i][cut]+ arr[i]*arr[cut]*arr[j] +dp[cut][j];
                    if(ans<min_ans)
                    {
                        min_ans=ans;
                        ans1='(' + sdp[i][cut]+sdp[cut][j]+')';
                    }
                }
                dp[i][j]=min_ans;
                sdp[i][j]=ans1;

            }
        }
        cout<<sdp[0][n-1]<<endl;
	}
	return 0;
}