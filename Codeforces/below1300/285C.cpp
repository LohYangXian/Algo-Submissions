// Building Permutation

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v{};
    vector<int> ref{};
    long long changes{};

    int n;
    int x;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v.push_back(x);
        ref.push_back(i);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        changes += (abs(ref[i] - v[i]));
    }
    cout << changes;
}