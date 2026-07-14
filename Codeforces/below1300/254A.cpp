//Cards with Numbers

/*
2n cards

split the pairs so that each pair had equal numbers on cards

n

2n positive integers

*/
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<pair<int,int>> v{};
    int n;

    cin >> n;
    int x;
    for (int i = 0; i < 2 * n; i++) {
        cin >> x;
        v.push_back(pair{x, i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < (2 * n) - 1; i+=2) {
        pair<int,int> a = v[i];
        pair<int,int> b = v[i + 1];
        if (a.first != b.first) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < (2 * n) - 1; i+=2) {
        pair<int,int> a = v[i];
        pair<int,int> b = v[i + 1];
        cout << a.second + 1 << " " << b.second + 1 << "\n";
        if (i != (2 * n) - 2) cout << "\n";
    }

}