#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for (int i = 0; i < 12; i++) {
        cin >> x;
        v.push_back(x);
    }

    int res{};
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < 12; i++) {
        if (n <= 0) {
            break;
        }
        res++;
        n -= v[i];
    }
    
    if (n <= 0) {
        cout << res;
    } else {
        cout << -1;
    }
}