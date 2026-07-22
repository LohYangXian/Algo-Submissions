//Differential Sorting

/*
n elements

x,y,z

replace ax with ay - az

after ops , |ax| need to be less than 10**18

make the result non-decreasing

O(n) soln or O(n log n)
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
        long long x{};

        bool sorted = true;

        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
            if (i > 0 && v[i] < v[i - 1]) sorted = false;
        }

        if (sorted == true) {
            cout << 0 << "\n";
            continue;
        }

        if (v[n - 2] > v[n - 1] || v[n - 1] < 0) {
            cout << -1 << "\n";
            continue;
        }   

        cout << n - 2 << "\n";

        for (int i = 0; i < n - 2; i++) {
            cout << i + 1 << " " << n - 1 << " " << n << "\n";
        }
    }
}