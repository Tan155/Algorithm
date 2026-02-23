#include <iostream>
#include <vector>

using namespace std;

int totalCount = 0;


void subset1(vector<int> &arr, vector<int> &x, int l, int n, int sum, int k, int lampCount) {

    if (sum == k) {
        if (lampCount >= 2) {
            totalCount++;
        }
        return;
    }


    if (l >= n || sum > k) {
        return;
    }


    if (l == 0 || x[l - 1] == 0) {
        x[l] = 1;
    	subset1(arr, x, l + 1, n, sum + arr[l], k, lampCount + 1);
    	x[l] = 0;
    }
    
    subset1(arr, x, l + 1, n, sum, k, lampCount);
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> arr(n);
    vector<int> x(n, 0); 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    subset1(arr, x, 0, n, 0, k, 0);

    cout << totalCount << endl;
    return 0;
}