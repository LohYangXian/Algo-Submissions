#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool isDistinct(int year) {
    unordered_set<int> s;
    for (char c: to_string(year)) {
        if (s.count(c)) {
            return false;
        }
        s.insert(c);
    }
    return true;
}

int main() {
    int y;
    cin >> y;
    int ans = y + 1;
    while (isDistinct(ans) == 0) {
        ans++;
    }
    cout << ans;
}