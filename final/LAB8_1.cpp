#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
	int n,p,q,start,target;
	cin >> n;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n; i++){
		cin >> p;
		while(cin >> q && q != 0){
			adj[p].push_back(q);
//			adj[q].push_back(p);
		}
	}
	
	cin >> start >> target;
	vector<int> dist(n + 1, -1);
	vector<int> queue(n+1);
	queue.push_back(start);
	dist[start] = 0;
	while(!queue.empty()){
		int curr = queue.front();
		queue.erase(queue.begin());
		for (int y = 0; y < adj[curr].size(); y++){
			int nei = adj[curr][y];
			if(dist[nei] == -1){
					dist[nei] = dist[curr] + 1;
					queue.push_back(nei);
			}
		}
	}
	
	cout << dist[target];
	return 0;
}

/*

6 
1 2 3 0 
2 1 4 0 
3 1 4 0 
4 2 3 5 0 
5 4 6 0 
6 5 0 
3 6 

*/