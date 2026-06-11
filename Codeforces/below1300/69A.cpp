#include <iostream>
using namespace std;

// Young Physicist

// // Input 
// 3
// 4 1 7
// -2 4 -1
// 1 -5 -3

int main() {
    int n;
    cin >> n;

    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }

    if (x == 0 && y == 0 && z == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}