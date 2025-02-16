#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int medianOfThree(vector<int> &arr, int l, int r){
	int mid = (l + r) / 2;
	if(arr[mid] < arr[l]) swap(arr[mid], arr[l]);
	if(arr[r] < arr[l]) swap(arr[r], arr[l]);
	if(arr[r] > arr[mid]) swap(arr[r], arr[mid]);
//	swap(arr[mid], arr[r]);
	return r;
}

int partition(vector<int> &arr, int l, int r){
	int pivot, i, j;
	pivot = arr[medianOfThree(arr, l, r)];
	i = l - 1; j = r;
	while(true){
		do{
			++i;
		}while(arr[i] <= pivot);
		do{
			--j;
		}while(arr[j] > pivot);
		if(i > j) break;
		
		swap(arr[i], arr[j]);
	}
	swap(arr[i], arr[r]);
	return i;
}

void quicksort(vector<int>&arr, int l, int r){
	if(l < r){
		int pivotpos = medianOfThree(arr, l, r);
		cout << pivotpos << " ";
		
		int p = partition(arr, l, r);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	quicksort(arr, 0, arr.size() - 1);
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}