//To become Max

/*

Given an array of integers a of length n

in one operation

choose an index i such that  1 <= i <= n - 1
and ai <= ai+1

increase ai by 1

find the max possible value of
max(a1,a2,... an) after performing this op
at most k times

t cases (100) NOTE THIS
n, k
n integers

sum of n does not exceed 1000 (we can try O(n3) soln)

*/
#include <iostream>
#include <vector>
using namespace std;

bool canReach(const vector<long long>& a, long long k, long long target) {
    int n = a.size();

    for (int i = 0; i < n; i++) {
        long long need = target;
        long long cost = 0;

        for (int j = i; j < n; j++) {
            if (a[j] >= need) {
                return true;
            }

            if (j == n - 1) {
                break;
            }

            cost += need - a[j];

            if (cost > k) break;

            need--;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        long long mx = 0;
        for (long long& x: a) {
            cin >> x;
            mx = max(mx, x);
        }
        long long lo = mx;
        long long hi = mx+k;
        long long ans = mx;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canReach(a, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}