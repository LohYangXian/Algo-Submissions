// Word
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    bool toUpper {false};
    vector<int> freq(2);

    string input;
    cin >> input;
    for (char c: input) {
        if (isupper(c)) {
            freq[1]++;
        } else {
            freq[0]++;
        }
    }
    if (freq[0] < freq[1]) toUpper = true;
    for (char& c: input) {
        if (toUpper) {
            c = toupper(c);
        } else {
            c = tolower(c);
        }
    }
    cout << input;
}