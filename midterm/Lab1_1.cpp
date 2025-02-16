#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int count=0;
	for(int i = 0; i < n; i++){
		count++;
		while( i < n && (arr[i] + 1 == arr[i + 1])){
			i++;
		}
	}
	cout << count;
	return 0;
}