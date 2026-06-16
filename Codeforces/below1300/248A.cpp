// Cupboards
#include <iostream>
using namespace std;

int main() {
    int l{};
    int r{};

    int a;
    int b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 1) l++;
        if (b == 1) r++;
    }

    cout << (min(n - l, l) + min(n - r, r));
}