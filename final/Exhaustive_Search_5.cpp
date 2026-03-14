#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 3;

int solve(int remain, vector<int> &sizes){
	if(remain == 0) return 0;
	if(remain < 0) return 0;
	int best = 100;
	for (int i = 0; i < n; i++){
		int current_cut = 1 + solve(remain - sizes[i], sizes);
		if(current_cut < best){
			best = current_cut;
		}
	}
	return best;
}

int main(){
	int target;
	cin >> target;
	vector<int> sizes(n);
	for (int i = 0; i < n; i++) cin >> sizes[i];
	cout << solve(target, sizes);
	return 0;
}


/*
8 
2 3 5
*/