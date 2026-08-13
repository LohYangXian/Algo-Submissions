//2^Sort

/*
a array of length n
k

find indices 1 <= i <= n - k
subarray with length k + 1 has property

if u multiply first eleme by 2^0, 2nd element by 2^1, 
.,... until (k + 1) by 2^k, this subarray is sorted in strcitly
increasing order

count number of indices

t cases
n, k

n integers

find a O(n) soln
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; int k;
        cin >> n >> k;

        vector<long long> v{};
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        int l = 0;
        int r = 1;
        long long ans = 0;
        while (r < v.size()) {
            if (v[r] * 2 > v[r - 1]) {
                if (r - l + 1 == k + 1) {
                    ans++;
                    l++;
                }
            } else {
                l = r;
            }
            r++;
        }
        cout << ans << "\n";
    }
}
