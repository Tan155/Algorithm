#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edges{
	int u,v,w;
};

int find(vector<int> &parent, int i){
	if(parent[i] == i){
		return i;
	}
	return find(parent, parent[i]);
}

void union1(vector<int> &parent, int u, int v){
	int rootx = find(parent, u);
	int rooty = find(parent, v);
	parent[rootx] = rooty;
}

int is_cycle(vector<int> &parent, int u, int v){
	int x = find(parent, u);
	int y = find(parent, v);
	return (x == y) ? true : false;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<edges> graph(m);
	
	for (int i = 0; i < m; i++){
		int s, d, l;
		cin >> s >> d >> l;
		graph[i].u = s; graph[i].v = d; graph[i].w = l; 
	}
	
	priority_queue< pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int , pair<int,int>>> > pq;
	
	vector<int> parent(n+1);
	for (int i = 0; i <= n; i++){
		parent[i] = i;
	}
	
	for (int i = 0; i < m; i++){
		pq.push({graph[i].w, {graph[i].u, graph[i].v}});
	}
	
	int ne = 0, total = 0;
	while(ne < n-1){
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();
		if(!is_cycle(parent, u, v)){
			ne++;
			total += (w - 1);
			union1(parent, u, v);
		}
	}
	cout << total;
	return 0;
}


/*
6 9 
1 2 8 
1 6 6 
2 6 6 
2 3 6 
2 4 9 
2 5 7 
3 4 5 
4 5 5 
5 6 8
*/