#include<iostream>
#include<vector>
using namespace std;

int N, W;

int maximumValue(vector<int> &weight, vector<int> &value, vector<vector<int>> &memo, int i, int j){
	if(i == 0 || j == 0) return memo[i][j] = 0;
	if(memo[i][j] != -1){
		return memo[i][j];
	}
	if(weight[i-1] <= j){
		memo[i][j] = max(value[i-1] + maximumValue(weight, value, memo,i-1,j-weight[i-1]),
						maximumValue(weight, value, memo, i-1, j));
	}else{
		memo[i][j] = maximumValue(weight, value, memo, i-1, j);
	}
	return memo[i][j];
}

int main(){
	cin >> N >> W;
	vector<int> weight(N);
	vector<int> value(N);
	
	for (int i = 0; i < N; i++){
		cin >> weight[i] >> value[i];
	}
	
	vector<vector<int>> memo(N+1, vector<int>(W+1, -1));
	cout << maximumValue(weight, value, memo, N, W) << endl;
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= W; j++){
			if(memo[i][j] == -1){
				cout << 0 << " ";
			}else{
				cout << memo[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	
	return 0;
}


/*
4 7
1 1
3 4
4 5
5 7


*/

