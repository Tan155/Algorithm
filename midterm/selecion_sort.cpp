#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void selection_sort(int arr[],int n){
	int min, tmp;
	
	for (int i = 0; i < n-1; i++){
		min = i;
		for (int j = i+1; j < n;j++){
			if(arr[j] < arr[min]) min = j;
		}
		tmp= arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
	
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {5, 10, 6, 2, 1};
	int n = sizeof(arr) / sizeof(int);
	
	selection_sort(arr, n);
	return 0;
}