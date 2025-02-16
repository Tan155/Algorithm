#include<iostream>
using namespace std;

int interpolation_Search(int arr[], int low, int high, int k){
	int pos = low + ((high - low) * (k - arr[low]) / (arr[high] - arr[low]));
	cout << pos << " ";
	
	if(arr[pos] == k) return pos;
	
	if(arr[pos] < k){
		interpolation_Search(arr, pos + 1, high, k);
	}else{
		interpolation_Search(arr, low, pos - 1, k);
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
	
	interpolation_Search(arr, 0, n-1, k);
	
	
	return 0;
}