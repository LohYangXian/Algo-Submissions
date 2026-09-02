//Hits different

/*
2023 rows

if can 9^2 is hit, all cans colored red above would fall
what is the sum of numbers on all cans that fail?

t cases, n integer that got hit

use long long

you cant use a O(n) solution, a O(log n) solution is better
*/

#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        queue<long long> level;
        long long row;
        for (int i = 1; i <= 2023; i++) {
            if ((i * (i - 1) / 2) + 1 <= n && n <= (i * (i + 1) / 2)) {
                row = i;
                break;
            }
        }
        long long left = n;
        long long right = n;
        long long sum = 0;
        
        while (row > 0) {
            for (long long i = left; i <= right; i++) {
                sum += (i * i);
            }
            row--;
            long long l = (row * (row - 1) / 2) + 1;
            long long r = (row * (row + 1) / 2);
            left = max(left - row - 1, l);
            right = min(right - row, r);
        }
        cout << sum << "\n";
    }
}