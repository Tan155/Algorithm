#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int start, end;
};

bool compareLines(Line a, Line b) {
    return a.start < b.start;
}

int main() {
    int M;
    cin >> M; 

    vector<Line> lines;
    int s, e;
    while (cin >> s >> e && (s != 0 || e != 0)) {
        lines.push_back({s, e});
    }

    sort(lines.begin(), lines.end(), compareLines);

    int count = 0;
    int current_reach = 0;
    int i = 0;
    bool possible = true;

    while (current_reach < M) {
        int best_end = current_reach;
        bool found = false;

        while (i < lines.size() && lines[i].start <= current_reach) {
            if (lines[i].end > best_end) {
                best_end = lines[i].end;
                found = true;
            }
            i++;
        }

        if (!found) {
            possible = false;
            break;
        }

        current_reach = best_end;
        count++;
    }

    if (possible) cout << count << endl;
    else cout << 0 << endl;

    return 0;
}


/*
9
1 2
3 5
-1 5
2 4
4 5
3 6
2 7
7 9
4 8
0 0


*/