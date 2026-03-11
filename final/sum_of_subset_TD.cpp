#include<iostream>
#include<vector>


using namespace std;
vector<vector<int>> memo(1000, vector<int>(1000, -1));
int sum(vector<int> &A, int n, int k){
	if(k == 0) return memo[n][k] = 1;
	if(n == 0) return memo[n][k] = 0;
	
	if(memo[n][k] != -1) return memo[n][k]; 
	
	if(k < A[n-1]){
		memo[n][k] = sum(A, n-1, k);
	}else{
		memo[n][k] = sum(A, n-1, k) || sum(A,n-1, k- A[n-1]);
	}
	
	return memo[n][k];
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> A(n+1);
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	cout << sum(A, n, k) << endl;
	
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= k; j++){
			cout << memo[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


/*
4 6
3 4 5 2

*/