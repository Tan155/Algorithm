#include<iostream>
using namespace std;

int max(int arr[], int n){
	if(n == 0){
		return arr[0];
	}
	
	int value = max(arr, n-1);
	
	if(arr[n] > value){
		return arr[n];
	}else{
		return value;
	}
}

int main(){
	int arr[] = {34, 3, 47, 91, 32, 0};
	int n = sizeof(arr) / sizeof(int);
	int maxValue = max(arr, n-1);
	cout << maxValue;
	return 0;
}