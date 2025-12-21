#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l,int r){
	int i = l - 1, j = r, pivot = arr[r];
	while(true){
		do{
			i++;
		}while(arr[i] < pivot);
		do{
			j--;
		}while(arr[j] > pivot);
		if(i > j)break;
		swap(&arr[i], &arr[j]); 
	}
	swap(&arr[i],&arr[r]);
	return i;
}

void quickSort(int arr[],int l,int r){
	if(l < r){
		int p = partition(arr,l,r);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,r);	
	}
}

int main(){
	int arr[] = {4,31,36,14,62,91,8,22,7,81};
	int n = sizeof(arr) / sizeof(int);
	quickSort(arr, 0, n-1);
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}