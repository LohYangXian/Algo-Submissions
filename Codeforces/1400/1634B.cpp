//Fortune Telling

/*
array a of n non-negative integers
indexed from 1 to n

starts w some non-negative number d,
performs one of the two ops for each i = 1,2,..., n 
in increasing order of i

d is current number 
replace d with d + ai
replace d with d bitwise XOR ai

given alice and bob started with x
find out who could get the number y after performing the operations
exactly one of them cld get the number

t cases

n, x, y

o(n) soln
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; long long x; long long y;
        cin >> n >> x >> y;
        long long num1s = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (x % 2 == 1) {
                num1s++;
            } 
        }

        string even;
        string odd;
        if (x % 2 == 0) {
            even = "Alice";
            odd = "Bob";
        } else {
            even = "Bob";
            odd = "Alice";
        }

        if (y % 2 == 0) {
            if (num1s % 2 == 0) {
                cout << even << "\n";
            } else {
                cout << odd << "\n";
            }
        } else {
            if (num1s % 2 == 0) {
                cout << odd << "\n";
            } else {
                cout << even << "\n";
            }
        }
    }
}