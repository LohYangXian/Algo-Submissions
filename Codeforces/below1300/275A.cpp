// Lights Out
/*
* 1 0 1  
* 8 8 8  
* 2 0 3
*/

// 0 1 0
// 0 1 1
// 1 0 0 
// Jth number in ith row is number of times the jth light of the ith row is pressed

#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> result(3, vector<int>(3,1));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            int change = x % 2;
            // amend center and adj squares
            if (i > 0) result[i - 1][j] ^= change;
            result[i][j] ^= change;
            if (j > 0) result[i][j - 1] ^= change;
            if (j < 2) result[i][j + 1] ^= change;
            if (i < 2) result[i + 1][j] ^= change;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j];
        }
        if (i < 2) cout << "\n";
    }
}