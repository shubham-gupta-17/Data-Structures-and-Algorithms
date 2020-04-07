#include<bits/stdc++.h>
using namespace std;
void bfs()
{
    vector<int> edges;
    for(int i=0;i<9;i++)
    {
        for(int j:graph[i])
        {
            edges[j]++;
        }
    }

    queue<int> q;
    vector<bool> mark;
    for(int i=0;i<edges.size();i++)
    {
        if(edges[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int top=q.front();

        for(int i:graph[top])
        {
            edges[i]--;
            if(edges[i]==0)
            q.push(i);
        }
    }
}
int main()
{
    vector<string> s;
    s.push_back("shubham");
    s.push_back("ayush");
    cout<<s[0]<<s[1];
}