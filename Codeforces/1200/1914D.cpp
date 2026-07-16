//Three Activites

/*
n days
try all activities exactly once 

go skiing,
watch movie
board games

on ith day, exactly ai friends will join him 
for skiing

b friends movie
c friends board games

choose 3 distinct days x,y,z such that total is maximised

we need a O(n) soln

1 10 1
10 1 1
1 1 10

*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    for (int i = 0; i < t; i++) {
        int n;
        vector<pair<int,int>> a{};
        vector<pair<int,int>> b{};
        vector<pair<int,int>> c{};
        long long sum{};

        int x;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x;
                if (i == 0) {
                    a.push_back(pair{x, i});
                } else if (i == 1) {
                    b.push_back(pair{x, i});
                } else if (i == 2) {
                    c.push_back(pair{x, i});
                }
            }
        }
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        sort(c.begin(), c.end(), greater<>());
        vector<pair<int,int>> fA{};
        vector<pair<int,int>> fB{};
        vector<pair<int,int>> fC{};
        for (int i = 0; i < 3; i++) {
            fA.push_back(a[i]);
            fB.push_back(b[i]);
            fC.push_back(c[i]);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[i].second == b[j].second || b[j].second == c[k].second || a[i].second == c[k].second) continue;
                    sum = max(sum, static_cast<long long>(a[i].first) + static_cast<long long>(b[j].first) + static_cast<long long>(c[k].first));
                }
            }
        }
        cout << sum << "\n";
    }
}


