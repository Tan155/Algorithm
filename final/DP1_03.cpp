#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector< vector<int> > dp(n+1, vector<int> (m+1, 0));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if(i == 1 && j == 1){
				dp[i][j] = 1;
			}else{
				int up = (i > 1)? dp[i-1][j] : 0;
				int left = (j > 1) ? dp[i][j-1] : 0;
				dp[i][j] = up + left;
			}
		}
	}
	cout << dp[n][m];
	return 0;
}



/*
2 3

2 5
*/