//Gigantomachy

/*
two giants, bea and ver 

own mountain range

bea range heights a 1 , a2, an
vers range b1 , b2, bm

left to right for bea
right to left for Ver

both stand at number 1 first, ranges arranged in non-increasing order

decide who wins
bea goes first
giant throws a boulder at the opp, height -- , if mountain infront is 
highjer than what he stands on, he jumps to it

t cases
n mountains
m mountains

n integers of heights
m integers of heights

output a number, number of giant who wins

*/
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; int m;
        cin >> n >> m;
        long long totalA = 0;
        long long totalB = 0;
        vector<long long> a{};
        vector<long long> b{};

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            a.push_back(x);
        }

        for (int i = 0; i < m; i++) {
            long long x;
            cin >> x;
            b.push_back(x);
        }

        for (int i = 0; i < n - 1; i++) {
            totalA += a[i] - a[i + 1] + 1;
        }
        totalA += a[n - 1];

        for (int i = 0; i < m - 1; i++) {
            totalB += b[i] - b[i + 1] + 1;
        }
        totalB += b[m - 1];

        if (totalA >= totalB) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}