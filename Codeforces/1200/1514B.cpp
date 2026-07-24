// AND 0, sum big

/*
given two integers n and k

count number of arrays of length n such that

all elements are integers between 0 and
2^k - 1 (inclusive)

bitwise AND of all elements is 0

sum is as large as possible

print remainder divided by 10^9 + 7

t cases
n , k

AND of all elements is 0 means all distinct
from 0 to 2k- 1

count number of combinations of distinct values of 0 to 2k-1


*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    const long long MOD = 1'000'000'007LL;
    while (t--) {
        int n; 
        int k;
        cin >> n >> k;
        long long res{1};
        for (int i = 0; i < k; i++) {
            res = (res * (n % MOD)) % MOD; 
        }
        cout << res << "\n";
    }
}