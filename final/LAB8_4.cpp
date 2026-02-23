#include<iostream>
#include<vector>
#include<string>

using namespace std;
int n,m,cnt=0;
string	grid[100];
bool visited[100][100];

void floodFill(int r, int c, char targetColor){
	if(r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] != targetColor){
		return;
	}
	
	visited[r][c] = true;
	cnt++;
	floodFill(r+1,c,targetColor);
	floodFill(r-1,c,targetColor);
	floodFill(r,c+1,targetColor);
	floodFill(r,c-1,targetColor);
}

int main(){
	cin >> n >> m;
	
	for (int i = 0;i < n; i++){
		cin >> grid[i];
	}
	
	int x, y;
	cin >> x >> y;
	
	int startR = x-1;
	int startC = y-1;
	
	if(startR >= 0 && startR < n && startC >= 0 && startC < m){
		floodFill(startR, startC, grid[startR][startC]);
	}
	
	cout << cnt;
	return 0;
}

/*
6 6 
LLWWLW 
LLWWLL 
WLLWWW 
WWLWLL 
WWLWLW 
WLLWWW 
2 4 
*/