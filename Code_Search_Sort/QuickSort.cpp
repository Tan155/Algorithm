#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int l, int r){
	int pivot,i,j,k;
	pivot = arr[r], i=l-1, j=r;
	while(true){
		do{
			i++;
		}while (arr[i] < pivot);
		do{
			j--;
		}while (arr[j] > pivot);
		if(i >= j) break;
		swap(arr,i,j);
	}
	swap(arr,i,r);
	return i;
}

void quickSort(int arr[], int l ,int r){
	if(l < r){
		int p = partition(arr, l, r);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,r);
	}
}

int main(){
	int arr[] = {25,57,48,37,33,92,86,12};
	int n = sizeof(arr) / sizeof(int);
	quickSort(arr, 0, n-1);
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}