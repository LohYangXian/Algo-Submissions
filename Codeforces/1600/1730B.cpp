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
using namespace std;

double calc(double x0, vector<pair<double,double>>& v) {
    double mx = 0;

    for (auto &[x, t] : v) {
        mx = max(mx, t + abs(x - x0));
    }

    return mx;
}
double findAns(vector<pair<double,double>>& v, vector<double>& vals) {
    int l = 0;
    int r = vals.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        double curr = calc(vals[mid], v);
        double next = calc(vals[mid + 1], v);

        if (curr <= next) {
            // bottom is at mid or somewhere to the left
            r = mid;
        } else {
            // still going downhill
            l = mid + 1;
        }
    }

    return vals[l];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<double, double>> v;
        
        for (int i = 0; i < n; i++) {
            double x; 
            cin >> x;
            v.push_back({x, -1});
        }
        
        for (int i = 0; i < n; i++) {
            double x;
            cin >> x;
            v[i].second = x;
        }

        double lo = v[0].first;
        double hi = v[0].first;

        for (auto &[x, t] : v) {
            lo = min(lo, x);
            hi = max(hi, x);
        }
        
        vector<double> vals;

        for (double x = lo; x <= hi; x += 0.5) {
            vals.push_back(x);
        }

        cout << findAns(v, vals) << "\n";
    }
}