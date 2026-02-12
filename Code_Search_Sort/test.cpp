#include<iostream>
using namespace std;

int count = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printSol(int x[],int n){
	for (int i = 1; i <= n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

void subset1(int x[], int start, int end){
	if (start == end){
		int i = 0;
		while(x[i] != 1)i++;
		if((x[i-1] == 2 || x[i + 1] == 2)) count++; return;
//		printSol(x,start); return;	
	}
	for (int i = start; i <= end; i++){
		swap(&x[start], &x[i]);
		subset1(x, start + 1, end);
		swap(&x[start], &x[i]);
	}
}



int main(){
	int n;
	cin >> n;
	int x[n] = {0};
	for (int i = 1; i <= n; i++){
		x[i] = i;
	}
	subset1(x, 1, n);
	cout << count;
	return 0;
}