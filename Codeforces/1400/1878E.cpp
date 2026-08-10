// Iva & Pav

/*
array a of n elements

define f(l,r) = al & a;+1 & .... ar

l <= r

Iva also gave Pav q queries

each query 2 numbers, k and l, find largest r , such that f(l,r) >= k

t cases
n array
n integers
q
q lines of l and k

sum of n and sum of q < 10^5
O(n) or O(q) soln

5
15 14 17 42 34
3
1 R 7
2 R 15
4 R 5

0 0 1 1 1 1  15 15           | 15   | 0     | 
0 0 1 1 1 0  14 14 14        | 14   | 0     |
0 1 0 0 0 1  17 0  0  17     | 0    | 0     |
1 0 1 0 1 0  42 0  0  0  42. | 0    | 34    |
1 0 0 0 1 0  34 0  0  0  34. | 0    | 34    |

0 1 0 0 1 1  19 | 
0 1 0 1 0 0  20 | 
0 0 1 1 1 1  15 | 
0 0 1 1 0 0  12 | 
0 1 0 1 0 1  21 | 
0 0 0 1 1 1  7  | 
0 0 1 0 1 1  11 | 



interesting thing is that itll always be non increasing,
so u start from a[l] , if a[l] < k, we can instantly return -1
then if not, we can &= until we get the first value thats < k 

problem is that we can change L

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
        cin >> n;
        vector<long long> v{};
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        vector<vector<int>> nextZero(n, vector<int>(30, n));
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 30; b++) {
                if (((v[i] >> b) & 1) == 0) {
                    nextZero[i][b] = i;
                } else if (i + 1 < n) {
                    nextZero[i][b] = nextZero[i + 1][b];
                }
            }
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int l;
            long long k;
            cin >> l >> k;
            if (v[l - 1] < k) {
                cout << -1 << " ";
                continue;
            }

            int s = l - 1;
            long long cur = v[s];

            vector<pair<int, int>> events;

            for (int b = 0; b < 30; b++) {
                if ((cur >> b) & 1) {
                    events.push_back({nextZero[s][b], b});
                }
            }

            sort(events.begin(), events.end());

            int ans = n;
            for (int j = 0; j < events.size();) {
                int pos = events[j].first;

                if (pos == n) break;

                while (j < events.size() && events[j].first == pos) {
                    int b = events[j].second;
                    cur &= ~(1LL << b);
                    j++;
                }

                if (cur < k) {
                    ans = pos;
                    break;
                }
            }

            cout << ans << " ";
        

        }
        
        cout << "\n";
    }
}