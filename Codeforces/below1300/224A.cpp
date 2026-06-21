// Parallelepiped
#include <iostream>
#include <cmath>
using namespace std;

// 4 6 6
// a x b , b x c , a x c
// a2 x b2 x c2 = 4 x 6 x 6
// try every combination 

//then 4 ( a + b + c )

int main() {
    int x; int y; int z;
    cin >> x >> y >> z;
    
    int a = sqrt(x * y / z);
    int b = sqrt(x * z / y);
    int c = sqrt(y * z / x);
    
    cout << (4 * (a + b + c));
    
}