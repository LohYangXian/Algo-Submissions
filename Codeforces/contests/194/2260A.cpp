//Monocarps Contest

/*
n problems , each either easy or hard
numbered 1 to n

wants the first and last problem to be easy

can choose any 2 problems and swap them

report min number of swaps
or report if impossible

t cases
n (2 to 50 number of problems)
n integers, 0 is easy , 1 is hard

it will always be either 0, -1, 1 or 2 swaps

*/
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int first;
        int last;
        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i == 0) {
                first = x;
            } else if (i == n - 1) {
                last = x;
            } else {
                if (x == 0) {
                    zeros++;
                } else {
                    ones++;
                }
            }
        }

        int count = 0;
        if (first == 1) {
            if (zeros > 0) {
                zeros--;
                count++;
            } else {
                cout << -1 << "\n";
                continue;
            }
        } 
        if (last == 1) {
            if (zeros > 0) {
                zeros--;
                count++;
            } else {
                cout << -1 << "\n";
                continue;
            }
        }
        cout << count << "\n";
    }
}