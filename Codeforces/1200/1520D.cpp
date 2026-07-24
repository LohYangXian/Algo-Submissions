// Same Differences

/*
array a of n integers

Count number of pairs of indices (i,j) such
i < j and aj - ai = j - i

t cases 
n integers

try an O(n) soln
*/

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v{};
        unordered_map<int,int> m{};
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            v.push_back(x - i);
        }

        long long res{};

        for (int i = n - 1; i >= 0; i--) {
            if (m.find(v[i]) != m.end()) {
                res += m[v[i]];
            }
            m[v[i]]++;
        }

        cout << res << "\n";
    }
}