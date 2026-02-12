#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int r){
	int i = l-1, pivot = arr[r];
	for (int j = l; j < r; j++){
		if(arr[j] < pivot){
			i++; swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	
	return i+1;
}

int quickSelect(int arr[], int l, int r, int k){
	if(l <= r){
		int p = partition(arr, l, r);
		if(p-l+1 == k) return arr[p];
		
		if(k < p - l + 1){
			return quickSelect(arr, l, p-1, k);
		}else{
			return quickSelect(arr, p+1, r, k - abs(p - l + 1));
		}
		
	}
	return -1;
}

int main(){
	int n,k, min = 100;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int find = quickSelect(arr, 0, n-1, k);
	cout << find;
	return 0;
}


/*
7 3
1 5 10 4 8 2 6
*/