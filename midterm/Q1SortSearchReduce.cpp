#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	string s = "";
	for (int i = 0; i < n; i++){
		s += to_string(a[i]);
		cout << a[i];
	}
	
	bool hasDuplicate = false;
	for (int i = 1; i < s.length(); i++){
		if(s[i] == s[i - 1]){
			hasDuplicate = true; break;
		}
	}
	
	cout << endl;
	
	if(hasDuplicate){
		int cnt = 1;
    	int maxCnt = 1;

    
	    for(int i = 1; i < s.length(); i++){
	        if(s[i] == s[i - 1]){
	            cnt++;
	            if(cnt > maxCnt){
	                maxCnt = cnt;
	            }
	        } else {
	            cnt = 1;
	        }
	    }
	
	    
	    cnt = 1;
	    for(int i = 1; i < s.length(); i++){
	        if(s[i] == s[i - 1]){
	            cnt++;
	        } else {
	            if(cnt == maxCnt){
	                cout << s[i - 1] << " ";
	            }
	            cnt = 1;
	        }
	    }
	
	    if(cnt == maxCnt){
	        cout << s.back() << " ";
	    }
	
	    cout << endl;
	}	
	
	if(!hasDuplicate){
	    bool used[10] = {false};
	
	        for(char c : s){
	            used[c - '0'] = true;
	        }
	
	        for(int i = 0; i <= 9; i++){
	            if(used[i]){
	                cout << i << " ";
	            }
	        }
	    cout << endl;	
	}
	
	string reduce = "";
	reduce += s[0];
	
	for (int i = 1; i < s.length(); i++){
		if(s[i] != s[i - 1]){
			reduce += s[i];
		}
	}
	cout << reduce;
	return 0;
}