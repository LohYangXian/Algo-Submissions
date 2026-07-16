//Make Almost Equal with Mod

/*
choose a positive integer k
for each i from 1 to n, replace ai with ai mod k

find a value of k 1 <= k <= 10^18
a contains exactly 2 distinc values at the end of the operation,



*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        long long x;
        vector<long long> v{};
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        bool hasEven{};
        bool hasOdd{};
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                hasEven = true;
            } else {
                hasOdd = true;
            }
        }
        if (hasEven == true && hasOdd == true) {
            cout << 2 << "\n";
            continue;
        }


        for (long long k = 2; k <= 1e18; k *= 2) {
            long long firstRemainder = v[0] % k;
            bool allSame = true;

            for (int j = 1; j < n; j++) {
                if (v[j] % k != firstRemainder) {
                    allSame = false;
                    break;
                }
            }

            if (!allSame) {
                cout << k << "\n";
                break;
            }
        }
    }
}