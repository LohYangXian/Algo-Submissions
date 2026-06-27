// Chatroom

#include <string>
#include <iostream>
using namespace std;

int main() {
    string h{"hello"};
    int r = 0;

    string s;
    cin >> s;
    for (char c: s) {
        if (c == h[r]) {
            r++;
        } 
        if (r == h.size()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}