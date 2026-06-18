//Petya and Strings
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    std::transform(a.begin(), a.end(), a.begin(),
    [](unsigned char c){ return std::tolower(c); });
    std::transform(b.begin(), b.end(), b.begin(),
    [](unsigned char c){ return std::tolower(c); });

    if (a < b) {
        cout << -1;
    } else if (b < a) {
        cout << 1;
    } else {
        cout << 0;
    }
}