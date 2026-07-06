// Big Segment

/*
n segment, ith segment starts at l and ends at r [l,r]

sort vector of pair<pair<int,int> index>
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    vector<pair<pair<int,int>,int>> v{};

    cin >> n;
    int x;
    int y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        v.push_back(pair{pair{x,y}, i});
    }

    sort(v.begin(), v.end(), [](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
        if (a.first.first == b.first.first) {
            return a.first.second > b.first.second;
        }
        return a.first.first < b.first.first;
    });

    int res = v[0].first.second;
    for (int i = 0; i < n; i++) {
        if (res < v[i].first.second) {
            cout << -1; 
            return 0;
        }
    }
    cout << v[0].second;
}