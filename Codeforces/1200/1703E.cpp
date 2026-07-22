// Mirror Grid

/*
n rows , n columns

Contains either 0 or 1

You can flip a cell

Find min num of flips so you can obtain a square
that remains the same when rotated 0, 90, 180, 270
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> matrix(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                matrix[i][j] = s[j];
            }
        }

        int res{};
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int f  = matrix[i][j] - '0';
                int s  = matrix[j][n - 1 - i] - '0';
                int t  = matrix[n - 1 - i][n - 1 - j] - '0';
                int fo = matrix[n - 1 - j][i] - '0';

                int sum = (f + s + t + fo);
                res += min(sum, 4 - sum);
            }
        }
        cout << res << "\n";
    }
}