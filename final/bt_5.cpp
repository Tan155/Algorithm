#include<iostream>
using namespace std;

int min_p = -100000;

void print_sol(int x[], int r, int p[], int k){
	int temp_p=0, count=0;
	for (int i = 1; i <= r; i++){
		if(x[i] == 1){
			temp_p += p[i];
			count++;	
		}
//		if(x[i] == 1)cout << p[i] << " ";
	}
	
	if(temp_p <= k && count >= min_p){
		min_p = count;
	}
//	cout << endl;
}

void permute(int x[], int l, int r, int p[], int k){
	if(l == r){
		print_sol(x, r, p, k);
	}else{
		x[l+1] = 1;
		permute(x, l+1, r, p, k);
		x[l+1] = 0;
		permute(x, l+1, r, p, k);
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	int p[n+1];
	int x[n+1];
	
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	
	permute(x, 0, n, p, k);
	cout << min_p;
	return 0;
}