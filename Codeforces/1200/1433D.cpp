// Districts Connection

/*
n districts, ith district belongs to aith bandit gang
no districts are connected to each other

build n - 1 two way roads to connect all the districts

do not connect 2 districts from the same gang,
connect n districts with n-1roads, alternatting gangs

if impossible, return no

t cases
n districts
a a a a a a a integers
*/

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int,vector<int>> m{};
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            m[x].push_back(i);
        }
        if (m.size() < 2) {
            cout << "NO" << "\n";
            continue;
        } else {
            cout << "YES" << "\n";
        }

        auto it = m.begin();

        int firstGang = it->first;
        int firstAnchor = it->second[0];

        ++it;

        int secondAnchor = it->second[0];

        for (auto& [gang, districts] : m) {
            if (gang == firstGang) {
                continue;
            }

            for (int district : districts) {
                cout << firstAnchor << " " << district << '\n';
            }
        }

        for (int district : m[firstGang]) {
            if (district == firstAnchor) {
                continue;
            }

            cout << secondAnchor << " " << district << '\n';
        }
    }
}