// Wow Factor

/*
for string a = "wowwo"

wow factor is number of subsequences equal to "wow"

however w is replaced by vv


*/
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long vCount = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'v' && s[i - 1] == 'v') vCount++;
    }
    
    long long res = 0;
    long long curVCount = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'o') {
            res += (curVCount * (vCount - curVCount));
        } else if (s[i] == 'v' && s[i - 1] == 'v') {
            curVCount++;
        }
    }

    cout << res;
}