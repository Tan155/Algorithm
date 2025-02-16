#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>;
using namespace std;


int main(){
	int n, t;
	cin >> n >> t;
	vector<int> array(n);
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}
	int i = 0, j = n - 1;
	int i_1, j_1, min = 10000;
	sort(array.begin(), array.end());
	while(i <= j){
		int sum = abs(array[i] + array[j]);
		if(sum == t && (min > abs(array[i] - array[j]))){
			i_1 = array[i]; j_1 = array[j];
			min = abs(array[i] - array[j]);
		}
		
		if(sum < t){
			i++;
		}else if(sum > t){
			j--;
		}else{
			i++; j--;
		}
	}
	cout << i_1 << " " << j_1;
	return 0;
}