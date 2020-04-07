#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left=NULL;
    Node*right=NULL;

    Node(int data,Node*left,Node*right)
    {
        this->data=data;
        this->left=left;
        this->right=right;
    }


};
int i=0;
Node*create(int a[])
{
    if(a[i]==-1){
        i++;
        return NULL;
    }

    Node*node=new Node(a[i],NULL,NULL);
    i++;
    node->left=create(a);
    node->right=create(a);

    return node;

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
/*Node *LCA_inBst(Node*node,int a,int b)
{

    if(node->data<a)
     return LCA_inBst(node->right,a,b);
     else if(node->data>b)
     return LCA_inBst(node->left,a,b);
     else
     {
         if(find(node,b) && find(node,b))
         return node;
     }
     return NULL;
     
}*/
//int b[20]={0};
vector<int> b(21,0);
void vertical_traversal_lefttoright(Node *root,signed int level)
{   if(root==NULL)
     return;
     // b[level].push_back(b[level]+root->data);
     b[level]+=root->data;
     // int *max_level=new int;
      //int *min_level=new int;

    //  min_level=min(max_level,level);
     // max_level=max(level,max_level);

    vertical_traversal_lefttoright(root->left,level+1);
    vertical_traversal_lefttoright(root->right,level-1);
    return ;
}
/*int subsq(Node *node,int Potentialvalue , int currentlen)
{
    if(node==NULL)
    return 0;

    if(node->data==Potentialvalue)
    currentlen++;

    else 
    currentlen=1;

    int max1=subsq(node->left,Potentialvalue+1,currentlen);
    int max2=subsq(node->right,Potentialvalue+1,currentlen);

    return max(currentlen,max1,max2);
]

}*/
int main()
{   int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    Node*root=create(a);
     display(root);
    vertical_traversal_lefttoright(root,0);
    cout<<endl;
    int m=sizeof(b)/sizeof(int);
    for(int i=-2;i<3;i++)
    cout<<b[i]<<" ";

   // cout<<min_level<<endl<<max_level;
    return 0;

}