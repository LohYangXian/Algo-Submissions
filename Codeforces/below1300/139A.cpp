// Petr and Book

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a; int b; int c; int d; int e; int f; int g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    int day{0};
    while (n > 0) {
        day = (day % 7) + 1;
        switch(day) {
            case 1:
                n -= a;
                break;
            case 2:
                n -= b;
                break;
            case 3:
                n -= c;
                break;
            case 4:
                n -= d;
                break;
            case 5:
                n -= e;
                break;
            case 6:
                n -= f;
                break;
            case 7:
                n -= g;
                break;
        }
    }

    cout << day;
}