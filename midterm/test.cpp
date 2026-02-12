#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class graph{
	public:
	int edges[100][100];
	int s_v;
	graph(int n){
		s_v = n;
		for (int i = 0; i < s_v; i++){
			for (int j = 0; j < s_v; j++){
				edges[i][j] = 0;
			}
		}
	}
	
	void add_edge(int x,int y, int w){
		edges[x][y] = w;
	}
	
	void print(){
		for (int i = 0; i < s_v; i++){
			cout << i << ":" << " ";
			for (int j = 0; j < s_v; j++){
				if(edges[i][j] > 0){
					cout << j << "," << edges[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
	
	void bft(int start){
		int visited_bft[100];
		for (int i = 0; i < s_v; i++){
			visited_bft[i] = 0;
		}
		vector<int> q;
		q.push_back(start);
		visited_bft[start] = 1;
		while(!q.empty()){
			start = q.front();
			cout << start << " ";
			q.erase(q.begin());
			for (int i = 0; i < s_v; i++){
				if(visited_bft[i] == 0 && edges[start][i] > 0){
					q.push_back(i);
					visited_bft[i] = 1;
				}
			}
		}
	}
	
	int visited_dft[100];
	
	void sub_dft(int start){
		cout << start << " ";
		visited_dft[start] = 1;
		for (int i = 0; i < s_v; i++){
			if(visited_dft[i] == 0 && edges[start][i] > 0){
				sub_dft(i);
			}
		}
	}
	
	void dft(int start){
		for (int i = 0; i < s_v; i++){
			visited_dft[i] = 0;
		}
		sub_dft(start);
	}
	
};

int main(){
	graph g(4);
	g.add_edge(0,1,5);
	g.add_edge(0,2,3);
	g.add_edge(1,3,2);
	
	g.print();
	cout << endl;
	g.bft(0);
	cout << endl;
	g.dft(0);
	return 0;
}