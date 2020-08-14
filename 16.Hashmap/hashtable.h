#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class Node{

public:
	string key;
	T value;
	Node<T>* next;

	Node(string key,T value)
	{
		this->key=key;
		this->value=value;
		next=NULL;
	}

	~Node()
	{
		if(next!=NULL)
			delete next;
	}
};

template<typename T>
class hashtable{


	Node<T>**table;
	int current_size;
	int table_size;
	int hashfunction(string key)
	{
		int idx=0;
		int p=1;
		for(int i=0;i<key.length();i++)
		{
			idx=idx + (key[i]*p)%table_size;
			idx=idx%table_size;
			p=(p*27)%table_size;
		}
		return idx;
	}

	void rehasing()
	{
		
		Node<T>**old=table; // now we have created old pointer bcoz our class is written wrt to table so we need to resize table with new table array
		int old_size=table_size;
		table_size=2*table_size;
		table=new Node<T>*[table_size];

		for(int i=0;i<table_size;i++)
			table[i]=NULL;

		current_size=0;

		for(int i=0;i<old_size;i++)
		{
			Node<T>* node=old[i];
			while(node!=NULL)
			{
				insert(node->key,node->value);
				node=node->next;
			}

			if(old[i]!=NULL)
				delete old[i];
		}

		delete [] old;

	}
public:
	hashtable(int table_size)
	{
		this->table_size=table_size;
		table=new Node<T>*[this->table_size];
		current_size=0; // because at this point we have created hashtable and have not inserted anything in that
		// in c++ when we create an array it contains garbage value or point to any memory location hence we need to make it to point to null
		for(int i=0;i<table_size;i++)
			table[i]=NULL;    // it will help us to find which table contains a linked list or not

	}

	int size(){
		return current_size;	
	}
	

	void insert(string key, T value)
	{
		int idx=hashfunction(key);

		Node<T>* node=new Node<T>(key,value);
		// insert node at head of linked list
		node->next=table[idx];
		table[idx]=node;
		current_size++;

		/* insert at tail
		Node<T>* prev=table[idx];
		while(prev->next!=NULL)
			prev=prev->next;
		prev->next=node;*/


		// Rehashing
		float load_factor=current_size/(1.0*table_size);

		if(load_factor>0.5)
		{
			rehasing();
		}



	}

	void print()
	{
		for(int i=0;i<table_size;i++)
		{	cout<<i<<"->";
			if(table[i]!=NULL)
			{	
				Node<T>* p=table[i];
				while(p!=NULL)
				{
					cout<<p->key<<"->";
					p=p->next;
				}
			}
			cout<<endl;

		}

	}

	T* search(string key)
	{
		int idx=hashfunction(key);
		Node<T>* node=table[idx];
		while(node!=NULL)
		{
			if(node->key==key)
				return &node->value;
			node=node->next;
		}
		return NULL;
	}

	T& operator[] (string key)
	{
		T* find= search(key);
		if(find==NULL)
		{
			T garbage;
			insert(key,garbage);
			find=search(key);
		}

		return *find;
	}

};
