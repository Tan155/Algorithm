#include<iostream>
using namespace std;

int arr[100000];

void merge(int l, int m, int r){
	int i, j, k=l;
	int n1 = m-l+1, n2= r-m;
	int a[n1],b[n2];
	for(i=0;i<n1;i++){
		a[i] = arr[l+i];
	}
	for(j=0;j<n2;j++){
		b[j] = arr[m+1+j];
	}
	i=0;j=0;
	while(i < n1 && j < n2){
		if(a[i] < b[j]){
			arr[k] = a[i]; i++;
		}else{
			arr[k] = b[j]; j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = a[i]; i++; k++;
	}
	while(j < n2){
		arr[k] = b[j]; j++; k++;
	}
}

void mergeSort(int l, int r){
	if(l < r){
		int mid = (l + r) /2;
		mergeSort(l,mid);
		mergeSort(mid+1,r);
		merge(l,mid,r);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	mergeSort(0, n-1);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}