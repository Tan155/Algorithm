#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> array(n);
	
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}
	
	sort(array.begin(), array.end());
	int count = 0;
	for (int i = 0; i < n; i++){
		count++;
		while(i < n && array[i] == array[i + 1]){
			i++;
		}
	}
	
	cout << count;
	return 0;
}