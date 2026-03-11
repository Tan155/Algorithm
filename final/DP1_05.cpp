#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> memo(1000, vector<int>(1000,-1));

int P(int i, int j){
	if(i == 0) return 3 * j;
	if(j == 0) return 2 * i;
	if(memo[i][j] != -1) return memo[i][j];
	
	int c = 2 * i + j;
	int p1 = P(i-1,j) + 2;
	int p2 = P(i,j-1) + 3;
	int p3 = P(i-1,j-1) + c;
	
	memo[i][j] = min({p1,p2,p3});
	return memo[i][j];
}

int main(){
	int i,j;
	cin >> i >> j;
	cout << P(i, j);
	return 0;
}

/*
10 5

2 3
*/

