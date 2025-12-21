#include<iostream>

using namespace std;

void selection_Search(int array[], int n){
	int i, j, min, temp;
	for (i = 0; i < n-1; i++){
		min = i;
		for(j = i+1; j < n; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

int main(){
	int array[] = {4,31,36,14,62,91,8,22,7,81};
	int n = sizeof(array) / sizeof(int);
	selection_Search(array, n);
	for (int i = 0; i < n; i++){
		cout << array[i] << " ";	
	}
	return 0;
}