#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string word;
    unordered_map<char, int> freqCount{};

    cin >> n >> word;
    for (const char c: word) {
        freqCount[c]++;
    }

    string res{};

    for (const auto [key, value]: freqCount) {
        if (value % n != 0) {
            cout << -1;
            return 0;
        }
        res += string(value / n, key);
    }
    string ans{};
    for (int i = 0; i < n; i++) {
        ans += res;
    }
    cout << ans;
}