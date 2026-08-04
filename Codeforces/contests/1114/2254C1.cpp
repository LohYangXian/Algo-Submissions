//Marenol

/*
whether a can be transformed into b

binary strings a and b of length n

choose a substring* in  a equal to 001 and replace with 100 or vice versa

choose a substring equal to 110 and replace it with 011 or vice versa
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        string b;
        cin >> a >> b;
        if (n < 3) {
            if (a == b) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
            continue;
        }

        int oddA = 0;
        int evenA = 0;
        int oddB = 0;
        int evenB = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == '1') {
                if (i % 2 == 0) {
                    evenA++;
                } else {
                    oddA++;
                }
            }
            if (b[i - 1] == '1') {
                if (i % 2 == 0) {
                    evenB++;
                } else {
                    oddB++;
                }
            }
        }
        if (oddA == oddB && evenA == evenB) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}