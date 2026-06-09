//Beautiful Matrix

#include <iostream>
#include <cmath>
using namespace std;


int main() 
{
    int n = 5;
    int cur = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            cin >> cur;
            if (cur == 1) {
                cout << (abs(j - 2) + abs(i - 2));
                break; 
            }
        }
    }

    return 0;
}