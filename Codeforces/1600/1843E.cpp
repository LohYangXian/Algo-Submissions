//Tracking Segments

/*
array a consisting of n zeroes, given set m diff segments

l and r (1 <= l <= r <= n)
subarray of a 

l,r beautiful if number of ones on segment is strictly greater than 
number of zeroes

q changes
muyst assign element ax the value 1

find the first change after which at least one of
m given segments become beautiful, or none are

t cases
n, m segments
m lines of l and r
q
q lines of index x, (set to 1)

n <= 10^5, we can try O(n) or O(n log n) solution
means probably O(1) per qth flip to 1 or log n
*/
#include <map>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<pair<int, int>> range;
vector<int> queries;

bool solve(int k, int n, int m) {
    vector<int> v(n);
    for (int i = 0; i < k; i++) {
        v[queries[i] - 1] = 1;
    }
    for (int i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }
    for (int q = 0; q < m; q++) {
        int l = range[q].first - 1;
        int left;
        if (l == 0) {
            left = 0;
        } else {
            left = v[l - 1];
        }
        int r = range[q].second - 1;
        if (v[r] - left > (r - l + 1) / 2) return true; 
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        range.clear();
        queries.clear();
        
        int n;
        int m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int l;
            int r;
            cin >> l >> r;
            range.push_back({l,r});
        }
        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            queries.push_back(x);
        }
        int l = 1;
        int r = q;
        bool solved = false;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            bool achieved = solve(mid, n, m);
            if (achieved) {
                solved = true;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (solved) {
            cout << l << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}