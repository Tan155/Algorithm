#include<iostream>
using namespace std;


void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shellSort(int arr[], int n){
	int gap = n / 2;
	
	for (int k = gap; k > 0; k /= 2){
		for (int i = k; i < n; i++){
			int j = i - k;
			int v = arr[i];
			while(j >= 0 && arr[j] > v){
				arr[j + k] = arr[j]; j -=k;
			}
			arr[j + k] = v;
		}
	}
}

int main(){
	int arr[] = {4,31,36,14,62,91,8,22,7,81};
	int n = sizeof(arr) / sizeof(int);
	shellSort(arr, n);
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}