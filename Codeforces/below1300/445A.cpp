// DZY loves chessboard

/*
chessboard of n rows and m columns. Each chessman is either white or black. 
No two chessmen with same color are on two adjacent cells. 
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    char x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x == '-') {
                cout << '-';
            } else if ((i + j) % 2 == 0) {
                cout << 'B';
            } else {
                cout << 'W';
            }
        }
        if (i < n - 1) cout << "\n";
    }
}