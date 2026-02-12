#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	vector<int> buckets[10];
	vector<int> arr = {10,45,15,16,15,9,7,2,55,34,59};
	int n = arr.size(), max = -100,min = 100;
	int digits = 0;
	for (int i = 0; i < n; i++){
		if(arr[i] > max) max = arr[i];
	}
	
	while(max){
		digits++;
		max /= 10;
	}
	
	for (int d = 0; d < digits; d++){
		for (int i = 0; i < n; i++){
			buckets[i].clear();
		}
		for (int i = 0; i < n;i++){
			int dit = (arr[i] / (int)pow(10,d)) % 10;
			buckets[dit].push_back(arr[i]);
		}
		
		int k = 0;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < buckets[i].size(); j++){
				arr[k] = buckets[i][j]; k++;
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}