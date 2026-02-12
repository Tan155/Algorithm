#include<iostream>
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
			cout << i << ":";
			for (int j = 0; j < s_v; j++){
				if(edges[i][j] > 0){
					cout << j << "," << edges[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
		
};


int main(){
	graph g(4);
	g.add_edge(0,1,5);
	g.add_edge(0,2,3);
	g.add_edge(1,3,2);
	
	g.print();
	return 0;
}