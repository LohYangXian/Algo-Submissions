// Removing Smallest Multiples

/*
Set S, contains first n positive integers 1,2,... n

perform following ops on S any number of times >= 0

Choose a positive int k 1<=k<=n, such that there exists a multiple of
k in S
delete the smallest multiple of k from S. Costs K

Find min cost to transform S to T
Transformation is always possible

t: number  of tests

n
binary string describing T
*/

#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string x;
        cin >> x;
        unordered_set<long long> s{};

        for (long long i = 1; i <= n; i++) {
            if (x[i - 1] == '0') {
                s.insert(i);
            }
        }

        long long res{};

        for (long long key = 1; key <= n; key++) {
            if (s.find(key) == s.end() && x[key - 1] == '1')
                continue;

            for (long long i = key; i <= n; i += key) {
                if (x[i - 1] == '1') {
                    break;
                }

                if (s.find(i) != s.end()) {
                    res += key;
                    s.erase(i);
                }
            }

            if (s.empty()) break;
        }

        cout << res << "\n";
    }
}