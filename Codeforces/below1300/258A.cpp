// Little Elephant and Bits

/*
integer a

delete exactly one any digit from number a in binary
then remaining binary digits, written in corresponding order

wants number to be as large as possible

find the max number he can obtain by deleteing exactly one digit
*/

#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            s.erase(i, 1);
            cout << s;
            return 0;
        }
    }

    s.erase(s.size() - 1, 1);
    cout << s;
}