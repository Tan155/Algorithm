#include<iostream>

using namespace std;
//      data : 0 = x, 1 = y;
int ar[100000][2];
int status[10000] = {1};
void merge(int l, int m, int r){
	int i,j,k=l;
	int n1 = m - l + 1, n2 = r - m;
	int a[n1][2],b[n2][2];
	for(i = 0; i < n1; i++){
		a[i][0] = ar[l + i][0];
		a[i][1] = ar[l + i][1];
	}
	for(j = 0; j < n2; j++){
		b[j][0] = ar[m + 1 + j][0];
		b[j][1] = ar[m + 1 + j][1];
	}
	i=0;j=0;
	while(i < n1 && j < n2){
		if(a[i][0] < b[j][0]){
			ar[k][0] = a[i][0];
			ar[k][1] = a[i][1];
			i++;
		}else{
			ar[k][0] = b[j][0];
			ar[k][1] = b[j][1];
			j++;
		}
		k++;
	}
	while(i < n1){
		ar[k][0] = a[i][0];
		ar[k][1] = a[i][1];
		i++; k++;
	}
	while(j < n2){
		ar[k][0] = b[j][0];
		ar[k][1] = b[j][1];
		j++; k++; 
	}
}

void mergeSort(int l,int r){
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(l,m);
		mergeSort(m+1, r);
		merge(l,m,r);
	}
}

void conq(int l,int m,int r){
	int k;
	for(int i = m+1; i <=r; i++){ //find first of right
		if(status[i] == 1){
			k = i;break;
		}
	}
	for (int i = l; i <=m; i++){
		if(status[i] == 1 && ar[i][1] < ar[m+1][1]){
			status[i] = 0;
		}
	}
}

void maxima(int l,int r){
	if(l < r){
		int m = (l + r-1) / 2;
		maxima(l,m);
		maxima(m+1,r);
		conq(l,m,r);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i <n; i++){
		cin >> ar[i][0] >> ar[i][1];
	}
	mergeSort(0, n-1);
	for(int i = 0; i < n; i++){
		cout << ar[i][0] << "," << ar[i][1] << " , ";
	}
	
	for (int i = 0; i < 10000; i++){
		status[i] = 1;
	}
	
	maxima(0,n-1);
	cout << endl;
	for(int i = 0; i < n; i++){
		if(status[i] == 1){
			cout << ar[i][0] << "," << ar[i][1] << " , ";
		}
	}
	return 0;
}


/*
9
1 4
2 6
3 1
4 5
5 7
6 9
7 2
8 6
9 3
*/