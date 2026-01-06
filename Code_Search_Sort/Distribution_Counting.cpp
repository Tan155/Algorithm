#include<iostream>
using namespace std;

int main(){
	int arr[] = {2,1,3,5,1,2,5,3,4,1,5};
	int n = sizeof(arr) / sizeof(int);
	
	int max=-100, min=100;
	for (int i = 0; i < n; i++){
		if(arr[i] > max) max = arr[i];
		if(arr[i] < min) min = arr[i];
	}
	
	int range = max - min + 1;
	int count[range] = {0};
	int output[n];
	
	for (int i = 0; i < n; i++){
		count[arr[i] - min]++;
	}
	
	for (int i = 1; i < range; i++){
		count[i] += count[i - 1];
	}
	
	for (int i = n - 1; i >= 0; i--){
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}
	
	for (int i = 0; i < n; i++){
		cout << output[i] << " ";
	}
	return 0;
}