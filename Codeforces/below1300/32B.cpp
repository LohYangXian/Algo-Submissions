#include <iostream>
using namespace std;

int main() {
    string answer; 
    char a;
    char b;
    while (cin >> a) {
        if (a == '.') 
        {
            answer += '0';
        } else {
            cin >> b;
            if (b == '.') answer += '1';
            if (b == '-') answer += '2';
        }
    }
    cout << answer;
    return 0;
}