#include<iostream>
#include<algorithm>
using namespace std;

void swap(string *a, string *b){
	string temp = *a;
	*a = *b;
	*b = temp;
}

void subset1(string x[], int start, int end){
	if(start == end){
		for (int i = 1; i <= end; i++){
			cout << x[i] << " ";
		}
		cout << endl; return;
	}
	
	for (int i = start; i <= end; i++){
		swap(&x[start], &x[i]);
		sort(x + start + 1, x + end + 1);
		subset1(x, start + 1, end);
		swap(&x[start], &x[i]);
	}
}

int main(){
	int n;
	cin >> n;
	string x[n+1];
	for (int i = 1; i <= n; i++){
		cin >> x[i];
	}
	sort(x + 1, x + n + 1);
	subset1(x, 1, n);
	return 0;
}