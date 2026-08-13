//Schedule Management

/*
n workers
m tasks

workers numbered 1 to n

each task i has value a (index of worker proficient in this task)

every task shld have a worker assigned
if proficient, 1 hour, else 2 hour

assign workers in a way to complete tasks asap

time 0, whats min time tasks completed by

t cases

n workers, m tasks

m values of a.... index of worker proficient in ith task

try O(m) soln

try a priority queue
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool solvefork(long long mid, vector<long long>& v) {
    long long need = 0;
    long long surplus = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < mid) {
            surplus += (mid - v[i]) / 2;
        } else if (v[i] > mid) {
            need += (v[i] - mid);
        }
    }
    return need <= surplus;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; int m;
        cin >> n >> m;
        vector<long long> v(n,0);
        for (int i = 0; i < m; i++) {
            long long x;
            cin >> x;
            v[x - 1]++;
        }

        long long l = 0;
        long long r = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] > r) r = v[i];
        }

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (solvefork(mid, v) == false) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << l << "\n";
    }
}