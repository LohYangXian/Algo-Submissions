//Divide and Equalise

/*
array a consisting of n positive integers

perform the following operations on it

choose a pair of elements ai and aj

choose one of divisors of integer ai
such that ai % x = 0

replace ai with ai/x and aj with aj * x

Determine if its possible to make all elements in the
array the same by applying the operation a certain number
of times

t cases
n 
n integers

find a O(n) soln
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<long long> v{};
        cin >> n;

        unordered_map<long long, int> cnt;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int p = 2; 1LL * p * p <= x; p++) {
                while (x % p == 0) {
                    cnt[p]++;
                    x /= p;
                }
            }

            if (x > 1) {
                cnt[x]++;
            }
        }

        bool possible = true;
        for (const auto &[prime, count] : cnt) {
            if (count % n != 0) {
                possible = false;
                break;
            }
        }
        
        cout << (possible ? "YES\n" : "NO\n");
    }
}