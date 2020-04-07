#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>graph(10,vector<int>());
void addedge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    return;
}
void create()
{
    addedge(0,1);
    addedge(1,2);
    addedge(1,4);
    addedge(3,4);
    addedge(4,5);
    addedge(5,6);
    addedge(5,7);
    addedge(5,8);
    addedge(5,9);
    addedge(8,9);
    
    return ;
}
int n=graph.size();
vector<bool> vis(graph.size(),false);
vector<int> lowest;
vector<int> discovery;
vector<int> parent(graph.size(),0);
int level =0;
int ap=0;
void DFS(int src)
{  
    vis[src]=true;
    lowest[src]=discovery[src]=level;
    level++;
    for(int j:graph[src])
    {
        if(!vis[j])
        {   
            if(parent[j]==-1)
            {
                parent[j]=src;
            }
            DFS(j);

            if(discovery[src]<=lowest[j])
            ap++;
            lowest[src]=min(lowest[src],lowest[j]);
        }

        else 
        {
            lowest[src]=min(discovery[j],lowest[src]);
        }
    }
    return ;
}
void display()
{
    for(int i=0;i<n;i++)
    {   cout<<i<<" ->";
        for(int j:graph[i])
        cout<<j<<" ";

        cout<<endl;
    }
    return ;
}
void arti()
{
    for(int i=1;i<graph.size();i++)
    {
        if(!vis[i])
        {
            DFS(i);
        }
    }
    return ;
}
int main()
{   create();
    display();
   arti();
   // for(int i=0;i<articulation.size();i++)
    //cout<<i<<" " << articulation[i];
    cout<<ap;
    return 0;
}
