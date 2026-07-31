//Box Fitting

/*
n rectangles , each of height 1

each rec width is a power of 2 

2d box of width W, W is at least as large as the width of the largest rectangle

fuind smallest height of this box such that it is able to fit all given rectangles

no overlaps, no rotations

t case
n and W
n integers

sum of n < 10^5, 

we can find a O(n) soln
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, W;
        cin >> n >> W;

        vector<int> cnt(21, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[__builtin_ctz(x)]++;
        }

        int ans = 0;
        int left = n;

        while (left > 0) {
            ans++;
            int rem = W;

            for (int b = 20; b >= 0; b--) {
                while (cnt[b] && (1 << b) <= rem) {
                    rem -= (1 << b);
                    cnt[b]--;
                    left--;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}