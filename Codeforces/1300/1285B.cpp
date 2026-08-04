//Just eat it

/*
n cupcake types, arranged from
1 to n on shelf

infinitely many of each type
tastiness of a cupcake of type i is an integer ai

tastiness can be positive, zero , negative

buy exactly one cupcake of each type

choose segment l,r that does not include all
cupcakes

yasser will buy exacrly one of each upe

adel will choose some segment l < r and buy one of each type

yasser will be happy if sum (yas) > sum (abel)

t cases
n integers

O(n) res
*/
#include <iostream>
#include <vector>
using namespace std;

long long getMax(vector<long long>& v, int l, int r) {
    long long curMax = 0;
    long long globalMax = numeric_limits<long long>::min();;
    for (int i = l; i < r; i++) {
        curMax += v[i];

        globalMax = max(globalMax, curMax);
        if (curMax < 0) {
            curMax = 0;
        }
    }
    return globalMax;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v{};
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            totalSum += x;
            v.push_back(x);
        }

        long long globalMax = max(getMax(v, 0, n - 1), getMax(v, 1, n));
        if (globalMax >= totalSum) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}