#include<iostream>
using namespace std;
int arr[10000];

int compute(int l,int m, int r){
	int sum = 0, left = -100000;
	for(int i = m; i >= l; i--){
		sum += arr[i];
		if(sum > left) left = sum;
	}
	int right = -1000000;
	sum = 0;
	for(int i = m+1; i <= r;i++){
		sum += arr[i];
		if(sum > right) right = sum;
	}
	return (right + left);
}

int maxima(int l,int r){
	if(l == r) return arr[l];
	int m = (l + r) / 2;
	int leftSum = maxima(l,m);
	int rightSum = maxima(m+1, r);
	int combine = compute(l,m,r);
	
	if(leftSum >= rightSum && leftSum >= combine){
		return leftSum;
	}else if(rightSum >= leftSum && rightSum >= combine){
		return rightSum;
	}	
	else{
		return combine;	
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maxima(0, n-1);
	return 0;
}

/*
-2 1 -3 4 -1 2 1 -5 4
*/