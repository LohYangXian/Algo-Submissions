//Ball in Berland

/*
pairs of boys and girls

a boys and b girls

k possible pairs

distinct

boys number first, then girls number

find number of ways to select two pairs that match the condition above

t cases
a boys, b girls, k pairs

k integers is number of boy in pair with number i
k integers number of girl in pair with number i

try O(n) soln
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a; int b; int k;
        cin >> a >> b >> k;

        vector<pair<long long, long long>> pairs{};
        vector<long long> boyCount(a + 1);
        vector<long long> girlCount(b + 1);

        for (int i = 0; i < k; i++) {
            long long x;
            cin >> x;
            pairs.push_back({x, -1});
            boyCount[x]++;
        }

        for (int i = 0; i < k; i++) {
            long long x;
            cin >> x;
            girlCount[x]++;
            pairs[i].second = x;
        }

        long long res = 0;

        for (auto& [boy, girl] : pairs) {
            res += k - (girlCount[girl] - 1) - boyCount[boy];
        }
        
        cout << res / 2 << "\n";
    }
}