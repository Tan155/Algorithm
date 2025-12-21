#include<iostream>
using namespace std;


int stone(int arr[], int l, int r){
	if(r-l == 2){
		if(arr[l] == arr[l+1] && arr[l] != arr[r]){
			return r;
		}else if(arr[l] == arr[r] && arr[l] != arr[l+1]){
			return l+1;
		}else if(arr[l+1] == arr[r] && arr[l+1] != arr[l]){
			return l;
		}else{
			return l;
		}
		
	}else{
		int st = (l + r) / 3;
		int s1 = stone(arr,l,st);
		int s2 = stone(arr,st+1, st+st+1);
		int s3 = stone(arr,st + st + 2, r);
		if(arr[s1] == arr[s2] && arr[s1] != arr[s3]){
			return s3;
		}else if(arr[s1] == arr[s3] && arr[s1] != arr[s2]){
			return s2;
		}else if(arr[s2] == arr[s3] && arr[s2] != arr[s1]){
			return s1;
		}
	}
}

int main(){
	int arr[] = {1, 1, 1, 1, 1, 1, 1, 2, 1};
	int n = sizeof(arr) / sizeof(int);
	int value = stone(arr,0,n-1);
	cout << value;
	return 0;
}