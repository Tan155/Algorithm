#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N, target;
	cin >> N >> target;
	vector<int> coins(N,0);
	for (int i = 0; i < N; i++){
		cin >> coins[i];
	}
	int bestChoice = 0, count = 0, sum = 0;
	
	while(sum < target){
		if(coins[bestChoice] <= target-sum){
			sum += coins[bestChoice];
			count++;
		}else{
			bestChoice++;
		}
	}
	
	cout << sum << " " << count;
	return 0;
}

/*
4 175
10 5 2 1

*/