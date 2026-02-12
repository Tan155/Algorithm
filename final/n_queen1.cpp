#include<stdio.h>
#include<math.h >
int n=4, x[4], ct = 0;

void n_queens(int k){
	if(k == n){ //place all queens on the board
		int flag = 0;
		ct++;
		for (int j = 1; j < k; j++){ //check any two queens
			for (int p = 0; p < j; p++){
				if(abs(p-j) == abs(x[p]-x[j]) || (x[j] == x[p])){
					flag = 1;
				}
			}
		}
		if(flag == 0){ // no conflict print sol
				for(int i = 0; i < k; i++){
					printf("%d ", x[i]);
				}
				printf("\n");
		}
	}else{
		for(int row = 0; row < n; row++){ // place queen k on row 1
			x[k] = row;
			n_queens(k + 1); // place next queen
		}
	}
}


int main(){
	n_queens(0);
	printf("%d", ct);
	return 0;
}