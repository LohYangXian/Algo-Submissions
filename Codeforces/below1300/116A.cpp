// Tram
#include <iostream>
using namespace std;

int main() {
    int cur{};
    int resMin{};

    int n;
    int a;
    int b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cur = cur + b - a;
        resMin = max(cur, resMin);
    }

    cout << resMin;
}