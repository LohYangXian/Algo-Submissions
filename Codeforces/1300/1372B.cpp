//Omkar and Last Class of Math

/*
LCM is smallest positive integer x which is divisible by 
both a and b

given n, find positive integers a and b such that a + b = n
and LCM(a,b) is min val
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> divisors{};
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (n / i != i && n / i != n) {
                    divisors.push_back(n / i);
                }       
            }
        }

        sort(divisors.begin(), divisors.end(), greater<int>());

        cout << divisors[0] << " " << n - divisors[0] << "\n";
    }
}
// if even, return n / 2
// if odd, return 