//puzzles

/*
n students
m puzzles
f pieces

difference between number of pieces as small 
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    int r{};
    int l{};
    vector<int> v{};
    cin >> n >> m;
    l = 0;
    r = n - 1;

    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int res{numeric_limits<int>::max()};

    while (r < m) {
        res = min(res, v[r] - v[l]);
        r += 1;
        l += 1;
    }

    cout << res;
}