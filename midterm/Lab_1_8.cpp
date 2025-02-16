#include<iostream>
using namespace std;

int main(){
	int n, max = -100000;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			int sum = 0;
			for (int k = i; k <= j; k++){
				sum += A[k];
			}
			if(max < sum) max = sum;
		}
	}
	cout << max;
	return 0;
}