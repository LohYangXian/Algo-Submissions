// Letter

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    string output;
    unordered_map<char,int> freq{};
    unordered_map<char,int> outputfreq{};
    getline(cin, str);
    getline(cin, output);

    for (const char c: str) {
        if (c == ' ') continue;
        freq[c]++;
    }
    for (const char c: output) {
        if (c == ' ') continue;
        outputfreq[c]++;
    }

    for (auto [key, value]: outputfreq) {
        if (freq[key] < value) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}