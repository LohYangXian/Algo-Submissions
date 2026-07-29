// Strong Vertices

/*
arrays a and b 
length n

elements of both arrays indexed from 1 to n

constructing a directed graph where edge from u to v exists
if au - av > bu - bv

a vertex is strong if there exists a path from V to all other vertices

a path in a directed graph is a chain of several vertices
connected by edges
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int largest;
        vector<pair<int,int>> v{};

        cin >> n;

        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            v.push_back({x, i});
        }

        for (int i = 0; i < n; i++) {
            cin >> x;
            v[i].first -= x;
        }

        sort(v.begin(), v.end());

        largest = v[n - 1].first;

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (v[i].first == largest) {
                count++;
            }
        }

        cout << count << "\n";

        for (int i = 0; i < n; i++) {
            if (v[i].first == largest) {
                cout << v[i].second << " ";
            }
        }
        cout << "\n";
    }
}