// Comparing Strings

/*
two dwarves belong to the same race if we can swap two characters in the first genome and second genome 
*/

// count freq count, and count mismatches? mismatch = 2 

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;

    unordered_map<char,int> freqA{};
    unordered_map<char,int> freqB{};
    for (const char c: a) {
        freqA[c]++;
    }
    for (const char c: b) {
        freqB[c]++;
    }
    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }

    int mismatch{};
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) mismatch++;
    }

    if (mismatch > 2) {
        cout << "NO";
        return 0;
    }

    for (auto [key, value]: freqA) {
        if (freqB.find(key) == freqB.end() || value != freqB[key]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}