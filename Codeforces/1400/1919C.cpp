// Grouping Increases

/*
array of size n

do the following process to calc penalty 

1. split array a into 2 possibly empty subsequences s and t such 
that every element of a is in either s or t

for an array b of size m, define the penalty p(b) of an array b
as the number of indices i between 1 and m - 1 where b1 < b1 + 1

the total penalty receive is p(s) + p(t)
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
        vector<int> a{};
        vector<int> b{};
        int res = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (a.size() == 0) {
                a.push_back(x);
                continue;
            } 

            if (b.empty()) {
                if (x <= a.back()) {
                    a.push_back(x);
                } else {
                    b.push_back(x);
                }
                continue;
            }

            if (x <= a.back() && x > b.back()) {
                a.push_back(x);
            } else if (x <= b.back() && x > a.back()) {
                b.push_back(x);
            } else {
                if (x <= a.back() && x <= b.back()) {
                    if (a.back() >= b.back()) {
                        b.push_back(x);
                    } else {
                        a.push_back(x);
                    }
                } else {
                    if (a.back() <= b.back()) {
                        a.push_back(x);
                    } else {
                        b.push_back(x);
                    }
                }
            }
        }

        for (int i = 0; i + 1 < a.size(); i++) {
            if (a[i] < a[i + 1]) res++;
        }

        for (int i = 0; i + 1 < b.size(); i++) {
            if (b[i] < b[i + 1]) res++;
        }

        cout << res << "\n";
    }
}