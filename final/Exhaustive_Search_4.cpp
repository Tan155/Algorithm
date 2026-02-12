#include<iostream>
#include<cmath>
using namespace std;
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool checkValid(int x[], int n){
	bool flag = true;
	for (int p = 1; p <= n; p++){
		for (int j = 0; j < p; j++){
			if( abs(p - j) == abs(x[p] - x[j]) || (x[p] == x[j]) ){
				flag = false;
			}
		}
	}
	return flag;
}

void permute(int x[], int start, int end){
	if(start == end){
		for (int i = 0; i < end; i++){
				cout << x[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for (int  i = start; i < end; i++){
		swap(&x[start], &x[i]);
		if(checkValid(x, start)){
			permute(x, start + 1, end);
		}
		swap(&x[start], &x[i]);
	}
}

int main(){
	int n;
	cin >> n;
	int x[n+1];
	for (int i = 0; i < n; i++){
		x[i] = i;
	}
		
	permute(x, 0, n);
	return 0;
}