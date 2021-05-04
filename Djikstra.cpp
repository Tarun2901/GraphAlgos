#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,src;
  cin>>n>>m;
  vector<pair<int,int>> adj[n+1];

  int a,b,wt;
  for(int i = 0;i<m;i++)
 {
   cin>>a>>b>>wt;
   adj[a].push_back(make_pair(b,wt));
   adj[b].push_back(make_pair(a,wt));
 }
 cin>>src;
 //Djikstra Algorithm begins from here
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
 vector<int> distTo(n+1,INT_MAX);
 distTo[src] = 0;
 pq.push(make_pair(0,src));
 while(!pq.empty())
 {
   int dist = pq.top().first;
   int prev = pq.top().second;
   pq.pop();
   vector<pair<int,int>>:: iterator it;
   for(auto it: adj[prev])
   {
     int next = it.first;
     int nextDist = it.second;
     if(distTo[next]>distTo[prev]+nextDist)
     {
       distTo[next] = distTo[prev]+nextDist;
       pq.push(make_pair(distTo[next],next));
     }
   }
 }
 cout<<"The distances from source, "<<src<<", are : "<<endl;
 for(int i = 1;i<=n;i++)
 {
   cout<<distTo[i]<<" ";
 }
  return 0;
}
