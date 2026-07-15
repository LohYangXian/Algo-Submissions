//Adding digits

/*
a and b
a too short
repeat lengthening number a n times

one operation: adding exactly one digit to the number to the right,
provided the resulting number is divisible by b

print number we can get by applying ops a n times

create multiples of b up till max value with (a + n) digits
then we check in reverse if there exists a number  with (a + n) digits
and first part of digits = to the a
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    for (int d = 0; d <= 9; d++) {
        if ((a * 10 + d) % b == 0) {
            cout << a << d;
            for (int i = 1; i < n; i++) {
                cout << 0;
            }
            return 0;
        }
    }

    cout << -1;
}