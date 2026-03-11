#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> prices(n);
	for (int i = 0; i < n; i++){
		cin >> prices[i];
	}
	vector<int> dp(k+1, -1);
	dp[0] = 0;
	
	for(int p : prices){
		for (int j = k; j >= p; j--){
			if(dp[j - p] != -1){
				dp[j] = max(dp[j], dp[j-p] + 1);
			}
		}
	}
	cout << dp[k];
	return 0;
}


/*
5 5
1 1 2 1 3

5 4
1 1 2 1 3

*/