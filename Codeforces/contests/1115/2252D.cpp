//Array Replacement

/*
aaray a of length n

1. choose an index i (2 <= i < n - 1) such that ai-1 and ai+1 
have the same parity

replace ai with ai-1 - ai + ai+1

find the lexicographically smallest array
that can be obtained

t cases
length n
n integers

aim for O(n)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> v(n);
        for (long long& x: v) cin >> x;

        vector<long long> diff(n - 1);
        for (int i = 0; i < n - 1; i++) {
            diff[i] = v[i + 1] - v[i];
        }

        int left = 0;
        while (left < n - 1) {
            int right = left;

            while (right + 1 < n - 1 && ((diff[right + 1] & 1LL) == (diff[left] & 1LL))
            ) {
                right++;
            }

            sort(diff.begin() + left, diff.begin() + right + 1);

            left = right + 1;
        }

        vector<long long> ans(n);
        ans[0] = v[0];
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + diff[i - 1];
        }

        for (long long x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}