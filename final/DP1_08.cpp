#include<iostream>
#include<vector>
using namespace std;


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> coins(k);
	for (int i = 0; i < k; i++){
		cin >> coins[i];
	}
	
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	
	for (int coin : coins){
		for (int j = coin; j <= n; j++){
			dp[j] += dp[j - coin];
		}
	}
	cout << dp[n];
	return 0;
}


/*
5
3
1 2 3

13
4
1 2 6 10

*/