#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data,Node*left,Node*right)
    {
        this->data=data;
        this->right=right;
        this->left=left;
    }
};
int i=0;
vector<Node *> c;
Node*create(int a[])
{
    if(a[i]==-1 ){
        i++;
        return NULL;
    }

    Node *node=new Node( a[i],NULL,NULL);
    i++;
    node->left=create(a);
    node->right=create(a);

    return node;
}
 void Inorder(Node *node) {
        if(node==NULL)
            return ;

        Inorder(node->left);
        cout<<node->data<<" ";
        Inorder(node->right);
        return;

}
vector<Node*>e;
void Preoder(Node *node)
{
    if(node==NULL) return ;

    e.push_back(node);
    Preoder(node->left);
    Preoder(node->right);

    return;
}
vector<Node*>d;

void Postorder(Node *node)
{
    if(node==NULL)   return ;

    Postorder(node->left);
    Postorder(node->right);
    d.push_back(node);

    return ;
}
void display(Node *node)
{
   if(node==NULL)
   return;

   string s="";
   s += node->left!=NULL?to_string(node->left->data):"-1";
   s +="->" + to_string(node->data )+ "<-";
   s +=node->right!=NULL?to_string(node->right->data):"-1";

   cout<<s<<endl;
   display(node->left);
   display(node->right);

   return;
}
bool res=false;
vector<Node*> b;
bool find(Node *node,int key)
{
    if(node==NULL)
     return false;

    if(node->data==key){
        b.push_back(node);
     return true;
    }

    res=find(node->left,key) || find(node->right,key);
    if(res)
    b.push_back(node);

    return res;
}
int maximum_in_tree(Node*root)
{
    if(root==NULL)
    return 0;

    return max(root->data,max(maximum_in_tree(root->left),maximum_in_tree(root->right)));
}
int height(Node *node)
{
    if(node==NULL)
    return 0;

    return max(height(node->left),height(node->right))+1;

}
int diameter(Node *node)
{
    if(node==NULL)
    return 0;

    if(node->left==NULL && node->right==NULL)
    return 0;

   int ld=diameter(node->left);
   int rd=diameter(node->right);

   int lh=height(node->left);
   int rh=height(node->right);
/*it has a time complexity of O(n^2) because for every node we are calculating height and calculation
 of height take O(n) time so for calculating diameter of n nodes will take O(n^2) time.*/

    return max(max(ld,rd),lh+rh+1);
}
class Pair{
    public:
    int height;
    int diameter;
};
Pair fast_diameter(Node *root)
{   Pair p;
    if(root==NULL)
    {
       p.height=p.diameter=0;
       return p;
    }
/* O(n) because using pair we are calculating both height and diameter at a single time traversing
  each node only once */
    Pair left=fast_diameter(root->left);
    Pair right=fast_diameter(root->right);

    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height+1,max(left.diameter,right.diameter));
    return p;
}
bool rootTonode(Node *node,int key,vector<Node*>&base)
{
    if(node==NULL)
    return  false;

    if(node->data==key)
    { base.push_back(node);
        return true;
    }

    bool ans=false;
     ans=ans || rootTonode(node->left,key,base)|| rootTonode(node->right,key,base);
     if(ans){
     base.push_back(node);
     return true;
     }

    return false;
}
vector<Node*> *rootTonode2(Node *node,int key)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->data==key)
    { vector<Node*>*base=new vector<Node*>();
      base->push_back(node);
        return base;
    }

    vector<Node*>*left=rootTonode2(node->left,key);
    if(left!=NULL)
    {
        left->push_back(node);
        return left;
    }
     vector<Node*>*right=rootTonode2(node->right,key);
    if(right!=NULL)
    {
        right->push_back(node);
        return right;
    }
    return NULL;
}
vector<Node*> roottonode3(Node*node,int key){

    if(node==NULL) //udacity and coursera on tensorflow
    {
        vector<Node*> arr;
        return arr;
    }

    if(node->data==key)
    {
        vector<Node*>base;
        base.push_back(node);
        return base;
    }

    vector<Node*> left=roottonode3(node->left,key);
    if(left.size()!=0)
    {
        left.push_back(node);
        return left;
    }

    vector<Node*> right=roottonode3(node->right,key);
    if(right.size()!=0)
    {
        right.push_back(node);
        return right;
    }

    vector<Node*> arr;
    return arr;
}
int LCA(Node *root)
{
    vector<Node*> LCA1=roottonode3(root,100);
    vector<Node*> LCA2=roottonode3(root,60);
    int prev=-1;
    int i=LCA1.size()-1;
    int j=LCA2.size()-1;
    while(LCA1.at(i)->data==LCA2.at(j)->data)
    {
        prev=LCA1.at(i)->data;
        i--;
        j--;
    }
    return prev;
}

 queue<Node*>* leveloder(Node*root)
{  
   queue<Node*>* que =new queue<Node*>();
   queue<Node*>base;
   base.push(root);
    que->push(root);
   while(!base.empty())
   {   Node*node = base.front();
       base.pop();
      if(node->left!=NULL){
      base.push(node->left);
      que->push(node->left);
      }
    
      if(node->right!=NULL){
       base.push(node->right); 
       que->push(node->right);
      }  

        // is it possible to push more than 2 elements in queue.
    }
    
  return que;
}
bool res2=false;
void kaway(Node *root,int data,int k)
{  
    if(root==NULL)
    return;

    if(k==0)
    {
        cout<<root->data<<" ";

    }

    if(root->data==data || res2==true)
    {   res2=true;

        kaway(root->left,data,k-1);
        kaway(root->right,data,k-1);
        return ;
    }
    else{
    kaway(root->left,data,k);
    kaway(root->right,data,k);
    return ;

    }

    return ;

}
bool path(Node *root,int data,vector<Node*>&arr2)
{
    if(root==NULL)
    return false ;

    if(root->data==data){
    arr2.push_back(root);
    return true;
    }

    bool ans=false;
    ans=ans || path(root->left,data,arr2) || path(root->right,data,arr2);

    if(ans)
    arr2.push_back(root);

    return ans;
}
void kaway2(Node *root,Node *node,int k)
{
    if(root==NULL || root==node)
    return ;

    if(k==0)
    cout<<root->data<<" ";

    kaway2(root->left,node,k-1);
    kaway2(root->right,node,k-1);
}
void kdown(Node *root,int data,int k)
{   vector<Node*> arr;
    path(root,data,arr);
    Node *node=NULL;
    for(Node*n:arr)
    cout<<n->data<< " ";
    cout<<arr.size()<<endl<<endl;
    for(int i=0;i<arr.size();i++){
    kaway2(arr.at(i),node,k-i);
    node=arr.at(i);
    }

    return ;
}
 void leveloder2(Node*root)
{  queue<Node*> que;
   que.push(root);
   que.push(NULL);
   while(!que.empty())
   {   Node*node = que.front();
        que.pop();
      cout<<node->data<<" ";
      if(node->left!=NULL)
      que.push(node->left);

      if(node->right!=NULL)
      que.push(node->right);

      if(que.front()==NULL)
      {
          que.pop();
          cout<<endl;
          if(!que.empty())
          {
              que.push(NULL);
          }
      }

    }
  return ;
}
/*void levelorder03(Node *root)
{
    list<Node *> que;
    que.addlast(root->data);
    int level=1;
    while(que.size>0)
    {   
        cout<<level<<"-> ";
        int size=que.size();
        while(size>0)
        {
            Node *node=que.removefirst();
            cout<<node->data;
            if(node->left!=NULL)
            que.addlast(node->left);

            if(node->right!=NULL)
            que.addlast(node->right);

            size--;
        }
        level++;
        cout<<endl;

    }
}*/
int sum(Node*root)
{
    if(root==NULL)
    return 0;
    int ls=sum(root->left);
    int rs=sum(root->right);
    if(root->left!=NULL || root->right!=NULL)
    {
        root->data=ls+rs;
    }
    return root->data+ls+rs;
}
vector<int>  leet_inorder(Node *root,vector<int>level)
{
    if(root==NULL)
    return level;

    leet_inorder(root->left,level);
    level.push_back(root->data);
    leet_inorder(root->right,level);

    return level ;
}
int main()
{
  int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    Node *root=create(a);
    display(root);
    cout<<endl;
   /* Inorder(root);
    cout<<endl;
    vector<int> level;
    vector<int>level1=leet_inorder(root,level);
    for(int n:level1)
    cout<<n<<" ";

    int key;
    cin>>key;
    cout<<find(root,key)<<endl;

    for(Node*n:b)
    cout<<n->data<<"->";

    cout<<endl<<"HEIGHT:"<<height(root)<<endl<<"DIAMETER: "<<diameter(root)<<endl<<"INORDER: ";

    Inorder(root);
    for(Node*n:c)
    cout<<n->data<<" ";

 /*   cout<<endl<<"POSTORDER: ";
    Postorder(root);
    for(Node *n:d)
    cout<<n->data<<" ";

    cout<<endl<<"PREORDER:";
    Preoder(root);
    for(Node*n:e)
    cout<<n->data<<" ";

    cout<<endl;

    vector<Node*> base;
    cout<<rootTonode(root,key,base)<<endl<<"rootTonodepath_1:";
    for(Node*n:base)
    cout<<n->data<<" ";


    cout<<endl<<"ROOT_TO_NODE_PATH 2: ";
    vector<Node*>*path=rootTonode2(root,key);
    for(Node*n:*path)
    cout<<n->data<<"->";

    cout<<endl<<"ROOT TO NODE PATH 3: ";
    vector<Node*> path2=roottonode3(root,key);
    for(Node*n:path2)
    cout<<n->data<<"->";

    cout<<endl<<LCA(root)<<endl;  //least common ancestor
    
    queue<Node*>*bus=leveloder(root);
    while(!bus->empty()){
    cout<<bus->front()->data<<" ";
     bus->pop();
    }



cout<<endl;
Node *root=arr();
display(root);
cout<<endl;
leveloder2(root);

 cout<<maximum_in_tree(root)<<endl;
 leveloder2(root);
 cout<<endl;
 sum(root);
 cout<<endl;
 leveloder2(root);
 


  kaway(root,10,2); //print all elements at k distance from data
  */

 kdown(root,60,2);
    return 0;


}
