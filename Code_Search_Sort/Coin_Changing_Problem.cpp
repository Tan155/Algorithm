#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int coin_change(int W, vector<int>D, int n){
	int cnts = 0;
	for (int i = n-1; i>= 0; i--){
		while(W >= D[i]){
			W -= D[i];
			cnts++;
		}
	}
	return cnts;
}

int main(){
	vector<int> D = {1,2,4,5,10};
	int W = 38, n = 5;
	sort(D.begin(),D.end());
	int coin = coin_change(W,D,n);
	cout << coin;
	return 0;
}