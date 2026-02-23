#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

bool check(vector<int> &x, int n){
	bool flag = true;
	for (int j = 1; j <= n; j++){
		for (int p = 0; p < j; p++){
			if(abs(p - j) == abs(x[p] - x[j]) || (x[p] == x[j])){
				flag = false;
			}
		}
	}
	return flag;
}

void permute(vector<int> &x, int start, int end){
	if(start == end+1){
		for(int i = 1; i <= end; i++){
			cout << x[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= end; i++){
		swap(x[start], x[i]);
		if(check(x, start)){
			permute(x, start + 1, end);
		}
		swap(x[start], x[i]);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> x(n+1);
	for (int i = 0; i <= n; i++){
		x[i] = i;
	}
	permute(x,1, n);
	return 0;
}


/*

4 

*/