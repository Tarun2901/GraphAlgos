#include<bits/stdc++.h>
using namespace std;


vector<int> toposort(int V,vector<int> adj[])
{
	vector<int>InDegree(V,0);
	vector<int>topo;
	//Make InDegree array
	for(int i = 0;i<V;i++)
	{
		for(auto it:adj[i])
		{
			InDegree[it]++;
		}
	}
    //Make queue
    queue<int> q;
    //Push in queue those elements which have an InDegree of 0

    for(int i = 0;i<V;i++)
    {
    	if(InDegree[i] == 0)
    	{
    		q.push(i);
    	}
    }

    //apply BFS using queue
    while(!q.empty())
    {
    	int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
        	 InDegree[it]--;
        	 if(InDegree[it] == 0)
        	 {
        	 	q.push(it);
        	 }
        }
    }
   return topo;
}

int main()
{
   int n,m;
   cin>>n>>m;
   vector<int> adj[n];

   for(int i = 0;i<m;i++)
   {
   	int u,v;
   	cin>>u>>v;
   	adj[u].push_back(v);
   }
   for(int i = 0;i<n;i++)
   {
   	cout<<"For edge "<<i<<" the adjacent vertices are: ";
   	for(int it:adj[i])
   	{
   		cout<<it<<" ";
   	}
   	cout<<endl;
   }
   
   vector<int> ans = toposort(n,adj);

   for(int i = 0;i<ans.size();i++)
   { cout<<ans[i]<<" ";
   }

	return 0;
}