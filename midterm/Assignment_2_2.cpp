#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	int l = 0, r = n - 1, min = 1000000;
	
	while( l <= r){
		int sum = arr[l] + arr[r];
		if(sum == k){
			if(abs(arr[l] - arr[r]) < min){
				min = abs(arr[l] - arr[r]);
			}
			l++; r--;
		}else if(sum < k){
			l++;
		}else{
			r--;
		}
	}
	cout << min;
	return 0;
}