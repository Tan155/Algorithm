#include<iostream>
#include<vector>
using namespace std;

void dtf(int start, vector<int> graph[], vector<bool> &visited){
	visited[start] = true;
	for (int y = 0; y < graph[start].size(); y++){
		int nei = graph[start][y];
		if(visited[nei] == false){
			dtf(nei, graph, visited);
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> graph[n+1];
	int u,v;
	for (int i = 0; i < n; i++){
		cin >> u;
		while(cin >> v && v != 0){
			graph[u].push_back(v);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++){
		int start;
		bool flag = false;
		vector<bool> visited(n+1, false);
		cin >> start;
		dtf(start, graph, visited);
		
		for (int j = 1; j <= n; j++){
			if(!visited[j]){
				cout << j << " ";
				flag = true;
			}
		}
		if(!flag){
			cout << 0 << " ";
		}
		cout << endl;
	}
	return 0;
}


/*

3 
1 2 0 
2 2 0 
3 1 2 0 
3 1 2 3
*/