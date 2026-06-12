// Arrival of the general

#include <iostream>
#include <limits>
using namespace std;

int main() {
    int min_idx{};
    int min{numeric_limits<int>::max()};
    int max_idx{};
    int max{numeric_limits<int>::min()};
    int n{};

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= min) {
            min_idx = i;
            min = x;
        }
        if (x > max) {
            max_idx = i;
            max = x;
        }
    }

    if (min_idx < max_idx) {
        cout << (n - 1 - min_idx + max_idx - 1);
    } else {
        cout << (n - 1 - min_idx + max_idx);
    }
}
