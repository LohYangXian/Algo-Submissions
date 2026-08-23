// Tape

/*
m segments from 1 to m
each segment 1 cm, some segments r broken

a tape of length t placed at s will come 
s, s + 1,... s + t - 1


allowed to cover non-broken segments

cut at most k continuous pieces of tape to cover all broken segments

what is minimum total length of these pieces

n broken segments, m length of stick, k max pieces
n integers (position of broken segments)
increasing order (take note!)
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    long long m;
    cin >> n >> m >> k;

    vector<long long> b(n);
    for (auto& x : b) cin >> x;

    vector<long long> gaps;

    for (int i = 1; i < n; i++) {
        gaps.push_back(b[i] - b[i - 1] - 1);
    }

    sort(gaps.rbegin(), gaps.rend());

    long long ans = b[n - 1] - b[0] + 1;

    for (int i = 0; i < k - 1; i++) {
        ans -= gaps[i];
    }

    cout << ans << '\n';
}