//Candy Box

/*
n candies in a candy box

1 <= a <= n

number of candies of each type shld be all distinct

possible that multiple types r absent from gift

not all candies of some types taken to a gift

find maximum possible size of gift u can prepare

answer q queries

q number of queries
first line n number of candies
n integers

try O(n) soln
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<long long> candyCount(n + 1, 0);

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            candyCount[x]++;
        }

        vector<long long> v{};
        for (int i = 0; i < n + 1; i++) {
            if (candyCount[i] > 0) {
                v.push_back(candyCount[i]);
            }
        }

        sort(v.rbegin(), v.rend());
        long long res = 0;
        long long cur = v[0];
        for (int i = 0; i < v.size(); i++) {
            if (cur > v[i]) cur = v[i];
            res += cur;
            cur--;
            if (cur < 0) break;
        }

        cout << res << "\n";
    }
}