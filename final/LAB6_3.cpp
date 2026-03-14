#include<iostream>
#include<vector>
using namespace std;
vector<int> bright(100);
int n, k, ans = 0;

void check(int l, int count, int sum, bool prev){
	if(sum == k){
		if(count >= 2)ans++;
		return;
	}
	if(l == n || sum > k) return;
	
	if(!prev){
		check(l+1, count+1,sum + bright[l], true);
	}
	check(l+1, count, sum, false);
}

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> bright[i];
	check(0, 0, 0, false);
	cout << ans;
	return 0;
}

/*
4 5
1 2 3 4

*/