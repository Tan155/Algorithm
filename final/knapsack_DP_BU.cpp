#include<iostream>
#include<vector>
using namespace std;
int N, W;

int maximumValue(vector<vector<int>> &memo, vector<int> &weight, vector<int> &value, int i, int j){
	if(i == 0 || j == 0) return memo[i][j] = 0;
	
	if(weight[i] <= j){
		memo[i][j] = max(value[i] + maximumValue(memo,weight,value, i-1, j - weight[i]),
						maximumValue(memo,weight,value, i-1,j));
	}else{
		memo[i][j] = maximumValue(memo,weight,value, i-1,j);
	}
	return memo[i][j];
}

int main(){
	cin >> N >> W;
	vector<vector<int>> memo(N+1, vector<int>(W+1, 0));
	vector<int> weight(N);
	vector<int> value(N);
	for (int i = 0; i < N; i++){
		cin >> weight[i] >> value[i];
	}
	
	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= W; j++){
			if(weight[i-1] <= j){
				memo[i][j] = max(value[i-1] + memo[i-1][j-weight[i-1]],
								memo[i-1][j]);
			}else{
				memo[i][j] = memo[i-1][j];
			}
		}
	}
	cout << memo[N][W];
	
	cout << "\n";
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= W; j++){
			cout << memo[i][j] << " ";
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