// Ultra-fast Mathematician

#include <iostream>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a;
    cin >> b;
    string result;

    for (int i = 0; i < a.size(); i++)
    {
        result += (a[i] == b[i]) ? '0' : '1';
    }

    cout << result;
}