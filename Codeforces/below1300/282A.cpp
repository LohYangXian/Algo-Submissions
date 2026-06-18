// Bit++

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int res{};

    cin >> n;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "++X" || cmd == "X++") {
            res++;
        } else if (cmd == "--X" || cmd == "X--") {
            res--;
        }
    }
    cout << res;
}