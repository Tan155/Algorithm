#include<iostream>
#include<vector>
using namespace std;
#define MAXSIZE 100
#define UNDEFINED 0

int count = 0;

int fib(int n){
	count++;
	if(n <= 1) return n;
	return fib(n-1) + fib(n-2);
}

vector<int> memo(MAXSIZE, UNDEFINED);
int fib_DP(int n){
	if(memo[n] == UNDEFINED){
		count++;
		if(n <= 1){
			memo[n] = n;
		}else{
			memo[n] = fib_DP(n-1) + fib_DP(n-2);
		}
	}
	return memo[n];
}

int fib_BottomUp_DP(int n){
	memo[0] = 0;
	memo[1] = 1;
	
	for (int i = 2; i <= n; i++){
		memo[i] = memo[i-1] + memo[i-2];
	}
	return memo[n];
}

int main(){
	int n;
	cin >> n;
	
	cout << "Fib : " << fib(n) << " count = " << count << "\n";
	count = 0;
	cout << "Fib_DP : " << fib_DP(n) << " count DP = " << count << "\n";
	count = 0;
	cout << "fib_BottomUp_DP : " << fib_BottomUp_DP(n) << "\n";
	return 0;
}