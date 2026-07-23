//Pleasant Pairs

/*
a1 , a2, ... an of n distinct integers

count number of pairs of (i,j) such that i < j and 
ai * aj = i + j

t cases
n length of array a
n separated integers a1 a2 .... an (DISTINCT)

output number of pairs (i,j)

O(n) or O(n log n) soln

*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long res{};
        long long x;
        cin >> n;
        vector<pair<long long, long long>> v{};

        for (long long i = 1; i <= n; i++) {
            cin >> x;
            v.push_back({x, i});
        }

        sort(v.begin(), v.end());
        
        for (int i = n - 1; i > 0; i--) {
            int l = 0;
            while (l < i) {
                if (v[l].first * v[i].first >= 2 * n) break;

                if (v[l].first * v[i].first == v[l].second + v[i].second) {
                    res++;
                }
                l++;
            }
        }
        cout << res << "\n";
    }
}