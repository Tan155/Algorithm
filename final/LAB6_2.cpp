#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_count = 100;
vector<int> result_path;

void cutWire(int L, vector<int>& sizes, vector<int>& current) {
    if (L == 0) {
        if (current.size() < min_count) {
            min_count = current.size();
            result_path = current;
        }
        return;
    }
    if (L < 0) return;

    for (int i = 0; i < sizes.size(); i++) {
        current.push_back(sizes[i]);  
        cutWire(L - sizes[i], sizes, current); 
        current.pop_back();                
    }
}

int main() {
    int n = 3, L = 8;
    vector<int> sizes = {2, 3, 5};

    sort(sizes.rbegin(), sizes.rend());

    vector<int> current;
    cutWire(L, sizes, current);

    sort(result_path.begin(), result_path.end());
    for (int x : result_path) cout << x;

    return 0;
}