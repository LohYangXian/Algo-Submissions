// Dora and Search

/*
find a subsegment of a permutation such that none of the elements at its ends is either the min or max
of the entire subsegment

t cases
n values

1 3 2 4 6 5 7

3 2 4 6 5 
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> v{};
        cin >> n;
        int x;

        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }

        int max = n;
        int min = 1;

        int l{};
        int r{n - 1};

        while (l < r) {
            if (v[l] == min) {
                l++;
                min++;
            } else if (v[l] == max) {
                l++;
                max--;
            } else if (v[r] == min) {
                r--;
                min++;
            } else if (v[l] == max) {
                l++;
                max--;
            } else {
                break;
            }
        }

        if (l == r) {
            cout << -1 << "\n";
        } else {
            cout << l << " " << r << "\n";
        }

    }
}