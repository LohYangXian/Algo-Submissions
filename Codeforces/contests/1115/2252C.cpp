//Risky Tower

/*
2d jenga game

n rows
m columns

1st row  is top level

n row is bottom (intuitive)

each piece at i,j has destablization factor of aij
each row i has stability index of vi

when u remove a piece from row i damanges all elvels at and above it
for every row k at and above, stability - aij

tower collapse if stability level of any level drops <= 0

any level is left with exactly 0 pieces (even top leve)

t case
n rows, m cols
n integers, stability indices of each level from level 1 to n

next n lines m integers, aij

we can do a O(n) soln

min pieces removed to collapse the tower
*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> merge(vector<long long>& best, vector<long long>& cur) {
    int size = cur.size();
    vector<long long> merged{};
    int pointerA = 0;
    int pointerB = 0;
    while (merged.size() < size) {
        if (pointerA < best.size() && best[pointerA] >= cur[pointerB]) {
            merged.push_back(best[pointerA]);
            pointerA++;
        } else {
            merged.push_back(cur[pointerB]);
            pointerB++;
        }
    }
    return merged;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >> n >> m;

        vector<long long> v{};
        vector<vector<long long>> a{};
        vector<vector<long long>> largestMSeen{};

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            vector<long long> row{};
            for (int j = 0; j < m; j++) {
                long long x;
                cin >> x;
                row.push_back(x);
            }
            a.push_back(row);
        }

        vector<long long> largestMRow(m);
        int ans = m;

        for (int i = n - 1; i >= 0; i--) {
            sort(a[i].rbegin(), a[i].rend());

            largestMRow = merge(largestMRow, a[i]);

            long long sum = 0;

            for (int k = 0; k < m; k++) {
                sum += largestMRow[k];

                if (sum >= v[i]) {
                    ans = min(k + 1, ans);
                    break;
                }
            }
        }

        cout << ans << "\n";
    }
}