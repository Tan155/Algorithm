#include<stdio.h>
int k = 36;

void print_sol(int x[], int r, int x1[]){
	int sum = 0;
	for(int i = 1; i <= r; i++){
		if(x[i] == 1) sum += x1[i];
//		printf("%d", x[i]);
	}
	if(sum == k){
		for(int i = 1; i <= r; i++){
			if(x[i] == 1) printf("%d ", x1[i]);
		}
		printf("= %d", sum);
	}
}

void subset1(int x[], int l, int r,int x1[]){
	if(l == r){
		print_sol(x,r,x1);
	}else{
		x[l+1] = 1;
		subset1(x,l+1,r, x1);
		x[l+1] = 0;
		subset1(x, l+1, r, x1);
	}
}

int main(){
	int n = 4;
	int x1[n+1] = {-1,25, 10, 9, 2};
	int x[n+1];
	subset1(x,0,n,x1);
	return 0;
}

// 25 10 9 2

