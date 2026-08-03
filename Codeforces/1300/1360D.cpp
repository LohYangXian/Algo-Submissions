//Buying Shovels

/*
n shovels

store has k packages

package of ith type conssits of exactly i shovels
(1 <= i <= k)


infinite number of packages of each type

wants to choose one type and buy several packages
of this type

what is smallest number of packages to buy to get exacttly
n shovels

t cases
n , k
number of shovels and number of types of packages
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;

        vector<int> factors{};
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (n / (n / i) != n / i) {
                    factors.push_back(n / i);
                }
            }
        }

        sort(factors.begin(), factors.end());
        auto it = upper_bound(factors.begin(), factors.end(), k);

        if (it == factors.begin()) {
            cout << -1 << "\n";
        } else {
            it--;
            cout << n / *it << "\n";
        }
    }
}