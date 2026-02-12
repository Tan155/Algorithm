#include<iostream>
using namespace std;

int V[] = {12,5,4,2};
int W[] = {8,7,4,2};
int max_v = -1;
int ans[4];
int K = 18;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void printSol(int x[], int n){
	int w_temp=0,v_temp=0;
	for (int i = 1; i<= n; i++){
		if(x[i] == 1){
			w_temp += W[i-1];
			v_temp += V[i-1];
		}
	}
	
	if(w_temp <= K && v_temp > max_v){
		max_v = v_temp;
		for (int i = 1; i <= n; i++){
			ans[i] = x[i];
		}
	}
}

void subset2(int x[], int l, int r){
	if(l == r){
		printSol(x, r);
	}else{
		x[l + 1] = 1;
		subset2(x, l + 1, r);
		x[l + 1] = 0;
		subset2(x, l + 1, r);
	}
}

int main(){
	int n = 4;
	int x[n];
	subset2(x, 0, n);
	for (int i = 1;i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}