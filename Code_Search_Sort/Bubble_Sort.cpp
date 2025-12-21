#include<iostream>

void swap(int array[], int i,int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
void bubble_Sort(int array[], int num){
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num-1 ; j++){
			if (array[j] > array[j+1]){
				swap(array,j,j+1);
			}
		}
	}
}

using namespace std;
int main(){
	int array[] = {4,31,36,14,62,91,8,22,7,81};
	int num = sizeof(array) / sizeof(int);
	bubble_Sort(array, num);
	
	for (int i = 0; i < num; i++){
		cout << array[i] << " ";
	}
	return 0;
}