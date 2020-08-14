#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void map1_basic()
{
	unordered_map<string,int> map;
	
	//put
	map["ind"]=10;
	map["usa"]=100;
	map["russia"]=1000;

	//get
	cout<<map["shubham"]<<endl;  // never do this as it will put shubham in hashmap too hence use map.count;
	cout<<map.count("shubham")<<endl; // it returns 0/1 if present or not

	//erase
	if(map.count("shubham")) map.erase("shubham");
	if(map.erase("delhi")) map.erase("delhi"); // first check whether it is present in hashmap or not then erase

	for(pair<string,int> p: map)
	{
		cout<<p.first<<" "<<p.second<<endl;
		map[p.first]+=100; // it will increase the value by 100;
	}
	for(pair<string,int> p: map)
	{
		cout<<p.first<<" "<<p.second<<endl;
		
	}
	return ;
}
void frequency_map(string&s)
{	
	unordered_map<char,int> map;
	for(int i=0;i<s.length();i++)
	{
		map[s[i]]++;
	}
	for(pair<char,int> p:map)
		cout<<p.first<<" "<<p.second<<endl;

	return;
}
void character_index(string s)
{
	unordered_map<char,vector<int>> map;
	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		map[ch].push_back(i);
	}
	for(pair<char,vector<int>> p: map){
		cout<<p.first<<"->";
		  for(int i=0;i<p.second.size();i++) 
		  	cout<<p.second[i]<<", ";
		cout<<endl;
	}
}
int main()
{
	//map1_basic();
	string s="abbcdabbbbabbbacde";
	//frequency_map(s);
	character_index(s);
	return 0;
}