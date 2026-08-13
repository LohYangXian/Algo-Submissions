//Make it round

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n; long long m;
        cin >> n >> m;

        int num5 = 0;
        int num2 = 0;
        long long temp = n;

        while (temp % 2 == 0) {
            num2++;
            temp /= 2;
        }

        while (temp % 5 == 0) {
            num5++;
            temp /= 5;
        }

        long long k = 1;
        int diff = abs(num5 - num2);

        if (num5 > num2) {
            while (diff > 0 && k * 2 <= m) {
                k *= 2;
                diff--;
            }
        } else if (num2 > num5) {
            while (diff > 0 && k * 5 <= m) {
                k *= 5;
                diff--;
            }
        }
        
        while (k * 10 <= m) {
            k *= 10;
        }

        cout << n * (m / k) * k << "\n";
        
    }
}