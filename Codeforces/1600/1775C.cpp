//Interesting Sequence

/*
n and x

n & (n + 1) ... m  = x

min m (m>=n) such that the equality on board holds

can u solve for m?

t cases, 
n , x <= 10^18

if not possible , -1
m <= 5^10^18, HMMM interesting constraint,
maybe its a binary search to get the nuymber?
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n; long long x;
        cin >> n >> x;
        if ((n & x) != x) {
            cout << -1 << '\n';
            continue;
        }

        if (n == x) {
            cout << n << '\n';
            continue;
        }

        long long m = n;

        for (int b= 0; b < 60; b++) {
            bool nBit = (n >> b) & 1;
            bool xBit = (x >> b) & 1;

            if (nBit && !xBit) {
                long long block = 1LL << (b + 1);
                long long death = (n / block + 1) * block;
                
                m = max(m, death);
            }
        }

        bool valid = true;

        for (int b = 0; b < 60; b++) {
            if ((x >> b) & 1) {
                long long block = 1LL << (b + 1);
                long long death = (n / block + 1) * block;

                if (m >= death) {
                    valid = false;
                    break;
                }
            }
        }
        cout << (valid ? m : -1) << "\n";
    }
}