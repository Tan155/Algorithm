#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    vector<pair<int,int>> adj[n+1];
    for (int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[u].push_back({v, w});
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	vector<int> dist(n+1, INF);
	vector<bool> intree(n+1, false);
	dist[s] = 0;
	pq.push({0, s});
	while(!pq.empty()){
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(intree[u]) continue;
		intree[u] = true;
		for (auto edges : adj[u]){
			int v = edges.first;
			int w = edges.second;
			if(!intree[v] && dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	cout << dist[t];
	return 0;
}
/*
4 4 1 4 
1 2 2 
1 3 5 
2 4 6 
3 4 1 

3 3 1 3 
1 2 3 
2 3 4 
1 3 10 

*/