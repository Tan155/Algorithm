#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void Dijkstra(vector<pair<int, int>> adj[], int V, int src){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	vector<int> dist(V, 10000);
	vector<int> parent(V, -1);
	vector<bool> intree(V, false);
	
	pq.push({0, src});
	dist[src] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		
		if(intree[u]) continue;
		intree[u] = true;
		
		for(auto edge : adj[u]){
			int v = edge.first;
			int weight = edge.second;
			
			if(!intree[v] && dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
				parent[v] = u;
				pq.push({dist[v], v});
			}
		}
		
		cout << "Vertex\tParent\n";
		for (int i = 0; i < V; i++){
			cout << i << "\t" << parent[i] << endl;
		}
	}
}

int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    adj[0].push_back({1, 5});  adj[1].push_back({0, 5});
    adj[0].push_back({3, 9});  adj[3].push_back({0, 9});
    adj[0].push_back({4, 1});  adj[4].push_back({0, 1});

    adj[1].push_back({2, 2});  adj[2].push_back({1, 2});
    adj[2].push_back({3, 6});  adj[3].push_back({2, 6});
    adj[3].push_back({4, 2});  adj[4].push_back({3, 2});

    Dijkstra(adj, V, 0);

    return 0;
}