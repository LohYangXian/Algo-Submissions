// IQ Test

#include <vector>
#include <iostream>
using namespace std;

int main() {
    char x;
    vector<vector<char>> board{};

    for (int i = 0; i < 4; i++) {
        vector<char> row{};
        for (int j = 0; j < 4; j++) {
            cin >> x;
            row.push_back(x);
        }
        board.push_back(row);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int count{};
            if (board[i][j] == '.') count++;
            if (board[i][j + 1] == '.') count++;
            if (board[i + 1][j] == '.') count++;
            if (board[i + 1][j + 1] == '.') count++;
            if (count == 3 || count == 1 || count == 0 || count == 4) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}
