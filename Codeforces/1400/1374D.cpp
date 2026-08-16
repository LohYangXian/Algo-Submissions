//Zero Remainder Array

/*
array a consisting of n positive integers

initially x = 0
u can do one of 2 operations

1. choose exactly one i from 1 to n and increase ai by x 
then increase x by 1

2. increase x by 1

first op can be applied no more than once to each i from 1 to n 
(TAKE NOTE OF THIS)

find min number of moves to obtain an array that each elem
is divisible by k

t cases
n length ; k
n integers

try an o(n) soln, take note that first op can only be applied once

*/
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n; long long k;
        cin >> n >> k;

        unordered_map<long long, long long> count{};
        vector<long long> v{};
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            v[i] = v[i] % k;
            v[i] = k - v[i];
            count[v[i]]++;
        }

        long long res = 0;
        for (auto& [key, value]: count) {
            if (key == k) continue;
            res = max(res, key + (value - 1) * k);
        }
        if (res == 0) {
            cout << 0 << "\n";
        } else {
            cout << res + 1 << "\n";
        }
    }
}