//Strange Birthday Party

/*
n friends, assign k to ith of them

give a present to each of them

m unique presents, jth present costs c dollars
not allowed to buy a single present more than once

u can give them a present j <= k, cost c dollars, or
give c dollars directly

determine the min total cost of party

O(n) soln sum of values n < 10^5
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
        int m;
        vector<long long> friends{};
        vector<long long> v{};
        vector<long long> finalList{};
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            friends.push_back(x);
        }

        for (int i = 0; i < m; i++) {
            long long c;
            cin >> c;
            v.push_back(c);
            finalList.push_back(c);
        }

        for (int i = 0; i < n; i++) {
            finalList.push_back(v[friends[i] - 1]);
        }

        sort(finalList.begin(), finalList.end());

        long long res{};
        for (int i = 0; i < n; i++) {
            res += finalList[i];
        }

        cout << res << "\n";
    }
}