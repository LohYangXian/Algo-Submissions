//Product of Three Numbers

/*
given n

find three distinct integers a, b, c, such that 2 <= a, b, c
and a.b.c = n 
or say its impossible

t cases
n lines

get array of prime factors in root n time
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a = -1;
        int b = -1;
        int c = -1;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a = i;
                n = n / i;
                break;
            }
        }

        if (a != -1) {
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0 && i != a) {
                    b = i;
                    n = n / i;
                    break;
                }
            }
        }

        if (b != -1) {
            c = n;
        }

        if (a != -1 && b != -1 && c > 1 && a != b && b != c && a != c) {
            cout << "YES" << "\n";
            cout << a << " " << b << " " << c << "\n";
        } else {
            cout << "NO\n";
        }
    }
}