// Easy Number Challenge

/*
d(n) as the number of divisors of a positive integer n

a,b,c

final answer modulo 1073741824 
*/
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> nToDivisor(1000001);

    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            nToDivisor[j]++;
        }
    }

    int a; 
    int b;
    int c;
    cin >> a >> b >> c;

    int sum{};

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                int n = (i * j * k);
                sum = (sum + nToDivisor[n]) % 1073741824;
            }
        }
    }

    cout << sum;
}