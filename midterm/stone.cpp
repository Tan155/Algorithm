#include<iostream>

using namespace std;

int ar[100000];

int stone(int l,int r){
	if(r-l+1 == 3){ //base case
		if(ar[l] == ar[l+1] && ar[l] != ar[r]){
			return r;
		}else if(ar[l] == ar[r] && ar[l] != ar[l+1]){
			return l+1;
		}else if(ar[l+1] == ar[r] && ar[r] != ar[l]){
			return l;
		}
	}else{
		int st = (l+r - 1) / 3;
		int first = stone(l, st);
		int second = stone(st+1, st+st+1);
		int third = stone(st+2+st, r);
		
		if(ar[first] == ar[second] && ar[first] != ar[third]){
			return third;
		}else if(ar[first] == ar[third] && ar[first] != ar[second]){
			return second;
		}else if(ar[second] == ar[third] && ar[third] != ar[first]){
			return first;
		}
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> ar[i];
	}
	
	cout << stone(0, n-1);
	return 0;
}