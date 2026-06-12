// Panoramix's Prediction

#include <iostream>
using namespace std;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x;
    int y;
    cin >> x;
    cin >> y;
    int nextPrime{};
    for (int i = x + 1; i < y + 1; i++) {
        if (isPrime(i) == true) {
            nextPrime = i;
            break;
        }
    }

    if (nextPrime == y) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}