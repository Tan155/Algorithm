#include<iostream>
#include<vector>
using namespace std;
#define MAXSIZE 100
#define UNDEFINED 0

int binomial(int n, int k){
	if(k == 0 || k == n) return 1;
	return binomial(n-1,k-1) + binomial(n-1,k);
}


vector< vector<int> > memo(MAXSIZE, vector<int>(MAXSIZE, UNDEFINED));

int binomial_DP(int n, int k){
	if(memo[n][k] == UNDEFINED){
		if(k == 0 || k == n){
			memo[n][k] = 1;
		}else{
			memo[n][k] = binomial(n-1,k-1) + binomial(n-1,k);
		}
	}
	return memo[n][k];
}

int binomial_BottomUP_DP(int n, int k){
	for (int i = 0;i <= n; i++){
		memo[i][0] = 1;
	}
	for (int i = 1; i <= k; i++){
		memo[i][i] = 1;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= k && j < i; j++){
			memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
		}
	}
	return memo[n][k];
}


int main(){
	int n, k;
	cin >> n >> k;
	cout << binomial_DP(n,k) << "\n";
	cout << binomial_BottomUP_DP(n,k) << "\n";
	return 0;
}