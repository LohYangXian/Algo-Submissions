// Dragons

// n dragons
// initial strength s
// if duel i dragon, and s <= xi, he loses. but if s > xi, he wins and s += xi, 
// sort the array and then one pass to see if he can win

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int s;
    int n;
    cin >> s >> n;
    vector<pair<int,int>> v{};
    int a;
    int b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(pair{a, b});
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int,int>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++) {
        if (s <= v[i].first) {
            cout << "NO";
            return 0;
        }
        s += v[i].second;
    }
    cout << "YES";
}