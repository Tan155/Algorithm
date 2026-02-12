#include<iostream>


using namespace std;

int main(){
	int A[] = {16, 25, 2, 54, 36, 9, 12, 66};
	int n = sizeof(A) / sizeof(int);
	
	int max = 0, min = 100;
	for (int i = 0; i < n; i++){
		if(A[i] > max) max = A[i];
		if(A[i] < min) min = A[i];
	}
	int range = max - min + 1;
	int D[range] = {0};
	int S[n];
	
	for (int i = 0; i < n; i++){
		D[A[i] - min] = D[A[i] - min] + 1;
	}
	
	for (int i = 1; i < range; i++){
		D[i] = D[i - 1] + D[i];
	}
	
	for (int i = n-1; i >= 0; i--){
		int j = A[i] - min;
		S[D[j] - 1] = A[i];
		D[j]--;
	}
	
	for (int i = 0; i < n; i++){
		cout << S[i] << " ";
	}
	
	return 0;
}