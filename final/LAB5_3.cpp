#include<iostream>
#include<vector>
using namespace std;
int max_v = -1;

void subset1(vector<int> &x, vector<int> &V, vector<int> &W, int l, int r, int k){
	if(l == r){
		int v_temp = 0, w_temp = 0;
		for (int i = 1; i <= l; i++){
			if(x[i] == 1){
				v_temp += V[i-1];
				w_temp += W[i-1];
			}
		}
		
		if(w_temp <= k && v_temp > max_v){
			max_v = v_temp;
		}
		return;
	}
	
	x[l + 1] = 1;
	subset1(x, V, W, l + 1, r, k);
	x[l + 1] = 0;
	subset1(x, V, W, l + 1, r, k);
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> V(n);
	vector<int> W(n);
	vector<int> x(n+1);
	for (int i = 0; i < n; i++){
		cin >> V[i];
	}
	for (int i = 0; i < n; i++){
		cin >> W[i];
	}
	
	subset1(x, V, W, 0, n, k);
	cout << max_v;
	return 0;
}


/*
4 18 
12 5 4 2 
8 7 4 2

*/