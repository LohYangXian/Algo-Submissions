//Shocking Arrangement

/*

array consisting of integers such that a1 + a2
+ a3 + ... an = 0

rearrange the elements such that 

max |al + al+1 + ... ar | < max(a1, a2, a3, ... an)
- min(a1, a2, ... an)

sliding window i think

determine if there exist a permutation such that
the condition is satisfied and find the corresponding
array

sum of array a is ZERO (NOTE THIS DOWN)

t cases
n 
n integers

n <= 300000, try a O(n) or O(nlogn) solution

print no or yes followed by the arrangement

maybe dont put all the same sign together? if u alternate them
itll be okay, but if u cant alt them anymore, then check
if it exceeds via sliding window

3 4 
-2 -5

9

4
-3 -3 1 1 1 1 1 1

we shld make use of how sum of all = 0, like what
kinda hint is this

-8 -7 3 3 4 5

13

-8 -7
5 4 3 3

5 4 3 -8 3 -7 

16

-9 7 5 -8 -4 4 3 2 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        long long maximum = v[0];
        long long minimum = v[0];
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, v[i]);
            minimum = min(minimum, v[i]);
        }
        
        long long curSum = 0;
        long long target = maximum - minimum;
        int l = 0;
        int r = n - 1;
        vector<long long> soln;

        if (target == 0) {
            cout << "No\n"; 
            continue; 
        }
        while (l <= r) {
            if (curSum >= 0) {
                curSum += v[l];
                soln.push_back(v[l]);
                l++;
            } else {
                curSum += v[r];
                soln.push_back(v[r]);
                r--;
            }
        }

        if (soln.size() < n) {
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
            for (long long i: soln) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}