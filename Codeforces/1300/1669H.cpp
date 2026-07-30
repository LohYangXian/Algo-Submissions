// Maximal AND

/*
AND and OR

& and | 

given an array of length n and a non-negative integer k

perform at most j operations

1. Select an index i and replace ai with ai OR 2^j 
j is any integer between 0 and 30 inclusive

aka select ith number and set the jth bit of that number to 1

output the max value of a1 and a2 and ..... an after performing
at most k operations

t cases
n , k
n integers
*/

#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        int x;
        unordered_map<int, int> freq{};
        for (int i = 0; i < n; i++) {
            cin >> x;
            while (x) {
                int bit = __builtin_ctz(x);
                x &= (x - 1);
                freq[bit]++;
            }
        }

        long long res{};
        int j = 30;

        while (j >= 0) {
            if (freq[j] == n) {
                res += pow(2, j);
            } else if (k - (n - freq[j]) >= 0) {
                res += pow(2, j);
                k -= (n - freq[j]);
            } 
            j--;
        }

        cout << res << "\n";
    }
}
