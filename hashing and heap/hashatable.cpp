#include<iostream>
#include<cstring>
#include"hashtable.h"
using namespace std;
int main()
{	
	int table_size=7;
	hashtable<int> map(table_size);
	map.insert("burger",100);
	map.insert("pepsi",110);
	map.insert("pizza",120);
	map.insert("ashu",130);
	map.insert("sande",140);
	map.insert("arvidn",150);
	map.insert("haugd",160);
	map.insert("mango",160);
	cout<<map.size()<<endl;
	map.print();
	cout<<map.size();

	int *value=map.search("pzza");
	if(value!=NULL)
		cout<<*value<<endl;

	else
		cout<<"NOT FOUND"<<endl;

	map["mango"]+=100;
	cout<<map["mango"];
	return 0;
}