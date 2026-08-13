//Add modulo 10

/*
array of n integers a1, a2, ... an

apply following ops

select an index i (1 <= i <= n) , 

replace the value of element ai with value

ai + (ai % 10) 

for a single index, can be applied multiple times

check if u can make all array elements equal

YES or NO

t cases
n integers

n values 

try a O(n) soln
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v{};

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        int num5s = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] % 5 == 0) num5s++;
        }

        if (num5s != 0 && num5s != n) {
            cout << "NO" << "\n";
            continue;
        }
        bool solved = false;

        if (num5s == 0) {
            for (int i = 0; i < n; i++) {
                while (v[i] % 10 != 2) {
                    v[i] += (v[i] % 10);
                }
            }

            for (int i = 1; i < n; i++) {
                if ((v[i] - v[i - 1]) % 20 != 0) {
                    solved = true;
                    cout << "NO" << "\n";
                    break;
                }
            }

        } else {
            for (int i = 0; i < n; i++) {
                if (v[i] % 10 != 0) v[i] += 5;
            }

            for (int i = 1; i < n; i++) {
                if (v[i] != v[i - 1]) {
                    solved = true;
                    cout << "NO" << "\n";
                    break;
                }
            }
        }
        
        if (solved == false) {
            cout << "YES" << "\n";
        }
    }
}