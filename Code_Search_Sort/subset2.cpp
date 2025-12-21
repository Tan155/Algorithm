#include<iostream>
using namespace std;


void subset2(int x[], int l,int r){
	if(l == r){
		for (int i = 1; i <= r; i++){
			cout << x[i] << " ";
		}
		cout << endl;
	}else{
		x[l + 1] = 1;
		subset2(x, l + 1, r);
		x[l + 1] = 0;
		subset2(x, l + 1, r);
	}
}

int main(){
	int n = 3;
	int x[n + 1];
	subset2(x,0,n);
	return 0;
}