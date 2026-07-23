//Stable Groups

/*
n students numerated from 1 to n

level of ith student is ai

split the students into stable groups

group is stable if sorted array of their levels no 2 neighboring
elements differ by more than x

invite at most k additional students

find min number of stable groups teachers can form
from all students

(u can slot in additional k students to make the group stable)
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    long long k;
    long long x;
    cin >> n >> k >> x;
    vector<long long> gaps{};
    vector<long long> levels{};

    long long val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        levels.push_back(val);
    }

    sort(levels.begin(), levels.end());

    for (int i = 1; i < n; i++) {
        if (levels[i] - levels[i - 1] > x) {
            gaps.push_back(levels[i] - levels[i - 1]);
        }
    }

    sort(gaps.begin(), gaps.end());

    int pointer = 0;
    while (k > 0 && pointer < gaps.size()) {
        long long cur = gaps[pointer];
        long long req = cur / x;
        if (cur % x != 0) req++;
        req--;
        if (req <= k) {
            k -= req;
            pointer++;
        } else {
            k = 0;
        }
    }

    cout << gaps.size() - pointer + 1;
}