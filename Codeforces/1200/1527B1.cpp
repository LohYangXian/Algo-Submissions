//Palindrome game (easy)

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int numZeros{};
        for (char c: s) {
            if (c == '0') numZeros++;
        }

        int ans = numZeros % 4;
        if (numZeros % 2 == 1 && numZeros > 1)
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }
}