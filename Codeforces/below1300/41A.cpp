//Translation

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    int l = 0;
    int r = a.size() - 1;
    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }

    while (l <= r) {
        if (a[l] != b[r - l]) {
            cout << "NO";
            return 0;
        }
        l++;
    }
    cout << "YES";
}