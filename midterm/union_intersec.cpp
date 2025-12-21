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
	
	//intersec
	for (int i = 0; i < n; i++){
		if(Intersec[a[i]] == 2){
			cout << a[i] << " ";
		}
	}
	
	cout << endl;
	
	//union
	for (int i = 0; i < n; i++){
		if(Union[a[i]] == 0){
			cout << a[i] << " ";
			Union[a[i]] = 1;
		}
	}
	for (int i = 0; i < n; i++){
		if(Union[b[i]] == 0){
			cout << b[i] << " ";
			Union[b[i]] = 1;
		}
	}
	return 0;
}