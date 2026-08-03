//Most socially-distanced subsequence

/*
permutation p of length n , find its subsequence s1, s2, .. sk
of length of at least 2 such that

| s1 - s2 | + |s2 - s3| + ... is as big as possible

take note that permutation means that element appears exactly ONCE

sum of n < 10^^5

t cases 
n length of permutation

n integers

maximise gaps, minimize length
*/

#include <vector>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 2;
        bool isIncreasing = false;
        int x1;
        int x2;
        vector<int> v{};
        cin >> x1 >> x2;
        if (x2 > x1) {
            isIncreasing = true;
        }
        
        v.push_back(x1);
        // cout << x1 << " ";

        for (int i = 0; i < n - 2; i++) {
            int x; 
            cin >> x;
            if (x > x2 && isIncreasing == false) {
                res++;
                isIncreasing = true;
                // cout << x2 << " ";
                v.push_back(x2);
            } else if (x < x2 && isIncreasing == true) {
                res++;
                isIncreasing = false;
                // cout << x2 << " ";
                v.push_back(x2);
            } 
            x2 = x;
        }

        v.push_back(x2);
        // cout << x2 << "\n";
        cout << res << "\n";

        for (int i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}