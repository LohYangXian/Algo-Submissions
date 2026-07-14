// Domino

/*
n pieces

each piece 2 halves, upper and lower one

rotate pieces such that sum of top half is even and sum of bottom half is even

find minimum swaps, 1 swap is 1 second

n
xi yi

if sum of half is even and sum of bot is even, return 0

we shld count number of odd and evens for top and bot 
e.g. top/bot is odd/even counts, then if 

1 4 +3
2 3 +1
4 4 +0
6 4

= = 
13 15 


2 2
2 5
1 1
3 1
= =
8 9

*/

#include <iostream>
using namespace std;

int main() {
    int n;
    bool haveOddDiff{false};
    int top{};
    int bot{};
    
    cin >> n;
    
    int x;
    int y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        top += x;
        bot += y;
        if (abs(x - y) % 2 == 1) {
            haveOddDiff = true;
        }
    }

    if (top % 2 == 0 && bot % 2 == 0) {
        cout << 0;
        return 0;
    } 

    if (top % 2 == 0 || bot % 2 == 0 || haveOddDiff == false) {
        cout << -1;
        return 0;
    }

    cout << 1;
}

