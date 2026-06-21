// Dima and friends


// total number of fingers % number of friends
// n = number of other friends (not incl dima) 
// n = number of fingers
// show numbers that wont lead to him being selected

#include <iostream>
using namespace std;

int main() {
    int n;
    int m{};
    int res{};

    cin >> n;
    int x;
    while (cin >> x) {
        m += x;
    }

    n += 1;
    for (int i = 1; i <= 5; i++) { 
        if ((m + i) % n != 1) res++; 
    }

    cout << res;
}