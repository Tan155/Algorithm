#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1e9;
int dist[505][505];
int min_to_existing[505];
bool has_hospital[505];

int main(){
	int f, n;
	cin >> f >> n;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	
	vector<int> existing;
	for (int i = 0; i < f; i++){
		int h; cin >> h;
		existing.push_back(h);
		has_hospital[h] = true;
	}
	
	int u, v, w;
	for (int i = 0; i < n; i++){
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}
	
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		min_to_existing[i] = INF;
		for (int h : existing){
			min_to_existing[i] = min(min_to_existing[i], dist[i][h]);
		}
	}
	
	int best_city = 1;
	int min_max_dist = INF;
	
	for (int k = 1; k <= n; k++){
		if(has_hospital[k]) continue;
		
		int current_max = 0;
		for (int i = 1; i <= n; i++){
			current_max = max(current_max, min(min_to_existing[i], dist[i][k]));
		}
		if(current_max < min_max_dist){
			min_max_dist = current_max;
			best_city = k;
		}
	}
	cout << best_city << endl;
	return 0;
}

/*
1 6 
2 
1 2 10 
2 3 10 
3 4 10 
4 5 10 
5 6 10 
6 1 10


*/