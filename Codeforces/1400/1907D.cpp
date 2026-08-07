//Jumping through Segments

/*
level consists of n segments on line

ith segment starts at the point with coord l and ends at 
point with coord r

starts level at coord 0,
can move any pt within <= k

after ith move, land within ith segment, x l <= x <= r

after first move, must be inside the first segment (from l1 to r1)

after the second move, must be inside segment (l2 to r2)

after nth move (inside nth segment) (from ln to rn)

complete if player reaches nth segment

determine min k which is possible

(might be a binary search qns)

t cases,
n segments
ith , l1 and r1
*/
#include <iostream>
#include <vector>
using namespace std;


bool solvable(long long k, vector<vector<long long>>& v) {
    long long L = v[0][0];
    long long R = v[0][1];

    for (int i = 1; i < v.size(); i++) {
        long long l = v[i][0];
        long long r = v[i][1];

        L = max(L - k, l);
        R = min(R + k, r);

        if (L > R) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<vector<long long>> v;
        cin >> n;
        v.push_back({0,0});

        for (int i = 0; i < n; i++) {
            long long l;
            long long r;
            cin >> l >> r;
            v.push_back({l,r});
        }

        long long lastL = v[0][0];
        long long lastR = v[0][1];
        long long largestK = 0;
        for (int i = 0; i < n + 1; i++) {
            largestK = max(largestK, abs(v[i][1] - lastR));
            largestK = max(largestK, abs(v[i][0] - lastL));
            lastL = v[i][0];
            lastR = v[i][1];
        }

        long long low = 0;
        long long high = largestK;
        while (low <= high) {
            // cout << low << " " << high << "\n";

            long long mid = (low + high) / 2;
            bool canSolve = solvable(mid, v);
            // cout << mid << " " << canSolve << "\n";
            if (canSolve == true) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // cout << low << " " << high << "\n";
        cout << low;
        cout << "\n";
    }
}
