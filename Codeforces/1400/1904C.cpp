//Array Game

/*
a of n positive integers

pick some (i,j) 1 <= i < j < = |a| and append |ai - aj| to end of a 
minimise and print the minimum value of a after performing k operations

find the minimum of min of array a after k operations

t cases

n, k

n integers


3 9 7 15 1 



3 9 

O(n^2) Solution


find the smallest 

5 1 3 2 4
1 3 7 9 15



if k = 0,
just get the minimum of the array

if k = 1, find the pair where i < j and they have the smallest diff
and compare it to the min of the array

if k = 2, use this min, and compare w the next smallest diff w the new elem

if k == 3, = 0 straight
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<long long> a{};
        int n;
        int k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            a.push_back(x);
        }

        if (k >= 3) {
            cout << 0 << "\n";
            continue;
        }

        sort(a.begin(), a.end());

        if (k == 0) {
            cout << a[0] << "\n";
            continue;
        }

        long long soln = numeric_limits<long long>::max();

        for (int i = 0; i < n; i++) {
            soln = min(soln, a[i]);
            for (int j = i + 1; j < n; j++) {
                long long d = a[j] - a[i];
                soln = min(soln, d);
                if (k == 2) {
                    auto it = lower_bound(a.begin(), a.end(), d);
                    
                    if (it != a.end()) {
                        soln = min(soln, *it - d);
                    }

                    if (it != a.begin()) {
                        --it;
                        soln = min(soln, d - *it);
                    }
                }
            }
        }

        cout << soln << "\n";
    }
}

