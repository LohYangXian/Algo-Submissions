//Johnny and another rating drop

/*
diff between 2 numbers as the number of bit positions

5 vs 14

0101
1110
treat it as 5 XOR 14, then count number of 1 bits
1011
3

sum of such differences counted for neighbouring participants

sequence of CONSECUTIVE integers from 0 to n

find the unfairness of competition

t cases
n (10^18), so O(n) will not work, maybe theres some 
O(log n) or O(1) shortcut soln


*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long total = 0;
        long long power = 0;
        while ((1LL << power) <= n) {
            total += (power + 1);
            long long blockSize = (1LL << power) - (1LL << power - 1) - 1;

            long long cur = 1;
            long long remaining = blockSize;
            while (remaining > 0) {
                long long used = ((remaining + 1) / 2);
                total += (used * cur);
                remaining -= used;
                cur++;
            }
            power++;
        }

        long long remainingBlockSize = n - (1LL << power - 1);
        long long cur = 1;
        while (remainingBlockSize > 0) {
            long long used = ((remainingBlockSize + 1) / 2);
            total += (used * cur);
            remainingBlockSize -= used;
            cur++;
        }
        cout << total << "\n";
    }
}