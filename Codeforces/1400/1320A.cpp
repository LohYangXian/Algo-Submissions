// Journey Planning

/*
n cities
1 to n city

choose some city c1 to start journey

then go to another city2 > city1
then city3 > c2

choose to end her journey in some city ck > ck-1

so sequence of visited cities is strictly increasing

i has beauty value bi associated

if there are multiple cities in sequence, for adj
pairs
ci and ci+1, ci+1 - ci = bci+1 - bci must hold (IMPORTANT)

maximize total beauty values of subarray
n cities
n integers of beauty values

try O(n) or O(n log n) soln
*/
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v{};
    vector<long long> transformedV{};
    unordered_map<long long, long long> total{};

    long long ans = -1;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
        transformedV.push_back(i - x);
        total[i - x] += x;
    }

    for (auto& [key, value]: total) {
        ans = max(ans, value);
    }

    cout << ans;
}