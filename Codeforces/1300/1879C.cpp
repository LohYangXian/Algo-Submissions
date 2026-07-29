// Make it alternating

/*
Given a binary string s
0 and 1

perform the operation any times

choose integer i such that i <= i <= s
then erase the character si

make it alternating 

min number of ops required to make s alternating
number of diff shortests sequences of ops to make it alternating

t cases
s

can do a O(n) soln

print modulo 998244353
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    long long MOD = 998244353LL;
    while (t--) {
        string s;
        cin >> s;
        long long count = 0;
        long long res = 1;
        long long runLength = 1;

        for (int i = 1; i < static_cast<int>(s.size()); i++) {
            if (s[i] == s[i - 1]) {
                runLength++;
                count++;
            } else {
                res = res * runLength % MOD;
                runLength = 1;
            }
        }

        res = res * runLength % MOD;

        long long ans = 1;
        for (int i = 2; i <= count; i++)
            ans = ans * i % MOD;
        res = res * ans % MOD;
        cout << count << " " << res << "\n";
    }
}