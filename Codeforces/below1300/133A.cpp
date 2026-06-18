//HQ9+

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<char> s;
    s.insert('H');
    s.insert('Q');
    s.insert('9');

    string cmd;
    cin >> cmd;
    for (const char c: cmd) {
        if (s.find(c) != s.end()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}