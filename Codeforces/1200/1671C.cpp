// Dolce Vita

/*
n shops 
ith shop sells one pack of sugar for a coins
only one pack to one customer each day

to buy several packs, visit several shops

price increase + 1 after each day

budget everyday is X coins

if cost for each pack exceed x, u cant buy anything

t cases

n number of shops

x total budget

n integers, a1 a2 a3.. an

look for a O(n) soln
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int x;
        cin >> n >> x;

        long long val;
        long long res{};
        vector<long long> v{};
        vector<long long> prefix{};

        for (int i = 0; i < n; i++) {
            cin >> val;
            v.push_back(val);
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            prefix.push_back(v[i]);
            if (i > 0) {
                prefix[i] += prefix[i - 1];
            }
        }

        long long days{};
        long long packs{};
        for (int i = n - 1; i >= 0; i--) {
            if (prefix[i] > x) continue;
            int numDays = ((x - prefix[i]) / (i + 1)) + 1;
            packs += (numDays - days) * (i + 1);
            days += (numDays - days);
        }
        cout << packs << "\n";
    }
}
