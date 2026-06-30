// Pashmak and Flowers

/*
maximal diff between beauty

1. calc max diff, number of ways u can choose those combi
*/
// #include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    // vector<int> v{};
    unordered_map<int,int> m{};
    cin >> n;
    int x;
    int max_val{numeric_limits<int>::min()};
    int min_val{numeric_limits<int>::max()};

    for (int i = 0; i < n; i++) {
        cin >> x;
        // v.push_back(x);
        if (x > max_val) max_val = x;
        if (x < min_val) min_val = x;
        m[x]++;
    }
    long long ways;

    if (max_val == min_val)
        ways = 1LL * n * (n - 1) / 2;
    else 
        ways = 1LL * m[max_val] * m[min_val];

    cout << max_val - min_val << " " << ways;


}