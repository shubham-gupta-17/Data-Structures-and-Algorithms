#include<iostream>
using namespace std;
class Node{
	public :
	int data;
	Node*next=NULL;
	Node*prev=NULL;

	Node(int d)
	{
		this.data=d;
	}

};
Node *insert(int data,Node*root)
{
	if(root==NULL)
		return NULL;

	Node*root=new Node(data);
	
}
int main()
{

}