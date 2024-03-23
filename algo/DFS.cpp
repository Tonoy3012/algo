#include<bits/stdc++.h>
using namespace std;
#define MAX 10

bool visited[MAX];
vector<int>adj_list[MAX];


void DFS()
{
    stack<int>stk;
    stk.push(0);
    visited[0]=true;

    while(!stk.empty())
    {
        int u=stk.top();
        cout << "Visited " << u << " ";
        stk.pop();
        for(int i=0;i<adj_list[u].size();i++)
        {
            int v=adj_list[u][i];
            if(!visited[v])
            {
                visited[v]=true;
                stk.push(v);
            }
        }
    }
}

main()
{
    int n,edges,u,v,i,j;

    cin>>n>>edges;
    for(i=0;i<edges;i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }
    for(i=0;i<n;i++)
        visited[i]=false;

    for(i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(j=0;j<adj_list[i].size();j++)
            cout<<adj_list[i][j]<<" ";
        cout<<endl;
    }

    DFS();
}