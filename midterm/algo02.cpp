#include<iostream>
using namespace std;

int main(){
	int n, max = 0, sum = 0;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			sum = 0;
			for (int k = j; k < n; k++){
				sum += A[k];
			}
			if(sum > max) max = sum;
		}
	}
	cout << max;
	
	return 0;
}