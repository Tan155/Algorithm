#include<iostream>
using namespace std;
int count = 0;
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printSol(int x[], int arr[], int n){
	for (int i = 1; i <= n; i++){
		if(x[i] == 1){
			cout << arr[i-1] << " ";
		}
	}
	cout << endl;
}

void subset2(int x[], int arr[], int l, int r, int k, int sum){
	if(sum == k){
		printSol(x,arr,l); return;
	}
	if(sum > k) return;
	if(l == r) return;
	
	x[l + 1] = 1;
	sum += arr[l];
	subset2(x, arr, l + 1, r, k, sum);
	x[l + 1] = 0;
	sum -= arr[l];
	subset2(x, arr, l + 1, r, k, sum);
	
}

int main(){
	int k, n = 5;
	cin >> k;
	int x[n+1];
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	subset2(x, arr, 0, n, k, 0);
	return 0;
}