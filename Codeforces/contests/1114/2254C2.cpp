//Marenol (hard)

/*
easy + 
determine min number of operations to transform a into b
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        string b;
        cin >> a >> b;
        if (n < 3) {
            if (a == b) {
                cout << 0 << "\n";
            } else {
                cout << -1 << "\n";
            }
            continue;
        }

        vector<int> oddA{};
        vector<int> evenA{};
        vector<int> oddB{};
        vector<int> evenB{};

        long long res = 0;

        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == '1') {
                if (i % 2 == 0) {
                    evenA.push_back(i);
                } else {
                    oddA.push_back(i);
                }
            }
            if (b[i - 1] == '1') {
                if (i % 2 == 0) {
                    evenB.push_back(i);
                } else {
                    oddB.push_back(i);
                }
            }
        }
        if (oddA.size() != oddB.size() || evenA.size() != evenB.size()) {
            cout << -1 << "\n";
            continue;
        } 

        for (int i = 0; i < oddA.size(); i++) {
            res += abs(oddA[i] - oddB[i]) / 2;
        }

        for (int i = 0; i < evenA.size(); i++) {
            res += abs(evenA[i] - evenB[i]) / 2;
        }

        cout << res << "\n";
    }
}