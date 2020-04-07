#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int neighbour; //neighbour of a particular vertex
    int weight;

    Edge(int u,int w):neighbour(u),weight(w){};
};

vector < vector < Edge* > > graph(9,vector<Edge*>());
int n=9;

void addEdge(int row,int column,int weight)
{
    graph[row].push_back(new Edge(column,weight));
   // graph[column].push_back(new Edge(row,weight));
}
void display()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" ->";
        for(Edge *n:graph[i])
        {
            cout<<n->neighbour<<" "<<n->weight<<", ";
        }
        cout<<endl;
    }
}
int allpath(int source,int destination,string ans,vector<bool> &mark)
{
    if(source==destination)
    {
        cout<<ans+" "+to_string(destination)<<endl;
        return 1;
    }
   
    int count=0;

    for(Edge*n:graph[source])
    {
        if(!mark[source])
        {    mark[source]=true;  //if we don't mark it than it will keep on moving in a cycle
            count+=allpath(n->neighbour,destination,ans+" "+to_string(source),mark);
             mark[source]=false;
        }
    }
      
    return count;

}
void create()
{
    addEdge(0,1,10);
    addEdge(0,3,10);
    addEdge(1,2,10);
    addEdge(2,3,40);
    addEdge(3,4,2);
    addEdge(4,5,2);
    addEdge(4,6,8);
    addEdge(5,6,3);
    //addEdge(5,7,70);
    addEdge(7,8,100);
}
void BFS_topologicalsort(int i,vector<bool>&mark1)
{   
    queue<int> que;
    que.push(i);
    while(!que.empty())
    {
            int vtx=que.front();
            que.pop();
            cout<<vtx<<" ";

        if(mark1[vtx])
        {
            cout<<"Circular :"<<i<<" "<<vtx<<endl;
            continue;
        }

            mark1[vtx]=true;
            for(Edge *n:graph[vtx])
            {
                if(!mark1[n->neighbour]){
                que.push(n->neighbour);
               // mark1[n->neighbour]=true;
                }

            }
        
    }
   return ;

}
void GCC()
{   
    vector<bool> mark1(graph.size(),false);
    int countt=0;

    for(int i=0;i<graph.size();i++)
    {
        if(!mark1[i]){
        BFS_topologicalsort(i,mark1);
        countt++;
        }
    }
    cout<<"GCC: "<<countt;
}
void topology_DFS(int vtx, vector<bool>&mark, vector<int>&stack)
{
    mark[vtx]=true;

    for(Edge* e:graph[vtx])
    {
        topology_DFS(e,mark,stack);
    }
    stack.push_back(vtx);
}
int main()
{
    create();
    vector<bool>mark(9,false);
    display();
    cout<<"NUMBER OF ALL PATHS:"<<allpath(0,6," ",mark)<<endl;

    GCC();

    vector<bool> mark(graph.size(),false);
    vector<int> stack;
    for(int i=0;i<n;i++)
    {
        if(!mark[i])
        {
            topology_DFS(i,mark,stack);
        }
    }




    return 0;
}