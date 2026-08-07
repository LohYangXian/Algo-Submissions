//Boss Fight

/*
n spell cards

ith card deals ai damage

rearrange and reorder

if u play 2 cards that same, the sheild activates
all sub cards deal 0

find max total health boss can have such that you defeat him

t cases

n cards
*/
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unordered_map<int,int> m{};
        int n;
        cin >> n;

        long long total = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m[x]++;

            total += x;
        }

        for (auto [key, value]: m) {
            int o = n - value;
            int u = o + 2;

            if (value > u) {
                int un = value - u;
                total -= 1LL * un * key;
            }
        }

        

        cout << total << '\n';
       
    }
}