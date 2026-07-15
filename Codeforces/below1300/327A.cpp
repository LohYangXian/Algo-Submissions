//Flipping Game

/*
n integers
0 or 1

choose two indices and flip all values within i,j inclusive

find one move to obtain maximum number of ones

1 0 0 1 0

0 1 2 2 3


3 3 2 1 1
3 2 0 1 2


1 0 0 1
0 1 2 2
2 2 1 0
2 1 1 2

*/
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v{};

    int n;
    int x;
    cin >> n;
    vector<int> dp(n);
    int num1{};

    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        if (x == 1) {
            num1++;
        }
    }

    for (int i = 0; i < n; i++) {
        int score{};
        for (int j = i; j < n; j++) {
            if (v[j] == 0) {
                score++;
            } else {
                score--;
            }
            dp[i] = max(dp[i], score);
        }
    }

    int res{};
    for (int i = 0; i < n; i++) {
        if (dp[i] > res) {
            res = dp[i];
        }
    }   
    if (res == 0) {
        res = -1;
    }

    cout << res + num1;
}