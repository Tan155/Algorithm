#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void intersection(vector<int> &A, vector<int> &B, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(A[i] == B[j]){
				cout << A[i] << " ";
			}
		}
	}
	cout << endl;
}

void Union(vector<int> &A, vector<int> &B, int n){
	vector<int> U(n + n);
	int size = 0;
	for(int i = 0; i < n; i++){
		U[size] = A[i]; size++;
	}
	
	for(int i = 0; i < n; i++){
		int found = false;
		for(int j = 0; j < size; j++){
			if(U[j] == B[i]){
				found = true;
			}
		}
		if(!found){
			U[size] = B[i]; size++;
		}
	}
	
	for(int i = 0; i < size; i++){
		cout << U[i] << " ";
	}
	cout << endl;
}


int main(){
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int j = 0; j < n; j++){
		cin >> B[j];
	}
	
	intersection(A, B, n);
	Union(A,B,n);
	return 0;
}