#include<iostream>
#include<vector>
using namespace std;

void subset1(vector<int> arr, vector<int> x, int l, int r, int k, int sum){
	if(sum == k){
		for(int i = 1; i <= l; i++){
			if(x[i] == 1){
				cout << arr[i-1] << " ";
			}
		}
		cout << endl;
		return;
	}
	if(sum > k) return;
	if(l == r) return;
	
	x[l + 1] = 1;
	sum += arr[l];
	subset1(arr, x, l + 1, r, k, sum);
	x[l + 1] = 0;
	sum -= arr[l];
	subset1(arr, x, l + 1, r, k, sum);
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> x(n+1);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	subset1(arr, x, 0, n, k, 0);
	return 0;
}


/*
5 12 
25 10 9 2 1

*/