//Yet Another Problem About Pairs Satisfying an Inequality

/*
given an array 

count the number of pairs of indices
i,j i<j

such that ai < i < aj < j????

t cases
n length

n integers

get a O(n) soln

output the number of pairs 
use long long
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v{};
        vector<long long> diff{};
        long long res{};
        vector<long long> indices{};

        long long x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            v.push_back(x);
            diff.push_back(x - i);
        }
        long long count = 0;
        for (int i = 0; i < n; i++) {
            if (diff[i] < 0) { 
                res += lower_bound(indices.begin() , indices.end(), v[i]) - indices.begin();
                indices.push_back(i + 1);
            }
        }

        cout << res << "\n";
    }
}