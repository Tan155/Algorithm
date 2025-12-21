#include<iostream>
using namespace std;

int interpolation(int arr[],int l, int r, int k){
	int mid = l + abs( ((k - arr[l]) * (r - l)) / (arr[r] - arr[l]) );
	cout << mid << " ";
	if(arr[mid] == k) return mid;
	if(arr[mid] < k ){
		return interpolation(arr,mid+1,r,k);
	}else{
		return interpolation(arr,l,mid-1,k);
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int v = interpolation(arr,0,n-1,k);
	return 0;
}