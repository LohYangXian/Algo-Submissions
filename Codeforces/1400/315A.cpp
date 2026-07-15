#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> bottles(n);

    for (int i = 0; i < n; i++) {
        cin >> bottles[i].first >> bottles[i].second;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        bool canOpen = false;

        for (int j = 0; j < n; j++) {
            if (i != j && bottles[j].second == bottles[i].first) {
                canOpen = true;
                break;
            }
        }

        if (!canOpen) ans++;
    }

    cout << ans;
}