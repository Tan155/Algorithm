#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct item{
	int weight, value;
	double density;	
};

bool compare(item a, item b){
	return a.density > b.density;
}

int main(){
	int N, W;
	cin >> N >> W;
	vector<item> bag(N);
	for(int i = 0; i < N; i++){
		int w, v;
		cin >> w >> v;
		double d = (double) v / w;
		bag[i].weight = w, bag[i].value = v, bag[i].density = d;
	}
	sort(bag.begin(), bag.end(), compare);
	double currentWeight = 0, currentValue = 0;
	
	for(int i = 0; i < N; i++){
		if(currentWeight + bag[i].weight <= W){
			currentWeight += bag[i].weight;
			currentValue += bag[i].value;
		}else{
			int remain = W - currentWeight;
			currentWeight += bag[i].weight * ( (double) remain / bag[i].weight );
			currentValue += bag[i].value * ( (double) remain / bag[i].weight ); 
		}
	}
	cout << "CurrentWeight " << currentWeight << "\n";
	cout << "currentValue " << currentValue << "\n";
	return 0;
}


/*
4 25
18 25
15 24
10 15
5 8

*/