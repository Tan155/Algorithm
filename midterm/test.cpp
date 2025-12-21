#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> Intersec(100);

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	//Intersec
	for (int i = 0; i < n; i++){
		Intersec[a[i]] += 1;
		Intersec[b[i]] += 1;
	}
	for (int i = 0; i < n; i++){
		if(Intersec[a[i]] == 2){
			cout << a[i] << " ";
		}
	}
	cout << endl;
	
	
	//Union
	vector<int> Union(n + n);
	for (int i = 0; i < n; i++){
		Union[i] = a[i]; 
	}
	for (int i = 0; i < n; i++){
		Union[n + i] = b[i];
	}
	sort(Union.begin(), Union.end());
	cout << Union[0] << " ";
	for (int i= 1; i < n+n; i++){
		if(Union[i] != Union[i - 1]){
			cout << Union[i] << " ";
		}
	}
	return 0;
}