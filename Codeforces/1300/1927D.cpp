//Find the different ones

/*
array a of n integers, and q queries

each query is represented by two integers l and r (1 <= l 
<= r <= n) 

find for each query, two indices i and j or (determine they dont
exist) such that

l <= i <= r
l <= j <= r

ai != aj

for each query, find a pair of diff elements among
al , ai+ 1, .... ar , or determine they dont exist

t case
n length
n integers
q
q queries of l, and r

find a O(1) solution
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> v{};
        cin >> n;
        vector<int> pre(n, -1);
        int x;
        int l;
        int r;
        int q;

        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }

        for (int i = n - 2; i >= 0; i--) {
            if (v[i] != v[i + 1]) {
                pre[i] = i + 2;
            } else {
                pre[i] = pre[i + 1];
            }
        }

        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> l >> r;
            if (pre[l - 1] != -1 && pre[l - 1] <= r) {
                cout << l << " " << pre[l - 1] << "\n";
            } else {
                cout << -1 << " " << -1 << "\n";
            }
        }
        cout << "\n";
    }
}