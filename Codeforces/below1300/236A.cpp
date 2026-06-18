//boy or girl
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<char> s;
    string user;
    cin >> user;

    for (const char c: user) {
        s.insert(c);
    }
    if (s.size() % 2 == 0) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }
}