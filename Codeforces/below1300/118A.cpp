// String Task
#include <string>
#include <iostream>
#include <unordered_set>
#include <cctype>
using namespace std;

int main() {
    string word;
    string res{};
    unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
    cin >> word;

    for (char c: word) {
        if (vowels.find(c) != vowels.end()) {
            continue;
        }
        res += '.';
        res += tolower(c);

    }

    cout << res;
}