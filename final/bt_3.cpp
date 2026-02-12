#include<iostream>
using namespace std;

int max_v = 0;

void print_sol(int x[], int r, int w[], int v[], int k){
	int w_temp=0, v_temp=0;
	for(int i = 1; i <= r; i++){
		if(x[i] == 1){
			w_temp += w[i];
			v_temp += v[i];
		}
	}
	
	if(w_temp <= k && v_temp > max_v){
		max_v = v_temp;
	}
}


void permute(int x[], int l, int r, int w[], int v[], int k){
	if(l == r){
		print_sol(x,r,w,v, k);
	}else{
		x[l+1] = 1;
		permute(x,l+1,r,w,v, k);
		x[l+1] = 0;
		permute(x,l+1,r,w,v, k);
	}
}

int main(){
	int n,k;
	cin >> n >> k;
	int w[n+1];
	int v[n+1];
	int x[n+1];
	
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	
	permute(x,0, n, w,v, k);
	cout << max_v << endl;
	return 0;
}