//Chat Ban

/*
spam the emote triangle of size k

consists of 2k-1 messages

1
2
..
k
k-1
1

bans after you spam x emotes in succession

how many messages will you write before getting banned

t cases
k, x

we need a o(1) solution
*/

#include <iostream>
using namespace std;

using ll = long long;

ll prefix(ll m, ll k) {
    if (m <= k) {
        return m * (m + 1) / 2;
    }

    ll inc = k * (k + 1) / 2;
    ll d = m - k;

    ll dec = d * (2 * (k - 1) - d + 1) / 2;

    return inc + dec;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll k, x;
        cin >> k >> x;

        ll total = k * k;

        if (x >= total) {
            cout << 2 * k - 1 << "\n";
            continue;
        }

        ll l = 1;
        ll r = 2 * k - 1;

        while (l < r) {
            ll mid = (l + r) / 2;

            if (prefix(mid, k) >= x)
                r = mid;
            else
                l = mid + 1;
        }

        cout << l << "\n";
    }
}