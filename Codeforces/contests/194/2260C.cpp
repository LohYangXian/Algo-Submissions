//Maximize XOR, Minimize Operations

/*
two non-negative integers x and y
you can decrease x by 1 
and increase y by 1 at the same time

op cannot be performed if x = 0

for each pair, perform some number of ops, 
possbily zero, so that value of X XOR y , becomes
as large as possible

choose the one with min number of operations

output the max value of x xor y and min number of ops

t cases
x and y , 2^ 29 
so we can do O(n) or O(n log n) for the soln? 
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        long long y;
        cin >> x >> y;

        long long S = x + y;
        long long a= 0;
        for (int bit = 30; bit >= 0; bit--) {
            if ((S >> bit) & 1LL) {
                long long candidate = a | (1LL << bit);

                if (candidate <= x) {
                    a = candidate;
                }
            }
        }
        cout << S << " " << x - a << "\n";
    }
}