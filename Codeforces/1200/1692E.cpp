// Binary Deque

/*
array of length n of 0s and 1s

removes the first or last element of the array

min number of operations to perform such that total
sum of array is equal to s after performing all operations

if impossible, -1
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;

        vector<long long> v{};

        long long x;
        long long sum{};
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x == 1) {
                v.push_back(i);
            }
            sum += x;
        }

        if (sum < s) {
            cout << -1 << "\n";
            continue;
        }

        vector<long long> left(sum - s + 1);
        vector<long long> right(sum - s + 1);
        for (int i = 1; i <= sum - s; i++) {
            left[i] = v[i - 1] + 1;
            right[i] = n - v[v.size() - i];
        }

        long long res{numeric_limits<long long>::max()};
        for (int i = 0; i <= sum - s; i++) {
            res = min(res, left[i] + right[sum - s - i]);
        }
        
        cout << res << "\n";
    }
}