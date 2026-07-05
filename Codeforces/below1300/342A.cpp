// Xenia and Divisors

/*
n is divisible by 3 positive integers, each of them is at most 7

split the sequence into groups of three so that 

a < b < c

a divides b, b divides c

`
1 -
2 1
3 1
4 2 1
5 1
6 3 2 1
7 1
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int,int> m{};
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 5 || x == 7) {
            cout << -1;
            return 0;
        }
        m[x]++;
    }

    if (m[1] != n / 3 || m[3] > m[6]) {
        cout << -1;
        return 0;
    } 

    m[6] -= m[3];

    if (m[2] != m[4] + m[6]) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < m[3]; i++)
    cout << "1 3 6\n";

    for (int i = 0; i < m[4]; i++)
        cout << "1 2 4\n";

    for (int i = 0; i < m[6]; i++)
        cout << "1 2 6\n";
}
