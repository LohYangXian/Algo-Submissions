//AND Sequences

/*
sequence of n non-negative integers (n >= 2) is called good if forr
all i from 1 to n-1 the following condition true

a1 & a2 & ... ai = ai+1 & a+2 & ... an

given an array of size n (n >= 2, NOTE THIS)
find number of permutations p of numbers ranging from 
1 to n for sequence ap1, ap2.. is good

modulo 10^9 + 7

t cases
n size array
n i8ntegers

find a O(n) soln
*/
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    const long long MOD = 1000000007LL;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for (long long i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        unordered_map<long long, long long> map{};

        long long nSUM = -1;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (nSUM == -1) nSUM = x;
            nSUM &= x;
            map[x]++;
        }

        long long res = 0;
        for (auto& [key, value]: map) {
            if (value >= 2 && key == nSUM) {
                res = value * (value - 1) % MOD;
                res = res * fact[n - 2] % MOD;
            }
        }
        cout << res << "\n";
    }
}