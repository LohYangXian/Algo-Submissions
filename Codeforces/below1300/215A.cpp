// Bicycle Chain

// n stars pedal axle, m stars rear wheel axle
// n ^ 2 solution?
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    vector<int> vN{};
    vector<int> vM{};
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vN.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        vM.push_back(x);
    }

    int res{};
    int max{-1};
    unordered_map<int, vector<pair<int,int>>> freq{};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vM[j] % vN[i] == 0) {
                int div = vM[j] / vN[i];
                if (res < div) res = div;
                freq[div].push_back(pair{i, j});
            }
        }
    }
    cout << freq[res].size();
}