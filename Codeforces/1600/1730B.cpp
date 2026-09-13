//Meeting on the Line


/*
n people live on the coordinate line, ith one lives at the point
x

they want to choose a position x0 to meet.
ith person will spend |xi - x0 | minutes to get
to the meeting place. Also ith person needs t minutes to
get dressed, so in total he or she needs
ti + |xi - x0| minutes

find a position x0 that minimizes the time in which all
n people can gather at the meeting place

t cases 10^3
n people 
n integers (positions)

n integers of t time

O(n) or O(n log n) soln

print a single real number, x0
i think result is a float? 
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

long long calc(long long y, vector<pair<long long,long long>>& v) {
    long long mx = 0;

    for (auto &[x, t] : v) {
        mx = max(mx, 2 * t + abs(2 * x - y));
    }

    return mx;
}

long long findAns(vector<pair<long long,long long>>& v) {
    long long mn = v[0].first;
    long long mx = v[0].first;

    for (auto &[x, t] : v) {
        mn = min(mn, x);
        mx = max(mx, x);
    }

    long long l = 2 * mn;
    long long r = 2 * mx;

    while (l < r) {
        long long mid = l + (r - l) / 2;

        long long curr = calc(mid, v);
        long long next = calc(mid + 1, v);

        if (curr <= next) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long, long long>> v;
        
        for (int i = 0; i < n; i++) {
            long long x; 
            cin >> x;
            v.push_back({x, -1});
        }
        
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v[i].second = x;
        }

        long long ans = findAns(v);
        cout << fixed << setprecision(10) << ans / 2.0 << '\n'; 
    }
}