//Magic numbers
#include <iostream>
using namespace std;

int main() {
    string x;
    cin >> x;

    int num4s{};
    
    if (x.size() == 0 || x[0] != '1') {
        cout << "NO";
        return 0;
    }
    
    for (char c: x) {
        if (c == '1') {
            num4s = 0;
        } else if (c == '4') {
            num4s += 1;
            if (num4s > 2) {
                cout << "NO";
                return 0;
            }
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}