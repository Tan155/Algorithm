#include<iostream>
#include<string>
using namespace std;

int ar[10000], ar2[10000];

void merge(int l, int m, int r){
	int i,j,k=l;
	int n1 = m - l + 1, n2 = r - m;
	int a[n1],b[n2];
	for(i = 0; i < n1; i++){
		a[i] = ar[l + i];
	}
	for(j = 0; j < n2; j++){
		b[j] = ar[m + 1 + j];
	}
	i=0;j=0;
	while(i < n1 && j < n2){
		if(a[i] < b[j]){
			ar[k] = a[i]; i++;
		}else{
			ar[k] = b[j]; j++;
		}
		k++;
	}
	while(i < n1){
		ar[k] = a[i]; i++; k++;
	}
	while(j < n2){
		ar[k] = b[j]; j++; k++; 
	}
}

void mergeSort(int l,int r){
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(l,m);
		mergeSort(m+1, r);
		merge(l,m,r);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> ar[i];
	}
	
	mergeSort(0,n-1);
	
	//output1
	for(int i = 0; i < n; i++){
		cout << ar[i];
	}
	
	
	
	return 0;
}

/*

7
3 2 10 12 15 22 23

*/