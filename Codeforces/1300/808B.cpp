//Average Sleep Time

/*
last n days

a1, a2, ... 

a is sleep time on ith day

number of records is so large that he cant cal avg value

to get avg, consider k consecutive days as a week

n - k + 1 weeks to take into consideration

if k = 2, n = 3,

(3 + 4) + (4 + 7)

sliding window sum divide by number of sliding windows

n and k

use long long
*/
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<long long> v{};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int l = 0;
    int r = 0;

    long long rollingSum = 0;
    while (r < k) {
        rollingSum += v[r];
        r++;
    }

    long long weeks = n - k + 1;

    long long total = rollingSum;

    while (r < n) {
        rollingSum -= v[l];
        rollingSum += v[r];
        total += rollingSum;
        l++;
        r++;
    }

    cout << fixed << setprecision(6) << static_cast<double>(total * 1.000000/ weeks);
}