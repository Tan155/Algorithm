#include<iostream>
using namespace std;

void insertion_Sort(int array[], int n){
	int i,j,v;
	for(int i = 1; i < n; i++){
		v = array[i];
		j = i-1;
		while(j >= 0 && array[j] > v){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = v;
	}
}

int main(){
	int array[] = {4,31,36,14,62,91,8,22,7,81};
	int n = sizeof(array) / sizeof(int);
	insertion_Sort(array, n);
	
	for (int i = 0; i < n; i++){
		cout << array[i] << " ";
	}
	return 0;
}