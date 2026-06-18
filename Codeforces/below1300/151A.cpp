//soft drinking

#include <iostream>
using namespace std;

int main() {
    int n;
    int k;
    int l;
    int c;
    int d;
    int p;
    int nl;
    int np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int res{};

    res = k * l / nl / n;
    res = min(res, c * d / n);
    res = min(res, p / np / n);
    cout << res;
}