// Sale

/*
n TV sets, TV set with index i costs a bellars.
Some tv has negative price
carry at most m TV sets.
Find out maximum sum of money

Actually you can just sum up the negative values, top m negative values

*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int m;
    vector<int> v;
    int res{};

    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < 0) {
            v.push_back(-x);
        }
    }

    sort(v.begin(), v.end(), greater<int>{});
    int sz = v.size();
    for (int i = 0; i < min(m, sz); i++) {
        res+= v[i];
    }
    cout << res;

}