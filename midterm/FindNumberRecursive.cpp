#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int l, int r, int k){
	if(l < r){
		int value = l + abs( ((k - arr[l]) * (r - l)) / (arr[r] - arr[l]) );
		if(arr[value] == k)return value;
		if(arr[value] < k){
			return interpolationSearch(arr, value + 1, r, k);
		}else{
			return interpolationSearch(arr, l, value - 1, k);
		}
	}
	return -1;
}

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int index = interpolationSearch(arr,0, n-1,k);
	cout << index;
	return 0;
}