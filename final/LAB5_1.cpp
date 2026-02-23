#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

void permute(vector<int> &arr, int start, int end){
	if(start == end){
		int find = 1;
		while(arr[find] != 1)find++;
		if(arr[find-1] == 2 || arr[find+1] == 2){
			for (int i = 1; i <= end; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = start; i <= end; i++){
		swap(arr[start], arr[i]);
		permute(arr, start + 1, end);
		swap(arr[start], arr[i]);
	}
	
}


int main(){
	int n;
	cin >> n;
	vector<int> arr(n+1);
	for (int i = 0; i <= n; i++){
		arr[i] = i;
	}
	permute(arr, 1, n);
	return 0;
}


/*
3

4
*/