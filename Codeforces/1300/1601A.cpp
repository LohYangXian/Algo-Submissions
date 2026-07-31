// Array Elimination

/*
array a1,a2,a3.. an, consiting of non negative integers

operation with integer k, 1 <= k <= n

choose k distinct array indices 1 <= i1 < i2 < .. < ik <= n

calc x = ai & a2 & ... aik, & is BITWISE AND 

subtract x from each

find all possible values of k , such that its possible to make 
all elemnts equal to 0 

t cases
n length
n integers


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(31, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while (x) {
                int bit = __builtin_ctz(x);
                v[bit]++;

                x &= (x - 1);
            }
        }

        int d = 0;
        for (int i = 0; i < 31; i++) {
            d = gcd(d, v[i]); 
        }

        if (d == 0) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << "\n";
            continue;
        }

        vector<int> res{};

        for (int i = 1; i * i <= d; i++) {
            if (d % i == 0) {
                res.push_back(i);

                if (i != d /  i) {
                    res.push_back(d / i);
                }
            }
        }

        sort(res.begin(), res.end());

        for (int i: res) {
            cout << i << " ";
        }

        cout << "\n";
     }
}