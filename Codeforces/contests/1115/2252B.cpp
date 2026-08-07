//Always changing

/*
s of length n
alteranting if no 2 adj characters r same

binary string

choose any char and delete

the chars u delete must strictly alt (as in delete 0, then 1)

find the min number ops required to make s alternating
if impossible, output -1

t cases
n length
s string

try O(n) soln 
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        long long delOne = 0;
        long long delZ = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                if (s[i] == '0') {
                    delZ++;
                } else {
                    delOne++;
                }
            }
        }

        if (abs(delZ - delOne) <= 1) {
            cout << (delZ + delOne) << "\n";
            continue;
        }

        bool extraZ = false;
        if (delZ > delOne) {
            extraZ = true;
        }

        long long toDelete = abs(delOne - delZ) - 1;
        long long avail = 0;
        if (extraZ == true) {
            if (s[0] == '1') avail++;
            if (s[n - 1] == '1') avail++;
        } else {
            if (s[0] == '0') avail++;
            if (s[n - 1] == '0') avail++;
        }

        if (avail >= toDelete) {
            cout << (delZ + delOne + toDelete) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}