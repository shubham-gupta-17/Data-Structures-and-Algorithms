#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dir={{0,1},{1,0},{1,1}};
vector<string> d={"H","D","V"};
vector<string> mazepath01(int sr,int sc,int er,int ec)
{
	if(sr==er && sc==ec)
	{
		vector<string>arr;
		arr.push_back("");
		return arr;
	}
	vector<string> ans;
	for(int i=0;i<dir.size();i++)
	{	int r=sr+dir[i][0];
		int c=sc+dir[i][1];
		//cout<<"1";
		if(r<=er && c<=ec){
		vector<string> arr=mazepath01(r,c,er,ec);
		
		for(string s:arr)
		{
			string s1=d[i]+s;
			ans.push_back(s1);
		}
		}

	}
	return ans;

}
int mazepath_HVD_02(int sr,int sc,int er,int ec,string ans)
{	
	if(sr==er && sc==ec)  // here we don't have to mark anything because the directions are always in forward direction
	{
		cout<<ans<<endl;
		return 1;
	}
	int count=0;
	if(sc+1<=ec)
		count+=mazepath_HVD_02(sr,sc+1,er,ec,ans+"H");

	if(sr+1<=er && sc+1<=ec)
		count+=mazepath_HVD_02(sr+1,sc+1,er,ec,ans+"V");
	if(sr+1<=er)
		count+=mazepath_HVD_02(sr+1,sc,er,ec,ans+"D");

	return count;
}
int main()
{

	cout<<mazepath_HVD_02(0,0,2,2," ")<<endl;
	vector<string>arr=mazepath01(0,0,2,2);
	for(string s: arr)
		cout<<s<<endl;

	return 0;
}