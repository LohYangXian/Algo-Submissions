//Shuffle

/*
n integers
a1, a2, a3,... an

ax = 1, all other elements = 0

m operations

during ith operation, choose two indices c and d
li <= c,d <= ri  , swap ac and ad

calc number of indices k such that its possible
to choose ops so ak = 1

t cases
n , x , m
each m line , ith line l1, r1
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int x;
        int m;
        cin >> n >> x >> m;

        int low;
        int high;
        low = x;
        high = x;

        for (int i = 0; i < m; i++) {
            int l;
            int r;
            cin >> l >> r;
            if (r >= low && l <= high) {
                low = min(l, low);
                high = max(r, high);
            }
        }

        cout << high - low + 1 << "\n";
    }
}