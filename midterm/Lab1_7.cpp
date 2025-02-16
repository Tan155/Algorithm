#include<iostream>
using namespace std;


int main(){
	int n, k;
	cin >> n >> k;
	int A[n];
	int flag = 0;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for (int i = 0; i < n-1; i++){
		for (int j = i + 1; j < n; j++){
			if(A[i] + A[j] == k){
				flag = 1;
				cout << A[i] << " " << A[j] << endl;
			}
		}
	}
	
	if(flag == 0)cout << -1;
	return 0;
}