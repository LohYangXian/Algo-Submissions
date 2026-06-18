//A. Amusing Joke

#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    unordered_map<char, int> m;
    unordered_map<char, int> freq;
    string ref;
    string name1;
    string name2;
    cin >> name1 >> name2 >> ref;
    for (const char c: ref) {
        m[c]++;
    }

    for (const char c: name1) {
        freq[c]++;
    }

    for (const char c: name2) {
        freq[c]++;
    }

    for (auto [key, value]: m) {
        if (freq.find(key) == freq.end() || freq[key] != value || freq.size() != m.size()) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}