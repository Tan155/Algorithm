#include<iostream>
#include<vector>
#define MAXSIZE 100
#define UNDEFINED 0
using namespace std;

vector<vector<int>> memo(MAXSIZE, vector<int>(MAXSIZE, UNDEFINED));

int Binomial(int n, int k){
	if(memo[n][k] == UNDEFINED){
		if(k == 0 || n == k){
			memo[n][k] = 1;
		}else if(k == 1){
			memo[n][k] = 1;
		}else{
			memo[n][k] = Binomial(n-1,k) + Binomial(n-1,k-2);
		}
	}
	return memo[n][k];
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << Binomial(n, k);
	return 0;
}

/*
6 4
*/