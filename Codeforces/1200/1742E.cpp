//Scuza

/*
n steps,
ith step is ai meters higher than its predecessor

first step is a1 meters higher than the ground

q questions, k1, ... kq

print the max height u can achieve by climbing the steps if his legs are 
of length ki

can only climb jth step if legs are of length aj
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int q;
        cin >> n >> q;
        vector<long long> pre{};
        vector<long long> v{};
        vector<long long> heights{};
        long long x;
        long long sum{};
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
            heights.push_back(sum);
            v.push_back(x);
        }

        long long curMax = v[0];
        for (int i = 0; i < n; i++) {
            if (v[i] > curMax) {
                curMax = v[i];
            }
            pre.push_back(curMax);
        }

        vector<pair<long long, long long>> search{};
        for (int i = 0; i < n; i++) {
            search.push_back(pair{pre[i], heights[i]});
        }

        sort(search.begin(), search.end());

        for (int i = 0; i < q; i++) {
            cin >> x;
            auto it = upper_bound(search.begin(), search.end(), pair{x, numeric_limits<long long>::max()});
            if (it == search.begin()) {
                cout << 0 << " ";
                continue;
            }
            pair<long long, long long> p = *--it;
            cout << p.second << " ";
        }
        cout << "\n";
    }
}