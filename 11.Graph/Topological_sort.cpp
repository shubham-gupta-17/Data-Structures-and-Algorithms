#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(9,vector<int>());
void addEdge(int vertex,int neighbour)
{
   graph[vertex].push_back(neighbour);
   return ;
}
void create()
{
    addEdge(0,1);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(4,5);
    addEdge(4,6);
    addEdge(5,6);
    addEdge(5,7);
    addEdge(7,8);
    addEdge(8,0);
    return ;
}
void display()
{
    for(int i=0;i<graph.size();i++)
    {   cout<<i<<"-> ";
        for(int neighbour:graph[i])
        cout<<neighbour<<" ";

        cout<<endl;
    }
    return ;
}
void topo_dfs(int src,vector<bool>&mark,vector<int>&stack)
{   
    for(int neighbour : graph[src])  // doing topological using dfs
    {   if(!mark[neighbour]){
         mark[neighbour]=true;
        topo_dfs(neighbour,mark,stack);
    }
       
    }
    stack.push_back(src);
}
void dfs()
{   vector<bool> mark(graph.size(),false);
    vector<int> stack;
    for(int i=0;i<graph.size();i++)
    {
        if(!mark[i]){
            mark[i]=true;
        topo_dfs(i,mark,stack);
        }
    }

    for(int i=stack.size()-1;i>=0;i--)
    cout<<stack[i]<<" ";
}
void khan_bfs()
{   vector<int> incoming_edges(graph.size(),0);
    for(int i=0;i<graph.size();i++) // doing topological sort using bfs
    {
        for(int j:graph[i])
        { 
            incoming_edges[j]++;
        }
    }
    queue<int> q;
    queue<int> ans;
    vector<bool> mark(graph.size(),false);
    for(int i=0;i<graph.size();i++)
    {
        if(incoming_edges[i]==0)
        {
            q.push(i);
            mark[i]=true;
        }
    }
    
    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(int i: graph[top])
        {
            incoming_edges[i]--;

            if(incoming_edges[i]==0)
            q.push(i);
        }
    }

    for(int i=0;i<=graph.size();i++)
    {   cout<<incoming_edges[i]<<" ";
        if(incoming_edges[i]!=0)
        {
            cout<<"IS CYCLIC"<<endl;
            break;
        }
        else
        {
            continue;
        }
        
    }
}
void cycle_bfs(int i , vector<bool> &mark)
{  
    queue<int> q;
    q.push(i);
   
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        
        if(mark[top])
        {
            cout<<"Cycle is Present between :"<<i<<" "<<top;
        }

        mark[top]=true;
        for(int j: graph[top])
        {
            if(!mark[j])
            q.push(j);
        }

    }

}
bool cyclic_dfs(int i, vector<bool> &mark,vector<bool> &stack,vector<int> &st)
{
    mark[i]=true;
    stack[i]=true;
    bool res=false;
    for(int neigh: graph[i])
    {
        // if(!mark[neigh] && cyclic_dfs(neigh,mark,stack) || stack[neigh]==true)
        // return true;
        if(!mark[neigh]  && !res)
        {
            res =res || cyclic_dfs(neigh,mark,stack,st);
        }

         else if(stack[neigh])
        return true;

    }
    st.push_back(i);
    stack[i]=false;
    return res;
    
}
int main()
{
    create();
    display();
    dfs();  // this is topology dfs
    cout<<endl;
    khan_bfs();

    // cycle detection:
    // using bfs
    vector<bool>mark(graph.size(),false);
    for(int i=0;i<graph.size();i++)
    {   
        if(!mark[i])
        {
            cycle_bfs(i,mark);
        }

    }
    
   // cycle detection using dfs
    vector<bool> mark1(graph.size(),false);
    vector<bool> stack ;
    vector<int> st;
    bool res=false;
    for(int i=0;i<graph.size() && !res;i++)
    {
        if(!mark1[i]){
      //  res=res || cyclic_dfs(i,mark1,stack,st);

        if(res)         // find out whether cycle is present or not 
        cout<<"CYCLIC";
        }
        
    }

}