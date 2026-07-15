//Sereja and Suffixes

/*
n integers

m integers


*/

#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> v{};
    vector<int> res(n);
    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    unordered_set<int> s{};

    for (int i = v.size() - 1; i >= 0; i--) {
        if (s.find(v[i]) != s.end()) continue;
        s.insert(v[i]);
        res[i] = s.size();
    }

    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << res[x - 1] << "\n";
    }

}