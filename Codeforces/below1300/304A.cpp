// Pythagorean Theorem II

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res{};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int square = i * i + j * j;
            if ((sqrt(square) * sqrt(square) == square) && square <= n) {
                res++;
            }
        }
    }
    cout << res;
}