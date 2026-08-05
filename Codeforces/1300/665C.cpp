//Simple Strings

/*
t is called simple if every pair of adjacent characters
are distinct

given string s,
change minimum number of characters so that string s becomes simple

output any soln
*/
#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            char replacement = 'a';
            while (s[i - 1] == replacement || (i < n - 1 && s[i + 1] == replacement)) {
                replacement++;
            }
            s[i] = replacement;
        }
    }
    cout << s;
}