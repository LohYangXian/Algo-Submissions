//Flip the Bits

/*
binary string a of length n

you can select any prefix of a 
with an equal number of 0 and 1 symbols

then all symbols r inverted

transform a into b

t cases
n length of a and b
a
b

YES 
| NO

O(n) soln
*/

#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a;
        string b;
        cin >> n >> a >> b;

        unordered_map<char, int> m{};
        bool isFlipped = false;
        int pointer = n - 1;
        bool isSolved = false;

        for (int i = 0; i < n; i++) {
            m[a[i]]++;
        }

        while (pointer >= 0) {
            while (pointer >= 0) {
                if (isFlipped == false) {
                    if (a[pointer] == b[pointer]) {
                        m[a[pointer]]--;
                        pointer--;
                    } else {
                        break;
                    }
                } else {
                    if (a[pointer] != b[pointer]) {
                        m[b[pointer]]--;
                        pointer--;
                    } else {
                        break;
                    }
                }
            }

            if (m['0'] != m['1']) {
                cout << "NO" << "\n";
                isSolved = true;
                break;
            } 
            
            isFlipped = !isFlipped;
        }

        if (isSolved == true) continue;
        cout << "YES" << "\n";
    }
}