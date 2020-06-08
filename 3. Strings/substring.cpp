#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void subarray()
{
    int a[5]={1,2,3,4,5};
	for(int i=0;i<5;i++)
	{   int n=0;
	    for(int j=i;j<5;j++)
	    {  n=n*10+a[j];
	       cout<<n<<endl;
	    }
	}
}
void substring()
{   string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{   string s1="";
	    for(int j=i;j<n;j++)
	    {   
	        s1+=s[j];
	        cout<<s1<<endl;
	    }
	}

string s="1234";
int n=s.length();
    for(int i=0;i<n;i++)
    {
        for(int cut=1;cut<n-i;cut++)  // cut is basically length hence we are running till equal to n-i
        {
            cout<<s.substr(i,cut)<<" "<<s.substr(i+cut,n-cut)<<endl;
        }
    }
}
void substring1()
{
    string s="123456";
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        for(int cut=1;cut<=n;cut++)
        {   if(i+cut<=n)
            cout<<s.substr(i,cut)<<endl;
        }
    }
}
int main() {
	//cout<<"GfG!";
	subsequence();
	
	return 0;
}