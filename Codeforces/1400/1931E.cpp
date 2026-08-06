//Anna and the Valentine's Day Gift

/*
list a of n integers 

play a game,

anna first, sasha next

anna choose an element ai from the list and reverse sequence of 
its digits. leading zeros r removed

sasha must extract two elements ai and aj (i != j) from list,
concat them in any order, and insert back into list (like a string)

ends when sasha cant make a move. if integer >= 10^m, sasha wins
else anna wins

determine who will win
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int trailingZeros(long long x) {
    long long y = x;
    if (y == 0) return 1;
    int cnt = 0;
    while (y % 10 == 0) {
        cnt++;
        y /= 10;
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        int m;
        cin >> n >> m;

        vector<int> v{};
        int mCount = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(trailingZeros(x));
            int cnt = to_string(x).size();
            mCount += cnt;
        }

        sort(v.begin(), v.end(), greater<int>());

        int annaTurns;
        if (n % 2 == 0) {
            annaTurns = n / 2;
        } else {
            annaTurns = (n / 2) + 1;
        }

        for (int i = 0; i < annaTurns; i++) {
            mCount -= v[i * 2];
        }

        if (mCount < m + 1) {
            cout << "Anna" << "\n";
        } else {
            cout << "Sasha" << "\n";
        }
    }
}