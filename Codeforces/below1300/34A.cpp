// Reconnaissance 2
#include <iostream>
#include <cmath>
#include <utility>
#include <limits>
#include <vector>

using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<int> v{};
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    pair<pair<int,int>, int> res{pair{pair{0,0}, numeric_limits<int>::max()}};
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        if (abs(v[i] - v[next]) < res.second) {
            res = pair{pair{i, next}, abs(v[i] - v[next])};
        }
    }
    cout << res.first.first << " " << res.first.second;
}