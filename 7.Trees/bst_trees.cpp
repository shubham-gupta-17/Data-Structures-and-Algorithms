#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data =0;
    Node*left =NULL;
    Node *right=NULL;

   Node (int d):data(d),left(NULL),right(NULL){}; 

};
Node*createBST(Node *root,int data)
{  // with this method we can not create a balanced binary tree
    if(root==NULL)
    return new Node(data);

    if(data>=root->data)
    root->right=createBST(root->right,data);

    if(data<=root->data)
    root->left=createBST(root->left,data);

    return root;
}
void display(Node *root)
{
    if(root==NULL)
    return ;

    string s=" ";
    s+=root->left==NULL?"-1":to_string(root->left->data);
    s+="->" + to_string(root->data) + "<-";
    s+= root->right==NULL ? "-1":to_string(root->right->data);
    cout<<s<<endl;
    display(root->left);
    display(root->right);
    return ;

}
void preorder(Node *root)
{
    if(root==NULL)
    return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
int height(Node *root)
{
    if(root==NULL)
    return 0;

    return max(height(root->left),height(root->right))+1;
}
void levelorder1(Node *root,int level)
{   
    if(root==NULL)
    return ;

    if(level==1){
    cout<<root->data<<" ";
    return ;
    }
    levelorder1(root->left,level-1);
    levelorder1(root->right,level-1);
    return;
}
void inorder(Node *root)
{
    if(root==NULL)
    return ;

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    return ;

}
void levelorder2(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {   
        Node *node=q.front();
        q.pop();
        cout<<node->data<<" ";

        if(node->left!=NULL)
        q.push(node->left);

        if(node->right!=NULL)
        q.push(node->right);

        if(q.front()==NULL)
        {
            q.pop();
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
    }
    
    return;
}
int number_of_nodes(Node *root)
{
    if(root==NULL)
    return 0;

    return  number_of_nodes(root->left)+number_of_nodes(root->right)+1;
}
int sum_of_nodes(Node *root)
{
    if(root==NULL)
    return 0;

    return  sum_of_nodes(root->left)+sum_of_nodes(root->right)+root->data;
}
// Passing pair by value
pair<int,int> fast_diameter(Node *root)
{   pair<int,int> p;
    if(root==NULL)
    {
       p.first=p.second=0;
       return p;
    }
    
    pair<int,int> left=fast_diameter(root->left);
    pair<int,int> right=fast_diameter(root->right);

    p.first=max(left.first,right.first)+1;
    p.second=max(left.first+right.first+1,max(left.second,right.second));
    return p;
}
/*pair<int,int>*fast_diameter(Node *root)
{   pair<int,int> *p=new pair<int,int>();  // passing pair by reference
    if(root==NULL)
    {
       p->first=p->second=0;
       return p;
    }
    
    pair<int,int> *left=fast_diameter(root->left);
    pair<int,int> *right=fast_diameter(root->right);

    p->first=max(left->first,right->first)+1;
    p->second=max(left->first+right->first+1,max(left->second,right->second));
    return p;
}*/
int sum(Node *root)
{
    if(root==NULL)
    return 0;
   
    int ls=sum(root->left);
    int rs=sum(root->right);
    int data=root->data+ls+rs;
     if(root->left!=NULL || root->right!=NULL)
    { 
      root->data=ls+rs;   
    }

    return data;
}
bool BST_search_DFS(Node*root,int data)
{
    if(root==NULL)
    return false;
    
    if(data==root->data)
    return true;
    
    if(data>root->data)
    return BST_search_DFS(root->right,data);

    else 
    return BST_search_DFS(root->left,data);

}
bool BST_search_BFS(Node *root,int data)
{
       while(root!=NULL)
       { 
           if(root->data==data)
           return true;

           else if(root->data<data)
           root=root->right;

           else
           {
               root=root->left;
           }
       }
       return false;
}
int i=0;
Node *create_BST2(int pre[],int in[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    
    Node*root1=new Node(pre[i]); 
    for(int j=start;j<=end;j++)
    {   
        if(pre[i]==in[j])
        {   i++;
            root1->left=create_BST2(pre,in,start,j-1);
            root1->right=create_BST2(pre,in,j+1,end);
            return root1;

        }   
    }
    return root1;
}
Node* delete1(Node *root,int data)
{
    if(root==NULL)
    return NULL;

    if(root->data==data)
    {   // if has no children
         if(root->left==NULL && root->right==NULL){
         delete root;
         return NULL;
         }
        //if has one children
         else if(root->left!=NULL && root->right==NULL)
         {
             Node *temp=root;
             delete root;
             return temp->left;
         }
         else if(root->left==NULL && root->right!=NULL)
         {
             Node *temp=root;
             delete root;
             return temp->right;
         }
        //if has 2 childre
         Node *replace=root->right;
         while(replace->left!=NULL)
         replace=replace->left;

         root->data=replace->data;
         root->right=delete1(root->right,replace->data);
         return root;
    }

    if(data>root->data)
    root->right=delete1(root->right,data);

    else
    {
        root->left=delete1(root->left,data);
    }

    return root;
    
}
bool check_for_BST_02(Node *root,int min,int max)
{
    if(root==NULL)
    return true;


    if(root->data>min && root->data < max &&check_for_BST_02(root->left,min,root->data) && check_for_BST_02(root->right,root->data,max) )
    return true;

    else 
    return false;
}
class linkedlist
{   public:
    Node *head=tail;
    Node *tail=tail;
};
linkedlist flattern(Node *root)
{    linkedlist node;
     if(root==NULL){
     //linkedlist empty;
     return node;
     }
     if(root->right==NULL && root->left==NULL)
     {
         //linkedlist leaf;
         node.head= node.tail=root;
         return node;
     }
     if(root->left!=NULL && root->right==NULL)
     {
         linkedlist leftll =flattern(root->left);
         leftll.tail->right=root;
         node.head=leftll.head;
         node.tail=root;

         return node;
     }
     if(root->right!=NULL && root->left==NULL)
     {
         linkedlist rightll=flattern(root->right);
         root->right=rightll.head;

         node.head=root;
         node.tail=rightll.tail;
         return node;
     }
    //  if(root->right!=NULL && root->left!=NULL)
      
          linkedlist leftll=flattern(root->left);
          linkedlist rightll=flattern(root->right);
         // linkedlist node;
          leftll.tail->right=root;
          root->right=rightll.head;

          node.head=leftll.head;
          node.tail=rightll.tail;
          return node;
      

}
void push(Node *root,stack<Node*>*s)
{   if(root==NULL)
    return ;

    while(root!=NULL)
    {
        s.push(root);
        root=root->left;
    }
    return ;

}
void inorder_stack(Node *root)
{
     stack<Node*> *s=new stack<Node*>();
     push(root,s);
     while(s.size()!=0)
     {
        Node *node=s.pop();
        cout<<node->data;
        push(node->right,s);
     }
     return ;
}
void flat_using_vector(Node *root,vector<int>& f)
{
    if(root==NULL)
    return ;


}
int main()
{
    int n=6;
    //cin>>n;
   // int *a=new int[n];
    Node *root=NULL;
    int a[]={10,5,1,7,40,50};
    for(int i=0;i<n;i++){
   // cin>>a[i];
     root=createBST(root,a[i]);
    }
   display(root);
 /*  cout<<endl<<"PREORDER : ";
   preorder(root);
   int h=height(root);
   cout<<endl<<h<<endl<<"LEVELORDER 1:";

   for(int i=1;i<=h;i++)
   {
       levelorder1(root,i);
       cout<<endl;
   }
   cout<<"LEVELORDER 2:";
   levelorder2(root);
  
   cout<<endl;
    cout<<"Number of Nodes:"<<number_of_nodes(root)<<endl;

    cout<<"Sum of Nodes:"<<sum_of_nodes(root);

    pair<int,int> p=fast_diameter(root);
    cout<<endl<<p.first<<" "<<p.second;

    pair<int,int>*p=fast_diameter(root);
    cout<<p->first<<" "<<p->second;

levelorder2(root);
//sum(root);
cout<<endl;
//delete1(root,10);
cout<<endl;
levelorder2(root);
cout<<check_for_BST_02(root,INT_MIN,INT_MAX);
*/
inorder(root);
cout<<endl;
linkedlist flat_bst=flattern(root);

Node *temp=flat_bst.head;
while (temp!=NULL)
{
    cout<<temp->data<<endl;
    temp=temp->right;
}
    
    vector<int> flattern_vector;
    flat_using_vector(root,flattern_vector);

}