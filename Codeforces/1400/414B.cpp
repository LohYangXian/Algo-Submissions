//Mashmokh and ACM

/*

a sequence of l integers b1 , b2, bl.. is called good if each number 
divides (without a remainder) by the next number in the sequence

bi | bi+1 for all i 

given n and k, find number of good sequences of length k

print % 10^9 + 7

n, k

1 <= b1 <= b2 .... n

2000 only , so n^2 soln shld be okay
lets do backtracking
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long ans = 0;
long long k;
long long n;
long long MOD = 1000000007LL;

int main() {
    cin >> n >> k;
    vector<long long> curV(n, 1);
    vector<long long> prevV(n, 1);
    vector<vector<long long>> multiples{};
    for (int i = 1; i <= n; i++) {
        multiples.push_back({});
        for (int j = 2 * i; j <= n; j+=i) {
            multiples[i - 1].push_back(j);
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x: multiples[j - 1]) {
                curV[x - 1] += (prevV[j - 1] % MOD);
            }
        }
        prevV = curV;
    }

    for (int i = 0; i < n; i++) {
        ans += curV[i] % MOD;
    }
    cout << ans % MOD;
} 