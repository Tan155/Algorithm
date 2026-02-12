#include<iostream>
#include<string>
using namespace std;
int c = 0;

void swap(string *a, string *b){
	string temp = *a;
	*a = *b;
	*b = temp;
}

void permute(string x[], int start, int end){
	if(start == end){
		int find = 1;
		while(x[find] != "g1")find++;
		if(x[find-1] != "g2" && x[find+1] != "g2"){
			for (int i = 1; i <= end; i++){
				cout << x[i] << " ";
			}
			c++;
			cout << endl;
		}
		return;
	}
	for (int i = start; i <= end; i++){
		swap(&x[start], &x[i]);
		permute(x, start + 1, end);
		swap(&x[start], &x[i]);
	}
}

int main(){
	int m,n;
	cin >> m >> n;
	int number = m + n;
	string x[number + 1];
	for (int i = 1; i <= m; i++){
		x[i] = "b" + to_string(i);
	}
	for (int i = 1; i <= n; i++){
		x[m+i] = "g" + to_string(i);
	}
	permute(x, 1, number);
	cout << c;
	return 0;
}