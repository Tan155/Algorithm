#include<iostream>
#include<math.h>
using namespace std;

int interpolation_Search(int array[],int n,int k){
	int l = 0, r = n-1;
	while(l <= r){
		int x = l + abs( ((k - array[l]) * (r - l)) / (array[r]-array[l]));
		if (array[x] == k){
			return x;
		}
		if (array[x] < k){
			l = x+1;
		}else{
			r = x-1;
		}
	}
	return -1;
}

int main(){
	int array[] = {4,7,8,14,22,31,36,62,81,91};
	int num = sizeof(array) / sizeof(int);
	int found = interpolation_Search(array, num, 81);
	cout << "Interpolation = " << found << endl;
	return 0;
}