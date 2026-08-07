//the best card

/*
n cards, 2.. n+1

if x n y is divisble by other, smaller value wins
other wise bigger wins

find crd that wins all

23456
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        bool solved = false;
        for (long long i = 2; i * i <= n + 1; i++) {
            if ((n + 1) % i == 0) {
                cout << "NO" << "\n";
                solved = true;
                break;
            }
        }

        if (solved == false) cout << "YES" << "\n";
    }
}