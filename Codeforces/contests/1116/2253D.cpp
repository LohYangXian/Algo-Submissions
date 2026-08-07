
//Hypercarp and Interdimensional Jumps

/*
located at point (0,0 )

need to reach (x,y)

current state, jump vector (a,b)

when engine , ship moves by a along first coord, 
and b aloong second coord

initially (a,b) == (0,0)

each cycle is a move
1. increase a or b by 1
2. jump (p,q) to (p + a, q + b)

a and b cannot be decreased

ship cannot leave the rectangle after any jump, 
aka x >= 0 , x <= x , y >= 0 , y <= y

stop as close to x,y as possible

distance is (p - x ) ^ 2 + (q - y )^ 2

at most (20 000) jumps, maybe we can simulate
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        long long y;
        cin >> x >> y;

        long long k = -1;

        for (long long i = 1; (i * (i + 1) / 2) <= x + y; i++) {
            k = i;
        }

        long long total = (k * (k + 1) / 2);

        long long p = 0;

        long long minDist = numeric_limits<long long>::min();
        long long finalAnsP;

        while (p <= x) {
            long long dist = pow(x - p, 2) + pow(y - (total - p), 2);
            if (dist < minDist) {
                finalAnsP = p;
                minDist = dist;
            }
            p++;
        }

        cout << 

    }
}