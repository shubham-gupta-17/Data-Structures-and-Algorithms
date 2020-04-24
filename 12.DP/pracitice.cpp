#include<bits/stdc++.h>
using namespace std;
string dp[100][100]={""};
int len=0;
int st=0;
int en=0;
string ans="";
/*int find(string&s,int i,int j)
{
	if(i>j) return dp[i][j]=0;

	if(i==j) {
		if(len<1){
			len=1;
			st=en=i;
		}
		return dp[i][j]=1;
	
	}

	int ans=0;
	if(s[i]==s[j])
	{
		ans=find(s,i+1,j-1);
		if(ans!=0){
		ans+=2;
		if(len<ans){
			st=i;
			en=j;
			len=ans;
		}
		}
	}
	find(s,i,j-1);
	find(s,i+1,j);

	return dp[i][j]=ans; 
}*/
void find1(string&s)
{
	for(int gap=0;gap<s.length();gap++)
	{
		for(int i=0,j=gap;j<s.length();i++,j++)
		{
			if(gap==0) dp[i][j]=s[i];
			else if(s[i]==s[j] && gap==1) dp[i][j]=s[i]+dp[i-1][j]+s[j];
			else if(s[i]==s[j] &&dp[i+1][j-1]!="")
			dp[i][j]=s[i]+dp[i+1][j-1]+s[j];

			if(len<dp[i][j].length())
			{
				len=dp[i][j].length();
				ans=dp[i][j];

			}
		}
	}
}
int main()
{
	string s="babaddtattarrattatddetartrateedredi";
	find1(s);
	for(int i=0;i<45;i++)
	{
		for(int j=0;j<45;j++)
			cout<<dp[i][j]<<" ";

		cout<<endl;
	}
	cout<<endl<<len<<endl<<ans;
	return 0;

}