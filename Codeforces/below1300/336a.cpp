//Vasily the Bear and Triangle

/*
vertex at (0,0)
opp vertex at (x,y)

triangle
vertex at B = (0,0)


find two points A and C,
Xa < Xc

isoceles triangle ABC

all points of the rectangle is inside or on border of ABC

area of ABC is as small as possible

just get 

0,0 


*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    long long length = abs(x) + abs(y);

    if (x > 0 && y > 0) {
        cout << 0 << ' ' << length << ' '
             << length << ' ' << 0;
    }
    else if (x > 0 && y < 0) {
        cout << 0 << ' ' << -length << ' '
             << length << ' ' << 0;
    }
    else if (x < 0 && y > 0) {
        cout << -length << ' ' << 0 << ' '
             << 0 << ' ' << length;
    }
    else {
        cout << -length << ' ' << 0 << ' '
             << 0 << ' ' << -length;
    }

    return 0;
}