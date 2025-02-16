#include<iostream>
using namespace std;


void insertion_sort(int arr[], int n){
	int j , v;
	
	for (int i = 1; i <= n - 1; i++){
		v = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > v){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
	}
	
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {5, 10, 6, 2, 1};
	insertion_sort(arr, sizeof(arr) / sizeof(int));	
	return 0;
}