#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int l = 1, r = n;

        while (l < r) {
            int mid = (l + r) / 2;

            cout << "? " << l << " " << mid << endl;

            int cnt = 0;

            for (int i = l; i <= mid; i++) {
                int x;
                cin >> x;

                if (x == -1)
                    return 0;

                if (x >= l && x <= mid)
                    cnt++;
            }

            if (cnt % 2 == 1)
                r = mid;
            else
                l = mid + 1;
        }

        cout << "! " << l << endl;
    }

    return 0;
}