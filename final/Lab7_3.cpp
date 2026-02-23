#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++){
		cin >> prices[i];
	}
	sort(prices.begin(), prices.end(), greater<int>());
	
	int total = 0;
	for (int i = 2; i < n; i+= 3){
		total += prices[i];
	}
	cout << total;
	return 0;
}

/*
6
400 100 200 300 500 600


*/