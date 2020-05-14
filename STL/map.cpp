#include<iostream>
#include<map>
#include<cstring>
using namespace std;
void create_map()
{
	map<string,int> set;

// ways to insert
	//1.
	set.insert(make_pair("mango",1000));

	//2.
	pair<string,int> p;
	p.first="apple";
	p.second=100000;
	set.insert(p);

	//3.
	set["bannan"]=1000;

//find
	string key="apple";
	map<string,int>::iterator m=set.find(key);  // it is an iterator which will iterate over set and find whether that key is present or not, this return iterator
	if(m!=set.end()) cout<<endl<<set[key]<<endl;  // if key is present than print the value else print not present
	else cout<<"not present"<<endl;

//update
	if(set.count(key)) set[key]+=40;
	
//print
	//1.foreach loop
	for(pair<string,int> p:set)
		cout<<p.first<<" "<<p.second<<endl; // it will print in sorted order

	//2. iterator
	for(auto it =set.begin();it!=set.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
		// or use  
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}

//erase
	auto it=set.find(key);
	set.erase(it);
	
	
	return;
}
void create_multimap()
{
	multimap<char,string> set;
	int n=8;
	for(int i=0;i<n;i++)
	{
		char ch;
		string s;
		cin>>ch>>s;
		set.insert(make_pair(ch,s));
	}

	multimap<char,string>::iterator it=set.begin();
	set.erase('a');   // it will erase all the  all the key values with a;
	cout<<it->first<<" "<<it->second<<endl;
	set.erase(it);	  // it will rease 1st index of multimap


	auto it1=set.lower_bound('b');  // it will give the 1st index of key with b

	auto it2=set.upper_bound('d');  // it will give the index of next key after d but keep in mind that d must not be the last element in map as it will run the print loop upto infinite
	
	for(auto it3=it1;it3!=it2;it3++)
		cout<<it3->first<<" "<<it3->second<<endl; // it will print all key value pairs between key =b to key=d;

	cout<<endl;
	for(pair<char,string> p:set)
		cout<<p.first<<" "<<p.second<<endl; 


	//find
	auto f=set.find('c');
	if(f->second=="cat")
		set.erase(f);

	cout<<endl;
	for(pair<char,string> p:set)
		cout<<p.first<<" "<<p.second<<endl; 


}
int main()
{
	//create_map();
	create_multimap();
	return 0;

}