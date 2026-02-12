#include<iostream>
using namespace std;

void printSol(int x[],int arr[], int n){
	for (int i = 1; i <= n; i++){
		if(x[i] == 1){
			cout << arr[i - 1] << " ";
		}
	}
	cout << endl;
}

void subset2(int x[],int arr[], int l, int r,int sum,int k){
	if(sum == k){
		printSol(x, arr, l); return;
	}
	if(sum > k) return;
	if(l == r) return;
	x[l + 1] = 1;
	sum += arr[l];
	subset2(x, arr, l + 1, r, sum, k);
	x[l + 1] = 0;
	sum -= arr[l];
	subset2(x, arr, l + 1, r, sum, k);
}

int main(){
	int n, k;
	cin >> n >> k;
	int x[n];
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	subset2(x, arr, 0, n, 0, k);
	
	return 0;
}