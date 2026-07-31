//Deep Down below

/*
n caves, 
enter all caves in some order, exactly once

enter cave i, fight ki monsters in a row

beat monster if power > armor,
game ends if he cant beat the current monster

each time he beats a monster, pow += 1

find smallest possible power hero must start level
to enter all caves in some order n beat all monsters

t cases
n caves
next n lines, k integers
*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> v{};
        vector<pair<int,int>> intervals{};

        for (int i = 0; i < n; i++) {
            int k;
            vector<int> cave{};
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                cave.push_back(x + 1 - j);
            }
            v.push_back(cave);
        }

        for (int i = 0; i < n; i++) {
            int maxi = *max_element(v[i].begin(), v[i].end());
            intervals.push_back({maxi, v[i].size()});
        }

        sort(intervals.begin(), intervals.end());

        int ans = intervals[n - 1].first;
        for (int i = n - 2; i >= 0; i--) {
            int prev = ans;
            pair<int,int> cur = intervals[i];
            ans = max(ans - cur.second, cur.first);
        }
        cout << ans << "\n";
    }
}