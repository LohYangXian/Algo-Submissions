// Fence

/*
find indexes of k consecutive plans with minimal total height
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int k;
    int x;
    vector<int> v{};

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int cur{};
    

    int l{};
    int r{k};
    for (int i = 0; i < k; i++) {
        cur += v[i];
    }

    int res{cur};
    int resIdx{0};

    while (r < n - 1) {
        r++;
        cur += v[r];
        cur -= v[l];
        l++;

        if (cur < res) {
            res = cur;
            resIdx = l;
        }
    }

    cout << resIdx;
}