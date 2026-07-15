//Jzzhu and Sequences

/*
given x and y, calc fn modulo 1000000007 
x, y
n

f1 = 2
f2 = 3

f2 = f1 + f3
f3 = f2 - f1 = 1

f3 = f2 - f1
f4 = f3 - f2 = f2 - f1 - f2 = -f1

f5 = f4 - f3 = -f1 - f2 + f1 = -f2

f6 = f5 - f4 = 
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    long long x;
    long long y;

    cin >> x >> y >> n;

    const long long MOD = 1000000007;
    long long res;

    switch (n % 6) {
        case 1:
            res = x;
            break;
        case 2:
            res = y;
            break;
        case 3:
            res = y - x;
            break;
        case 4:
            res = -x;
            break;
        case 5:
            res = -y;
            break;
        case 0:
            res = x - y;
            break;
    }

    res = (res % MOD + MOD) % MOD;
    cout << res;
}