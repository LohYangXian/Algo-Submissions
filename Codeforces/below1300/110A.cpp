// Nearly lucky number
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isLucky(long long x) {
    for (char c: to_string(x)) {
        if (c != '4' && c != '7') {
            cout << "NO";
            return false;
        }
    }
    cout << "YES";
    return true;
}

int main() {
    long long x;
    cin >> x;
    long long count{};
    for (char c: to_string(x)) {
        if (c == '4' || c == '7') {
            count++;
        }
    }
    isLucky(count);
    return 0;
}