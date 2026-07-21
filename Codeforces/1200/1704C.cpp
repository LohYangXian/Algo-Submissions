//Virus

/*
n houses 
numbered from 1 to n on a circle

from 1 <= i <= n - 1 house i and i + 1 are neighbours
n and 1 are also neighbours

m of these houses are infected by a virus

each morning, can choose uninfected house and protect 
permanently

1. choose uninfected hse, protect it permanently
2. all uninfected unprotected houses with 1 infected neighbor becomes
infected

find minimum number of houses that will be infected in end
if she optimally choose the houses to protect

10 3 
3 6 8
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
        int m;

        cin >> n >> m;
        vector<long long> v{};

        long long x;
        for (int i = 0; i < m; i++) {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        vector<long long> gaps{};
        for (int i = 0; i < m; i++) {
            long long next = (i + 1) % m;
            long long gap = (v[next] - v[i] - 1 + n) % n;
            // cout << gap << "\n";
            gaps.push_back(gap);
        }

        sort(gaps.begin(), gaps.end(), greater<int>());
        long long res{n};

        int days{};

        for (long long i = 0; i < gaps.size(); i++) {
            long long remaining = gaps[i] - 2LL * days;
            if (remaining <= 0) {
                continue;
            } else if (remaining == 1) {
                res -= 1;
                days += 1;
            } else {
                res -= remaining - 1;
                days += 2;
            }
        }
        cout << res << "\n";
    }
}