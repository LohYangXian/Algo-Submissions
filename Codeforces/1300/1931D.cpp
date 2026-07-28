// Divisible Pairs

/*
x and y (can be equal)
found an array a of length n

pair of indices are beautiful if 

ai + aj % x == 0
ai + aj % y == 0

find number of beautiful pairs in the array a

t cases
n, x , y
*/
#include <map>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        long long y;
        cin >> n >> x >> y;

        long long z;
        long long res{};
        map<pair<long long, long long>, long long> freq{};

        for (int i = 0; i < n; i++) {
            cin >> z; 
            
            long long needX = (x - (z % x)) % x;
            long long remY = z % y;

            if (freq.find({needX, remY}) != freq.end()) {
                res += freq[{needX, remY}];
            }

            freq[{z % x, remY}]++;
        }

        cout << res << "\n";
    }
}