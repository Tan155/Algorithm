#include<iostream>
#include<algorithm>
using namespace std;

void print_sol(char c[],int end){
	for(int i = 1; i <= end; i++){
		cout << c[i];
	}
	cout << endl;
}

void permute(char c[], int start, int end){
	if(start == end){
		print_sol(c, end);
		return;
	}
	
	for(int i = start; i <= end; i++){
		swap(c[start], c[i]);
		sort(c + start + 1, c + end + 1);
		permute(c, start+1, end);
		swap(c[start], c[i]);
	}
}

int main(){
	int n;
	cin >> n;
	char c[n+1];
	for(int i = 1; i<= n;i++){
		cin >> c[i];
	}
	sort(c+1, c + n + 1);
	permute(c, 1, n);
	return 0;
}