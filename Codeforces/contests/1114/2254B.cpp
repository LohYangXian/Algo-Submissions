//Evanescent

/*
f(s) is compressed version of a string s, replacing every maximal contiguous block of identical characters with a single copy of that charactyer

aabbcc = abc

give string s consisting of n lowercase letters

delete exactly one character to form a new string s, find minimum possible value of f(s) you cannot delete s1 or sn
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string newS = "";
        newS += s[0];
        vector<int> chunks{};
        chunks.push_back(1);

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                newS += s[i];
                chunks.push_back(1);
            } else {
                chunks.back()++;
            }
        }

        int newN = newS.size();
        int res = newN;
        for (int i = 1; i < newN - 1; i++) {
            if (chunks[i] == 1) {
                res = min(res, newN - 1);

                if (newS[i - 1] == newS[i + 1]) {
                    res = min(res, newN - 2);
                }
            }
        }

        cout << res << "\n";
    }
}