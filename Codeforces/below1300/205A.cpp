#include <iostream>
#include <unordered_map>
#include <limits>
using namespace std;

int main() {
    long long minDist{numeric_limits<long long>::max()};
    int res;
    unordered_map<long long, int> minCount;
    int n;
    long long x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x <= minDist) {
            minDist = x;
            res = i;
            minCount[minDist]++;
        }
    }
    if (minCount[minDist] != 1) {
        cout << "Still Rozdil";
    } else {
        cout << res;
    }
}