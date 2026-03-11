#include<iostream>
#include<vector>

using namespace std;

int sum(vector<int> &A, int n, int k){
	vector<vector<bool>> S(n+1, vector<bool>(k+1));
	for (int i = 0; i <= n; i++) S[i][0] = true;
	for (int j = 1; j <= k; j++) S[0][j] = false;
	
	for (int j = 1; j <= k; j++){
		for (int i = 1; i <= n; i++){
			if (j < A[i-1]){
				S[i][j] = S[i-1][j];
			}else{
				S[i][j] = S[i-1][j] || S[i-1][j-A[i-1]];
			}
		}
	}
	
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= k; j++){
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	
	
	return S[n][k];
}

int main(){
	int n , k;
	cin >> n >> k;
	vector<int> A(n+1);
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	cout << sum(A, n, k);
	
	
	return 0;
}

/*
4 6
3 4 5 2

*/