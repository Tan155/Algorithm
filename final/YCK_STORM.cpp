#include<iostream>
#include<vector>
#include<string>
using namespace std;

int R, C;
vector<string> grid;


int stormFill(int i, int j){
	if(i < 0 || i >= R || j < 0 || j >= C || grid[i][j] != '#'){
		return 0;
	}
	grid[i][j] = '.';
	return 1 + stormFill(i-1,j) + stormFill(i+1,j) + stormFill(i,j+1) + stormFill(i,j-1);
}

int main(){
	cin >> R >> C;
	grid.resize(R);
	for(int i = 0; i < R; i++){
		cin >> grid[i];
	}
	int maxSize = 0;
	int stormCount = 0;
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			int currentSize = stormFill(i,j);
			
			if(currentSize > maxSize){
				maxSize = currentSize;
				stormCount = 1;
			}else if(currentSize == maxSize && maxSize > 0){
				stormCount++;
			}
		}
	}
	
	cout << maxSize << " " << stormCount;
	return 0;
}


/*
5 6
...#..
..###.
....#.
.#....
###...


4 5
##...
##...
...##
...##

3 3
#..
.#.
..#


2 2
..
..


*/