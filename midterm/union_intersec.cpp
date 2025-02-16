#include<iostream>
using namespace std;

int Intersec[10000];
int Union[10000];
int main(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		Intersec[a[i]] += 1;
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		Intersec[b[i]] += 1;
	}
	
	for(int i = 0; i < n; i++){
		if(Intersec[a[i]] == 2){
			cout << a[i] << " ";
		}
	}
	
	
	
	return 0;
}