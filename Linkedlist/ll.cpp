#include<iostream>
using namespace std;
class linkedlist
{	private:
	class Node{
	public:
	int data;
	Node * next=NULL;

	Node (int d){
		this.data=d;
	}
};
	private:
	Node *head=NULL;
	Node *tail=NULL;
	int size=0;

	void addfirstNode(Node *node)
	{
		node->next=head;
		head=node;
		size++;
	}
	void addlastNode(Node *node)
	{
		tail->next=node;
		tail=node;
		size++;
	}
	void addatNode(Node *node,int i)
	{	
		Node *current=head;
		for(int i=0;i<i;i++)
		{
			
		}
	}

public:
	int size(){
		return this.size;
	}

	void addfirst(int data)
	{
		Node *node=new Node(data);
		addfirstNode(node);
	}
	void addlast(int data)
	{
		Node *node=new Node(data);
		addlastNode(node);
	}
	void addat(int idx,int data)
	{
		Node*node=new Node(data);
		addatNode(node,idx);
	}

};
int main()
{
	return 0;

}