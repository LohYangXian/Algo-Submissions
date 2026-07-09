// Yaroslav and Permutations

/*
n integers 

swap two neighboring array elements

obtain an array where any two neighboring elements wld be distinct in a finite time
*/

#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    unordered_map<int,int>m{};
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }

    for (auto [key, value]: m) {
        if (n % 2 == 0) {
            if (value > n / 2) {
                cout << "NO";
                return 0;
            }
        } else {
            if (value > (n / 2) + 1) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}