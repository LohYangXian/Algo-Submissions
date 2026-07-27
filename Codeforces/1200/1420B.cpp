//Rock and Lever

/*
n > 0

array a, ai ai+1, ... > 0

calc number of pairs such that i < j and 
a ^ j >= ai XOR aj ???? 


t cases
n array length

o(n) soln
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int x;
        unordered_map<int,int> freq{};
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            int count = 31 - __builtin_clz(x);
            freq[count]++;
        }
        long long res{};

        for (auto [key, value]: freq) {
            if (value > 1) {
                res += (1LL * value * (value - 1)) / 2;
            }
        }

        cout << res << "\n";
    }

}