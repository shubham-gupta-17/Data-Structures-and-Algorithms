#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left=NULL;
    Node *right=NULL;

    Node (int d):data(d){};
};
int i=0;
Node *create(int *a,int n)
{
    if(a[i]==-1){
        i++;
    return NULL;
    }
    Node *node = new Node(a[i]);
    i++;
    node->left=create(a,n);
    node->right=create(a,n);

    return node;

}
void display(Node *node)
{
  if(node==NULL)
  return ;

  string s="";
//   ans += node->left!=NULL?to_string(node->left->data):"-1";
//   ans +=  "->" +to_string(node->data) + "<- ";
//   ans += node->right!=NULL?to_String(node->right->data):"-1";
   s += node->left!=NULL?to_string(node->left->data):"-1";
   s +="->" + to_string(node->data )+ "<-";
   s +=node->right!=NULL?to_string(node->right->data):"-1";


  cout<<s<<endl;
  display(node->left);
  display(node->right);
  return;
}
class linkedlist{
    public:
    Node *head;
    Node *tail;
};
linkedlist flattern(Node *root)
{
    linkedlist node;
    if(root==NULL)
    {
        return node;

    }
    else if (root->left ==NULL && root->right == NULL )
    {
        node.head = node.tail = root; 
        return node;
    }

    else if (root->left==NULL && root->right !=NULL)
    {   linkedlist rightll=flattern(root->right);
        root->right=rightll.head;
        node.head=root;
        node.tail=rightll.tail;
        return node;
    }
    else if(root->left!=NULL  && root->right ==NULL)
    {
        linkedlist leftll= flattern(root->left);
        leftll.tail->right=root;
        node.head=leftll.head;
        node.tail=root;
        return node;
    }

    linkedlist leftll=flattern(root->left);
    linkedlist rightll=flattern (root->right);

    root->right = rightll.head;
    leftll.tail->right=root;
    node.head=leftll.head;
    node.tail=rightll.tail;
    return node;
}
Node *createBST(int data,Node *root)
{
    if(root==NULL)
    {
        Node *node=new Node(data);
        return node;
    }

    if(data<=root->data){
    root->left =createBST(data,root->left);
    }

    else if (data > root->data){
    root->right=createBST(data,root->right);
    }  

    return root; 
}
int j=0;
Node *createBST2(int in[],int pre[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }

    int temp=pre[j];
    int index=0;
    for(int i=0;i<.8;i++)
    {
        if(in[i]==temp)
        {
                index=i;
        }
    }
    Node *root=new Node (pre[j]);
    j++;
    root->left=createBST2(in,pre,s,index-1);
    root->right=createBST2(in ,pre,index+1,e);

    return root;


}
vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> level1(10,vector<int>());
        queue<Node*> que;
        int i=0;
        que.push(root);
        level1[i].push_back(root->data);
        while(!que.empty())
        {   int level=que.size();
             i++;
            while(level>0){
            Node *top=que.front();
            que.pop();
            cout<<top->data<<" ";
                
                if(top->left!=NULL){
                    que.push(top->left);
                    level1[i].push_back(top->left->data);   
                }
                
                if(top->right!=NULL)
                {
                    que.push(top->right);
                    level1[i].push_back(top->right->data);
                }
                
                level--;
            }
            cout<<endl;
        
        }
        
        return level1;
 }
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    cin>>a[i];
    Node*root= create(a,n);
    display(root);

    vector<vector<int>> level1=levelOrder(root);
    cout<<endl;
    for(int i=0;i<level1.size();i++)
    {
        for(int j=0;j<level1[i].size();j++)
        cout<<level1[i][j]<<" ";

        cout<<endl;
    }
//     linkedlist flat = flattern(root);
//    Node * temp= flat.head;
//    while(temp!=NULL)
//    {
//        cout<<temp->data<<" ";
//        temp=temp->right;
//    }
   

//    //create bst using in and pre
//    int in[]={1,2,3,4,5,6,7,8};
//    int pre[]={8,6,4,2,1,3,5,7};
//    Node *root2=createBST2(in,pre,0,7);
//    cout<<endl;
//    display(root2);


//     // create using array
//     int b[]={1,2,3,4,5,6,7,8};
//     Node *root1=NULL;
//     for(int i=0;i<8;i++)
//     {
//         root1=createBST(b[i],root1);
//     }

//     cout<<endl;
//     display(root1);
}