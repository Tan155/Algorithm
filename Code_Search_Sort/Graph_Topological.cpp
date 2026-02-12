#include<iostream>
#include<stack>
#include<vector>
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
	
	void add_edge(int x, int y, int w){
		edges[x][y] = w;
	}
	
	void print(){
		for (int i = 0; i < s_v; i++){
			cout << i << ": ";
			for (int j = 0; j < s_v; j++){
				if(edges[i][j] > 0){
					cout << j << "," << edges[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
	
	int n_in_degree[100];
	int t_edges[100][100];
	void in_degree(){
		for (int i = 0; i < s_v; i++){
			n_in_degree[i] = 0;
			for (int j = 0; j < s_v; j++){
				for (int k = 0; k < s_v; k++){
					if(t_edges[j][k] == 1){
						n_in_degree[k]++;
					}
				}
			}
		}
	}
	
	void topologicalsort(){
		bool visited[100];
		int t_s_v = 0;
		for (int i = 0; i < s_v; i++){
			visited[i] = 0;
			for (int j = 0; j < s_v; j++){
				t_edges[i][j] = edges[i][j];
			}
		}
		
		while(t_s_v < s_v){
			in_degree();
			for (int i = 0; i < s_v; i++){
				if(n_in_degree[i] == 0 && visited[i] == 0){
					visited[i] = 1;
					cout << i << " ";
					for (int j = 0; j < s_v; j++){
						t_edges[i][j] = 0;
					}
					t_s_v++;
					break;
				}
			}
		}
	}
};


int main(){
	graph g(4);
	
	g.add_edge(0,1,1);
	g.add_edge(2,0,1);
	g.add_edge(3,1,1);
	g.add_edge(3,2,1);
	g.topologicalsort();

	return 0;
}