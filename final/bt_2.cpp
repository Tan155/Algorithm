#include<iostream>
using namespace std;
void print_sol(int x[], int x1[], int r, int k){
	int sum = 0;
	for (int i = 1; i <= r; i++){
		if(x[i] == 1) sum += x1[i];
	}
	
	if(sum == k){
		for (int i = 1; i <= r; i++){
			if(x[i] == 1) cout << x1[i] << " ";
		}
		cout << endl;
	}
}

void permute(int x[], int x1[], int l ,int r, int k){
	if(l == r){
		print_sol(x,x1,r,k);
	}else{
		x[l+1] = 1;
		permute(x,x1,l + 1, r,k);
		x[l+1] = 0;
		permute(x,x1,l+1, r,k);
	}
}

int main(){
	int n,k;
	cin >> n >>  k;
	int x1[n+1];
	int x[n+1];
	for(int i = 1; i <= n; i++){
		cin >> x1[i];
	}
	
	permute(x,x1, 0, n, k);
	return 0;
}



/*

5 12
25 10 9 2

*/