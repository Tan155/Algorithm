#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> files(n);
	for (int i = 0; i < n; i++){
		cin >> files[i];
	}
	
	double total_time = 0;
	double current_sum = 0;
	
	sort(files.begin(), files.end());
	for (int i = 0; i < n; i++){
		current_sum += files[i];
		total_time += current_sum;
	}
	
	cout << fixed << setprecision(2) << total_time / n;
	return 0;
}


/*
3
10 5 13

6
7 8 15 6 12 9


*/