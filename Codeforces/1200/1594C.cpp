//Make them equal

/*
s1 s2 s3 sn... charaacter c

make all characters of the string equal to c using min number of operations

he can choose a number X and for every position i % x != 0, replace s with c

find min number of ops required to make all characters equal to c
and x-s used

t, n, c

4 a
b a a a

O(n) soln


*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        bool allEqual = true;
        for (char ch : s) {
            if (ch != c) {
                allEqual = false;
                break;
            }
        }

        if (allEqual) {
            cout << 0 << '\n';
            continue;
        }

        int x = -1;
        for (int i = n / 2 + 1; i <= n; i++) {
            if (s[i - 1] == c) {
                x = i;
                break;
            }
        }

        if (x != -1) {
            cout << 1 << '\n';
            cout << x << '\n';
        } else {
            cout << 2 << '\n';
            cout << n << " " << n - 1 << '\n';
        }
    }

    return 0;
}