#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int l, int r){
	int pivot, i, j, t;
	pivot = arr[l];
	i = l;
	j = r + 1;
	
	while(true){
		do{
			i++;
		}while(arr[i] <= pivot);
		
		do{
			j--;
		}while(arr[j] > pivot);
		if(i >= j) break;
		
		swap(arr[i],arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}

void quickSort(vector<int> &arr, int l, int r){
	if(l < r){
		int p = partition(arr, l, r);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, r);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n; i++){
		cin >> arr[i];
	}
	
	quickSort(arr, 0,arr.size() - 1);
	
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	return 0;
}