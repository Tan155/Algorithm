#include<iostream>
using namespace std;

int main(){
	int n, k, flag = 0;
	cin >> n >> k;
	int A[n];
	
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for (int i = 0; i < n; i++){
		for (int j = n - 1; j > i; j--){
			if(A[i] + A[j] == k){
				cout << A[i] << " " << A[j] << endl;
				flag = 1;
			}
		}
	}
	
	if(flag == 0){
		cout << -1;
	}
	
	return 0;
}