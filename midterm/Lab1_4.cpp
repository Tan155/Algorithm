#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}
	int count = 1;
	for (int i = 0; i < n - 1; i++){
		if(array[i] > array[i + 1]){
			count = 0; break;
		}
	}
	
	if(count){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}