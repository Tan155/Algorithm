#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findPermutations(vector<char>& current, vector<bool>& used, const vector<char>& letters, int n) {
   
    if (current.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << current[i];
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(letters[i]);
            
            findPermutations(current, used, letters, n);
            
            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0; 

    vector<char> letters(n);
    for (int i = 0; i < n; i++) {
        cin >> letters[i]; 
    }

    sort(letters.begin(), letters.end());

    vector<char> current;
    vector<bool> used(n, false);

    findPermutations(current, used, letters, n);

    return 0;
}