#include<iostream>
using namespace std;

int summation(int arr[], int n){
	if(n == 0){
		return arr[n];
	}
	
	int sum = summation(arr, n-1);
	
	return sum + arr[n];
}

int main(){
	int arr[] = {34, 3, 47, 91, 32, 0};
	int n = sizeof(arr) / sizeof(int);
	int sum = summation(arr, n-1);
	cout << sum;
	return 0;
}