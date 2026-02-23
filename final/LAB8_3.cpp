#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	int V;
	cin >> V;
	vector<int> adj[V+1];
	
	int u, v;
	while(cin >> u >> v && (u != 0 || v != 0)){
		adj[u].push_back(v);
	}
	
	int k,m;
	cin >> k >> m;
	
	vector<int> dist(V+1, -1);
	vector<int> q;
	dist[k] = 0;
	q.push_back(k);
	
	int reached_count = 0;
	while(!q.empty()){
		int curr = q.front();
		q.erase(q.begin());
		
		if(dist[curr] <= m)reached_count++;
		
		for(int y = 0; y < adj[curr].size(); y++){
			int nei = adj[curr][y];
			if(dist[nei] == -1){
				dist[nei] = dist[curr] + 1;
				q.push_back(nei);	
			}
		}
	}
	cout << V - reached_count;
	return 0;
}

/*
7
1 2
1 4
1 5
2 3
2 5
3 1
3 6
3 7
4 5
5 4
6 5
6 7
0 0
1 2

*/