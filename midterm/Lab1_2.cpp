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
	sort(array.begin(), array.end());
	int max = -1000000, min = 1000000;
	for(int i = 0; i < n; i++){
		int count = 1;
		while(array[i] == array[i + 1]){
			count++; i++;
		}
		if(max < count) max = count;
		if(min > count) min = count;
	}
	cout << (max - min);
	return 0;
}