// T-primes

/*
T prime has exactly 3 distinct positive divisors
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<bool> isPrime(1000001, true);

    for (long long i = 2; i < isPrime.size(); i++) {
        for (long long j = i*i; j < isPrime.size(); j+=i) {
            isPrime[j] = false;
        }
    }
    isPrime[0] = false;
    isPrime[1] = false;

    long long x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int root = sqrt(x);
        long long reCon = root * root;
        if (root * root == x && isPrime[root] == true) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
}