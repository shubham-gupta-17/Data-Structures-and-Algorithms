#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;
class student{

	public :
	string first;
	string last;
	string roll;

	student(string f,string l,string r)
	{
		first=f;
		last=l;
		roll=r;

	}
	bool operator==(const student &s) const
	{
		return roll==s.roll?true:false;
	}
};
class Hashfn{

	public :
	size_t operator()(const student &s) const{
	return s.first.length()+s.last.length();	
	}
	
};

int main()
{	
	unordered_map<student,int,Hashfn> smap;
	student s1("shubham","gupta","3161");
	student s2("shubham","kumnar","3161");
	student s3("aka","kym","6727");

	smap[s1]=100;
	smap[s2]=10;
	smap[s3]=120;
	
	cout<<(s1==s2)<<endl;
	for(auto s:smap)
	{
		cout<<s.first.first<<" "<<s.first.last<<" "<<s.first.roll<<endl;
	}
	return 0;

}