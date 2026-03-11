#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int L;
	cin >> L;
	vector<int> prices(L+1);
	for (int i = 1; i < L; i++){
		cin >> prices[i];
	}
	
	vector<int> dp(L+1, 0);
	for (int i = 1; i <= L; i++){
		for (int j = 1; j <= i; j++){
			dp[i] = max(dp[i], prices[j] + dp[i-j]);
		}
	}
	cout << dp[L];
	return 0;
}


/*
8
3 5 8 9 10 17 17 20


8
1 5 8 9 10 17 17 20
*/