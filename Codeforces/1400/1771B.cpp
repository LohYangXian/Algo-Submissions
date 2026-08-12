//Hossam and Friends

/*
n friends numbered from 1 to n

m pairs of friends that dont know each other 

subsegment of q starting from a ending at b is
[a, a + 1, ... b]
subsegment is good when all pairs are friends

wants know how many pairs there are such that subsegment 
is good (a,b)

t cases
n friends, m pairs
m lines of x and y (friends who dont know each other)

find a O(n / m / n + m ) answer

3, 2

1 3
2 3

*/
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; int m;
        cin >> n >> m;

        vector<int> pre(n, n + 1);

        for (int i = 0; i < m; i++) {
            int x; int y;
            cin >> x >> y;
            if (y < x) {
                int temp = x;
                x = y;
                y = temp;
            }

            pre[x - 1] = min(pre[x - 1], y);
        }

        for (int i = n - 2; i >= 0; i--) {
            pre[i] = min(pre[i], pre[i + 1]);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            // cout << pre[i] << " ";
            res += (pre[i] - i - 1);
        }
        // cout << " \n";
        cout << res << "\n";
    }
}