#include<iostream>
using namespace std;

int main(){
	int arr[] = {0,4,2,2,0,0,1,1,0,1,0,2,4,2};
	int n = sizeof(arr) / sizeof(int);
	
	int count[100] = {0};
	for (int i=0;i < n; i++){
		count[arr[i]]++;
	}
	
	for (int i = 0; i < 100; i++){
		while(count[i] > 0){
			cout << i << " "; count[i]--;
		}
	}
	return 0;
}