#include<bits/stdc++.h>
using namespace std;
class Graph{
    int vertex;
    list<int>*l;

    public:
    Graph(int v){
        vertex=v;
        //Array of list
        l=new list<int>[v];
    }

    void addEdge(int u,int v,bool dir)
    {
    l[u].push_back(v);
    // if(dir)
    // l[v].push_back(u);
    }

    void print()
    {
        for(int i=0;i<vertex;i++)
        {   cout<<i<<"->  ";
            for(int vert:l[i])
            cout<<vert<<" ";

            cout<<endl;
        }
    }

    void bfs(int src)
    {
        vector<int> mark(9,false);
        queue<int> q;
        q.push(src);
        mark[src]=true;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            cout<<top<<" ";

            for(int it:l[top])
            {   if(!mark[it])
            {
                q.push(it);
                mark[it]=true;
            }

            }

        }
    }
};
template<typename T>
class Graph_genric{
   map<T,vector<T>> adjlist;
   public:
   void addedge(T vertex,T neighbour,bool dir)
   {
       adjlist[vertex].push_back(neighbour);
       if(dir)
       adjlist[neighbour].push_back(vertex);
   }

   void print()
   {
       for(auto i:adjlist)
       {
           cout<<i.first<<"->";
           for(T j:i.second)
           cout<<j<<" ";

           cout<<endl;
       }
   }

   void bfs(T src)
   {
       queue<T> q;
       map<T,bool> visited;
       q.push(src); 
       visited[src]=true;
       while(!q.empty())
       {
           T top=q.front();
           q.pop();
           cout<<top<<" ";

           for(T it:adjlist[top])
           {
               if(!visited[it]){
               q.push(it);
                visited[it]=true;
               }
           }
        
       }

   }
};
int main()
{
   Graph g(9);
    g.addEdge(0,1,true);
    g.addEdge(0,3,true);
    g.addEdge(1,2,true);
    g.addEdge(2,3,true);
    g.addEdge(3,4,true);
    g.addEdge(4,5,true);
    g.addEdge(4,6,true);
    g.addEdge(5,6,true);
    //addEdge(5,7,70);
    g.addEdge(7,8,true);

   Graph_genric<string> g1;
   g1.addedge("putin","trump",false);
   g1.addedge("putin","modi",false);
   g1.addedge("putin","pope",false);
   g1.addedge("modi","trump",true);
   g1.addedge("modi","yogi",true);
   g1.addedge("yogi","prabhu",false);
   g1.addedge("prabhu","modi",false);
   g.print();
   cout<<endl;
   for(int i=0;i<g.size();i++)
   {
       g.bfs(i);
   }
   cout<<endl;
   g1.print();
   cout<<endl;
   g1.bfs("putin");
   return 0;
}