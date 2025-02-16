#include<iostream>
using namespace std;

int arr[10000];


int stone(int l,int r){
	if(r-l+1 == 3){
		if(arr[l] == arr[l+1] && arr[l] != arr[r]){
			return r;
		}else if(arr[l] == arr[r] && arr[l] != arr[l+1]){
			return l+1;
		}else if(arr[l+1] == arr[r] && arr[r] != arr[l]){
			return l;
		}
	}else{
		int st = (l+r -1)/3;
		int first = stone(l,st);
		int second = stone(st+1, st+st+1);
		int third = stone(st+2+st,r);
		
		if(arr[first] == arr[second] && arr[first] != arr[third]){
			return third;
		}else if(arr[first] == arr[third] && arr[first] != arr[second]){
			return second;
		}else if(arr[second] == arr[third] && arr[third] != arr[first]){
			return first;
		}	
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << stone(0,n-1);
	return 0;
}