#include<iostream>
#include<algorithm>
using namespace std;
int c = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int x[], int start, int end){
	if(start == end){
		for (int i = 1; i <= end; i++){
			cout << x[i] << " ";
		}
		c++;
		cout << endl;
		return;
	}
	for (int i = start; i <= end; i++){
		swap(&x[start], &x[i]);
		sort(x + start + 1, x + end + 1);
		permute(x, start + 1, end);
		swap(&x[start], &x[i]);
	}
}

int main(){
	int n;
	cin >> n;
	int x[n + 1] = {-1};
	for (int i = 1; i <= n; i++){
		x[i] = i;
	}
	permute(x, 1, n);
	cout << c;
	return 0;
}