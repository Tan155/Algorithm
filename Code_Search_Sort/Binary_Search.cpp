#include<iostream>
using namespace std;

int binary_Search(int array[], int n, int k){
	int l = 0, r = n-1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(array[mid] == k) return mid;
		
		if(array[mid] < k){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return -1;
}

int binary_Search_Recursive(int array[], int l, int r, int n, int k){
	int mid = (l+r) / 2;
	if(l > r)return -1;
	if(array[mid] == k){
		return mid;
	}
	if (array[mid] < k) return binary_Search_Recursive(array, mid+1, r, n,k);
	if (array[mid] > k) return binary_Search_Recursive(array,l,mid-1,n,k);
}

int main(){
	int array[] = {4,7,8,14,22,31,36,62,81,91};
	
	int num = sizeof(array) / sizeof(int);
	
	int found = binary_Search(array, num, 91);
	
	int found_Recursive = binary_Search_Recursive(array,0,num-1,num,91);
	
	cout << "Binary Search = " << found << endl;
	cout << "Binary Search REcursive = " << found_Recursive << endl;	
	return 0;
}