#include<iostream>

using namespace std;

int sequential_Search(int array[], int num, int k){
	int i = 0;
	while ( (array[i] != k) && (i < num)){
		i++;
	}
	
	if (i < num){
		return i;
	}else{
		return -1;
	}
}

int main(){
	int array[] = {4,7,8,14,22,31,36,62,81,91};
	int num = sizeof(array) / sizeof(int);
	int found = sequential_Search(array, num, 8);
	cout << found;
	return 0;
}