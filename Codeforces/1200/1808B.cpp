//Playing in a Casino

/*
n cards

m numbers

all players play with each other in pairs

similar to the constrast question

winner gets [ |a1 - b1| + |a2 - b2| + |a3 - b3| + ...]

t cases

calc the total amount of winnings from all games
(aka for all pairs, calc the sum of abs differences)

we need to solve this in O(n) per case

3
3 5
1 4 2 8 5
7 9 2 1 4
3 8 5 3 1

1-2 1-3 2-3

6 + 5 + 7 + 1 = 19
2 + 4 + 3 + 5 + 4 = 18
4 + 1 + 3 + 2 + 3 = 13

50 // 



1 4
4 15 1 10


4 3
1 2 3
3 2 1
1 2 1
4 2 7

O(n) solution is fine 

1-2 + 1-3 + 1-4 + 2-3 + 2-4 + 3-4 = 
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >> n >> m;

        vector<vector<long long>> matrix(n, vector<long long>(m));
        long long x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                matrix[i][j] = x;
            }
        }

        long long sum{};
        for (int i = 0; i < m; i++) {
            vector<long long> col{};
            for (int j = 0; j < n; j++) {
                col.push_back(matrix[j][i]);
            }
            sort(col.begin(), col.end());

            vector<long long> prefix(col.size());
            for (int k = 1; k < n; k++) {
                prefix[k] += col[k - 1];
                prefix[k] += prefix[k - 1];
            }

            for (int k = 0; k < n; k++) {
                sum += (k * col[k] - prefix[k]);
            }
        }
        cout << sum << "\n";
    }
}

