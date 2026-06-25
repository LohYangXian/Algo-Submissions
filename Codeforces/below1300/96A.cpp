// Football

#include <iostream>
using namespace std;

int main() {
    string players;
    int count{};
    char cur{'0'};

    cin >> players;
    for (char c: players) {
        if (cur == c) {
            count++;
        } else {
            count = 1;
            cur = c;
        }
        if (count >= 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}