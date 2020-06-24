#include<iostream>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
// 115 distinct subsequences
int sub(string s,string t,int i,int j,vector<vector<int>>&dp)
    {
        if(i==s.length() && j==t.length() || j==t.length())
            return dp[i][j]= 1;
        if(i==s.length()) return dp[i][j]= 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int count=0;
        if(s[i]==t[j])
            count+=sub(s,t,i+1,j+1,dp);
        count+=sub(s,t,i+1,j,dp);
        return dp[i][j]= count;
    }
int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
        return sub(s,t,0,0,dp);
    }

//=======================================================================================================================
     int sub(string s,string t,int i,int j,vector<vector<int>>&dp)
    {
        if((i==s.length() && j==t.length()) ||( j==t.length()))
            return dp[i][j]= 1;
        if(i==s.length()) return dp[i][j]= 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        bool count=false;
        if(s[i]==t[j])
            count= count || sub(s,t,i+1,j+1,dp)==1;
        count= count || sub(s,t,i+1,j,dp)==1;
        return dp[i][j]= count ? 1:0;
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(t.length()+1,vector<int>(s.length()+1,-1));
        return sub(t,s,0,0,dp)==1;
    }

 
int main(){

	//115
	cout<<numDistinct("babgbag","bag")<<endl;
	//392
	cout<<isSubsequence("babgbag","bag")<<endl;
}