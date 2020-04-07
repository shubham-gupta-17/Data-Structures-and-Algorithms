#include<bits/stdc++.h>
using namespace std;
//int jump=1;
/*
vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
vector<string> dir_s={"R","L","D","U"};
bool isSafe(int nsr,int nsc,vector<vector<int>>&graph,int er,int ec)
{
    if(nsr>=0 && nsc>=0 && nsr<=er && nsc<=ec && graph[nsr][nsc]==0)
    return true;

    return false;
}
// bool isSafe(vector<vector<int>>&board,int r,int c)
// {
//     if(r<0 || c<0 || r>=board.size() || c>=board.size() || board[r][c])
//     return false;

//     return true;
// }
void floodfill(vector<vector<int>> &graph,int sr,int er,int sc,int ec,string ans)
{   
        if(sr==er && sc==ec)
        {
            cout<<ans<<endl;
            return ;
        }

        graph[sr][sc]=1;
        
        for(int i=0;i<dir.size();i++)
        {   
            for(int jump=1;jump<=3;jump++){
            int nsr=sr+jump*dir[i][0];
            int nsc=sc+jump*dir[i][1];

            if(isSafe(nsr,nsc,graph,er,ec))
            {   
                floodfill(graph,nsr,er,nsc,ec,ans+dir_s[i]);

            }
        }
        }
        graph[sr][sc]=0;
        return ;

}
int main()
{
    vector<vector<int>> graph(3,vector<int>(3,0));
    floodfill(graph,0,2,0,2," ");
    return 0;
}

//=====================================================================================================
// nqueen
vector<vector<int>> dir={{-1,0},{0,-1},{-1,1},{-1,-1},{1,0},{0,1},{1,-1},{1,1}};
bool is_safe(vector<vector<int>> &board,int r,int c)
{
    for(int i=0;i<dir.size();i++)
    {
        for(int jump =1;jump<=board.size();jump++)
        {   int nr = r+jump*dir[i][0];
            int nc=c +jump*dir[i][1];

            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc])
            {
                return false;
            }
        }
    }
    //cout<<"yes"<<endl;
    return true;

}
void nqueen(vector<vector<int>>&board,int queen,int total,int box,string ans)
{
    if(queen==total){
       // cout<<"BASE"<<endl;
    cout<<ans<<endl;
    return ;
    }


    for(int i=box;i<board.size()*board[0].size();i++)
    {
        int nr=i/board.size();
        int nc=i%board[0].size();

       
        if(is_safe(board,nr,nc) && !board[nr][nc])
        {    board[nr][nc]=1;
            nqueen(board,queen+1,total,i+1,ans+" queen"+to_string(queen) +"box:"+to_string(nr)+" "+to_string(nc));
             board[nr][nc]=0;
        }

    }
    return;

}
int main()
{
    vector<vector<int>> board(4,vector<int>(4,0));
    int queens=4;
    nqueen(board,1,5,0," ");

}
/=====================================================================================================
//bipartite and print 
bool isbi(int src,vector<vector<int>>&graph,vector<int>&color)
{
    queue<pair<int,int>> que;
    que.push({src,0});
    bool ans=true;
    while(!que.empty())
    {
        pair<int,int> vertex=que.front();
        que.pop();
        int u=vertex.first;
        int c=vertex.second;
        if(color[u]!=-1)
        {
            if(color[u]!=c){
            ans=false;
            }

            else 
            continue;
        }
        color[u]=c;
        for(int neighbour:graph[u])
        {  
            if(color[neighbour]==-1)
            {
                que.push({neighbour,(c+1)%2});
            }

            else if(color[neighbour]!=(c+1)%2)
            ans=false;

        }

    }
    return ans;


}

bool solve(vector<vector<int>>&graph)
{
    vector<int> color(graph.size(),-1);
    bool ans=true;
    for(int i=0;i<graph.size();i++)
    {
        if(color[i]==-1)
        {
            ans=isbi(i,graph,color);
        }
    
    }
    vector<int> a1;
    vector<int> a2;
    for(int i=0;i<color.size();i++)
    {
        if(color[i]==0)
        a1.push_back(i);

        else if(color[i]==1)
        a2.push_back(i);

    }

    for(int i=0;i<a1.size();i++)
    cout<<a1[i]<<" ";

    cout<<endl;

   for(int i=0;i<a2.size();i++)
    cout<<a2[i]<<" ";
    
    cout<<endl;
    return ans;
}
int main()
{
    vector<vector<int>>graph={{3,1},{0,2},{1,3},{0,2,4},{3,5,6},{4,6},{4,5}};
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<" ->";
        for(int j:graph[i])
        cout<<j<<", ";

        cout<<endl;
    }
  
    cout<<solve(graph);

    
    

    return 0;
}


//==========================================================================================
// print left and right sum
class Node 
{
    public:
    signed int data;
    Node *left=NULL;
    Node *right=NULL;

    Node(signed int d):data(d){};

};
int i=0;
Node* create(signed int a[])
{   if(a[i]==-1){
    i++;
   return NULL; 
}

   Node * node=new Node(a[i]);
   i++;
   node->left=create(a);
   node->right=create(a);

   return node;
}
void dis(Node *node)
{
    if(node==NULL)
    return ;

    string s="";
    s+= node->left!=NULL?to_string(node->left->data):"-1";
    s+= " ->"+to_string(node->data) +"<-";
    s+= node->right!=NULL?to_string(node->right->data):"-1";
    cout<<s<<endl;

    dis(node->left);
    dis(node->right);

    return ;
}
int sum(Node *root)
{   
    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    {   int d=root->data;
        root->data=0;
        return d;
    }

   
   int lsum= sum(root->left);
    int rsum =sum(root->right);
    int d=root->data;
    root->data =lsum+rsum;

    return d+lsum+rsum;



}
void pre(Node *root)
{
    if(root==NULL)
    return ;

    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);

    return ;
}
int main()
{
    int n;
    cin>>n;
   signed int *a=new signed int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    Node *root=create(a);
    dis(root);
    sum(root);
    cout<<endl;
    dis(root);
    cout<<endl;
    pre(root);
    
}

//========================================================================================
// return size of largest bst in a binary tree
class Node 
{
    public:
    signed int val;
    Node *left=NULL;
    Node *right=NULL;

    Node(signed int d):data(d){};

};
void dis(Node *node)
{
    if(node==NULL)
    return ;

    string s="";
    s+= node->left!=NULL?to_string(node->left->data):"-1";
    s+= " ->"+to_string(node->data) +"<-";
    s+= node->right!=NULL?to_string(node->right->data):"-1";
    cout<<s<<endl;

    dis(node->left);
    dis(node->right);

    return ;
}
// create using array
Node *create(int data,Node*root)
{
    if(root==NULL)
    {
        Node *node=new Node(data);
        return node;

    }


    if(data<=root->data){
    root->left=create(data,root->left);
   // return root->left;
    }

    if(data>root->data){
    root->right=create(data,root->right);
   // return root->right;
    }

    return root;
}
class max_size
{
    public:
    bool ans=false;
    int size=0;
    int min=INT_MAX;
    int max=INT_MIN;
    max_size()
    {

    }
    max_size(int s,bool a,int mx,int mn)
    {
        size=s;
        ans=a;
        max=mx;
        min=mn;
    }
};
int max_size1=0;
max_size find(Node *root)
{
    if(root==NULL)
     return max_size(0,true,INT_MIN,INT_MAX);

     if(root->left==NULL && root->right==NULL)
     return max_size(1,true,root->data,root->data);

    max_size bst1=find(root->left);
    max_size bst2 = find(root->right);
    max_size bst;
    if(bst1.max<=root->data && root->data>bst2.min && bst1.ans && bst2.ans)
    {
        bst.ans=true;
        bst.size=bst1.size+bst2.size+1;
        max_size1=max(bst.size,max_size1);
        bst.min=bst1.min;
        bst.max=bst2.max;

    }
    else 
    {   bst.ans=false;
        bst.size=bst1.ans=true ? bst1.size:bst2.size;
        max_size1=max(bst.size,max_size1);
        return bst;
    }
    return bst;
}
Node *create2(int *pre,int *in,int start,int end)
{
    if(start>end)
    return NULL;

    int index=0;
    int static j=0;
    for(int i=start;i<=end;i++)
    {
        if(in[i]==pre[j])
        index=i;
    }
   
    Node *node= new Node(pre[j]);
     j++;
     node->left=create2(pre,in,start,index-1);
     node->right=create2(pre,in,index+1,end);
    return node ;

}
int main()
{
// {
//     //int n;
//     cin>>n;
//     int *a=new int[n];
//     for(int i=0;i<n;i++)
//     cin>>a[i];

//     Node *root=NULL;
//     for(int i=0;i<n;i++)
//     {
//         root=create(a[i],root);
//     }

//     dis(root); edge[0].first=1;
      edge[0].second=2;
    int pre[]={8,3,1,6,4,7,10,14,13};
    int in[]={1,3,4,6,7,8,10,13,14};
    int n=sizeof(pre)/sizeof(int);
    Node *root2=create2(pre,in,0,8);
    cout<<endl;
    dis(root2);

    max_size sizee=find(root2);
    cout<<sizee.size;
    cout<<endl<<max_size1;
    return 0 ;

}

//===================================================================================================
// Disjoint union set
vector<vector<int>> graph(7,vector<int>());
vector<pair<int,int>> edge;
void create(int a,int b)
{
         
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {   
        cout<<i<<" ->";
        //for(int j=0;j<graph[i].size();i++)
        for(int j:graph[i])
        cout<<j<<" ";

        cout<<endl;
    }
}
vector<int> parent(7,0);
vector<int> sizee(7,1);
void merge(int a,int b)
{
    if(sizee[a]<sizee[b])
    {
        parent[a]=b;
        sizee[b]+=sizee[a];
    }
    else
    {
        parent[b]=a;
        sizee[a]+=sizee[b];
    }
    
}
bool bi(int src,vector<int>&color)
{
    queue<pair<int,int>> que;
    que.push({src,0});
    color[src]=0;
    while(!que.empty())
    {
        pair<int,int> p=que.front();
        int u=p.first;
        int c=p.second;
        que.pop();

        if(color[u]!=c)
        return false;


        for(int neighbour:graph[u])
        {
            if(color[neighbour]==-1)
            {
                que.push({neighbour,(c+1)%2});
                color[neighbour]=(c+1)%2;
            }

            else if(color[neighbour]!=(c+1)%2)
            return false;
        }

    }

    return true;

}
bool ans()
{
    vector<int> color(7,-1);
    bool ans=false;
    for(int i=0;i<7;i++)
    {
        if(color[i]==-1)
        {
            ans=bi(i,color);

            
        }
        if(!ans)
        return false;

    }

    return true;

}
int path_compression(int u)
{
    if(parent[u]==u)
    return u ;
    
    parent[u]=path_compression(parent[u]);
    return parent[u];
}
int main()
{   int a[]={0,0,1,1,2,2,3,3,4,4,5,5,6,6,};
    int b[]={1,3,0,2,1,3,0,2,5,6,4,6,4,5};

    for(int i=0;i<14;i++)
    graph[a[i]].push_back(b[i]);

    // bipartite
    cout<<ans();

// disjoint union set:
    // cout<<endl;
   

    for(int i=0;i<7;i++)
    parent[i]=i;
    
    for(int i=0;i<14;i++)
    merge(a[i],b[i]);

    for(int i=0;i<7;i++)
    cout<<parent[i]<<" ";
    
    cout<<endl;
    for(int i=0;i<7;i++)
    cout<<i<<" ->"<<path_compression(i)<<endl;

    int gcc=1;
    for(int i=0;i<6;i++)
    {
        if(parent[i]!=parent[i+1])
        gcc++;
    }
    cout<<gcc<<endl;
    display();
}
//================================================================================================
// find the cycle khans
vector<vector<int>> graph(7,vector<int>());

int main()
{
   
     int a[]={0,0,1,1,2,2,3,3,4,4,5,5,6,6,};
    int b[]={1,3,0,2,1,3,0,2,5,6,4,6,4,5};

    for(int i=0;i<14;i++)
    graph[a[i]].push_back(b[i]);

    vector<int> edges;
    for(int i=0;i<14;i++)
    {
        edges[b[i]]++;
    }
        queue<int> que;
    for(int i=0;i<edges.size();i++)
    {
        if(edges[i]==0)
        {
            que.push(i);
        }
    }


}
*/
//=================================================================================================

