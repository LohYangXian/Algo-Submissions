// TL

/*
n correct solutions

m wrong solutions

a seconds extra running time

set v seconds TL, at least one correct soln passes with extra time
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;

    int minWrong{numeric_limits<int>::max()};
    int minCorrect{numeric_limits<int>::max()};
    int maxCorrect{numeric_limits<int>::min()};

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < minCorrect) minCorrect = x;
        if (x > maxCorrect) maxCorrect = x;
    }

    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x < minWrong) minWrong = x;
    }
    if (minWrong <= maxCorrect) {
        cout << -1;
        return 0;
    } else if (minCorrect * 2 > maxCorrect) {
        if (minCorrect * 2 < minWrong) {
            cout << minCorrect * 2;
            return 0;
        } 
        cout << -1;
        return 0;
    }

    cout << maxCorrect;
}