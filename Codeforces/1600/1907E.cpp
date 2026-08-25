//Good Triples

/*
n >= 0
(a,b,c) is good if a + b + c = n
and digsum (a)  + digsum(b) + digsum(c) = digsum(n) where
digsum(x) is the sum of digits of number x

find number of good triples for the given number n
order matters

t cases
n integer

might need a less than O(n) soln
*/
#include <string>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;

        long long ans = 1;

        for (int i = 0; i < n.size(); i++) {
            long long digit = n[i] - '0';
            long long count = 0;
            for (long long j = 0; j <= digit; j++) {
                for (long long k = 0; k <= digit; k++) {
                    for (long long l = 0; l <= digit; l++) {
                        if (j + k + l == digit) {
                            count++;
                        }
                    }
                }
            }
            ans *= count;
        }
        cout << ans << "\n";
    }
}