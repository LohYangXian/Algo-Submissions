// Polo the Penguin and Matrix

/*
n x m matrix

index rows from 1 to n from top to bottom
index columns from 1 to m from left to right

add or subtract number d from some matrix
find min number of moves needed to make all matrix elements equal

return -1 if impossible

1st condition, all numbers % d must have the same remainder

then we need to find the median? of the numbers ish
2 4 6 8

20 / 4 = 5

*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    vector<int> v{};

    int n;
    int m;
    int d;
    cin >> n >> m >> d;
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            v.push_back(x);
        }
    }

    int commonD = v[0] % d;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % d != commonD) {
            cout << -1;
            return 0;
        }
    }

    sort(v.begin(), v.end());
    
    int midI = v.size() / 2;
    long long res{};
    for (int i = 0; i < v.size(); i++) {
        res += (static_cast<int>(abs(v[i] - v[midI]) / d));
    } 

    cout << res;

}