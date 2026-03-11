#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int INF = 2e9;

void solve(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	vector<pair<int,int>> adj[n];
	for (int i = 0; i < m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	vector<int> dist(n, INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	
	dist[s] = 0;
	pq.push({0, s});
	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(d > dist[u]) continue;
		if(u == t) break;
		
		for(auto edges : adj[u]){
			int v = edges.first;
			int w = edges.second;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	if(dist[t] == INF) cout << -1 << endl;
	else cout << dist[t] << endl;
}

int main(){
	int c;
	cin >> c;
	while(c--){
		solve();
	}
	return 0;
}