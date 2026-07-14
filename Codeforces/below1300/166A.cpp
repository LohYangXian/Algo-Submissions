// Rank List

/*
a team solve pa problems with total penalty time ta
b team solve pb problems with total penalty time tb

a > b if pa > pb or if pa = pb and ta < tb

count what number of teams share the Kth place


sort first with total score then we fill a bucket of n spots
*/

#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> v(n);
    vector<pair<int,int>> teams{};

    int p;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> p >> t;
        teams.push_back(pair<int,int>{p, t});
    }

    sort(teams.begin(), teams.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });

    int cur = 0;
    for (int i = 0; i < teams.size(); i++) {
        if (i == 0) {
            v[cur] = 1;
            continue;
        }

        if (teams[i].first == teams[i - 1].first && teams[i].second == teams[i - 1].second) {
            v[cur]++;
            continue;
        } else {
            cur++;
            v[cur]++;
            continue;
        }
    }

    pair<int, int> target = teams[k - 1];
    int ans = 0;

    for (const auto& team : teams) {
        if (team == target) {
            ans++;
        }
    }

    cout << ans;
}