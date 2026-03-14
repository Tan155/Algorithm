#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int N;
    cin >> N;

    vector<int> value(N), cnt(N);
    for (int i = 0; i < N; i++) cin >> value[i];
    for (int i = 0; i < N; i++) cin >> cnt[i];

    int M;
    cin >> M;

    vector<int> dp(M + 1, INF);
    vector<vector<int>> use(M + 1, vector<int>(N, 0));

    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < cnt[i]; k++) {
            for (int j = M; j >= value[i]; j--) {
                if (dp[j - value[i]] + 1 < dp[j]) {
                    dp[j] = dp[j - value[i]] + 1;
                    use[j] = use[j - value[i]];
                    use[j][i]++;
                }
            }
        }
    }

    if (dp[M] == INF) {
        cout << "impossible";
        return 0;
    }

    cout << dp[M] << endl;

    vector<pair<int,int>> ans;

    for (int i = 0; i < N; i++) {
        if (use[M][i] > 0)
            ans.push_back({value[i], use[M][i]});
    }

    sort(ans.begin(), ans.end(), greater<pair<int,int>>());

    for (auto &p : ans) {
        cout << p.first << ":" << p.second << endl;
    }
}
/*
3 
1 2 5 
10 20 10 
1000

3 
1 10 20 
5 2 3 
85

3 
6 5 1 
2 2 4 
10

*/