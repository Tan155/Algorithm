#include<iostream>
#include<vector>
using namespace std;
int V[4];
int W[4];
int max_v = -1;
int ans[4];
int K;

void printSol(int x[], int n){
	int v_temp=0, w_temp = 0;
	for (int i = 1; i <= n; i++){
		if(x[i] == 1){
			v_temp += V[i-1];
			w_temp += W[i-1];
		}
	}
	
	if(w_temp <= K && v_temp > max_v){
		max_v = v_temp;
		for(int j = 1; j <= n; j++){
			ans[j] = x[j];
		}
	}
}

void subset1(int x[], int l, int r){
	if(l == r){
		printSol(x,r);
	}else{
		x[l + 1] = 1;
		subset1(x, l + 1, r);
		x[l + 1] = 0;
		subset1(x, l + 1, r);
	}
}

int main(){
	cin >> K;
	int n = 4;
	int x[n];
	for (int i = 0; i < n; i++){
		cin >> V[i];
	}
	for (int i = 0; i < n; i++){
		cin >> W[i];
	}
	subset1(x, 0, n);
	
	cout << max_v;
	return 0;
}