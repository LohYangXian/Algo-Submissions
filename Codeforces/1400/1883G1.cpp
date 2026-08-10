//Dances (Easy Version)

/*
two arrays of integers

a1 a2, .. an
b1 b2, .. bn

you can reorder the elements of each array as you wish

if arrays not empty, you will perform both of following actions

choose any element from array a and remove it 
choose any element from array b and remove it

let k be final size, you need to find the minimum number of operations required to satisfy 
ai < bi
for all 1 <= i <= k

given integer m, find the sum of answers to the problem for m pairs of arrays (c[i], b),
where 1 <= i <= m

m pairs of arrays , where 1 <= i <= m,

c[i]1 = i
c[i]j = aj

t cases
n, m = 1

O(n * t)?

soln for each case shld be O(n)

get the min removals for all pairs of arrays

4 3 3 2 2 1 1
1 1 1 1 3 3 3 3

1 1 1 2  
3 3 3 3

1 1 5 
3 3 8

9 2 8 3 7 4 6 5
1 2 3 2 1 4 5 6 5

9 1
9 2 8 3 7 4 6 5
1 2 3 2 1 4 5 6 5

5 6 7 8 9
6

if la >= lb, lb ++ 
if la < lb, res++, la++ , lb++

2 3 4 5, n - 5 = 4

1 2 3 4 5
L       R

3 4 5 5 6
L       R

for a, remove from the back
for b, remove from the front

how to check after each op? 
keep a l,r for both array

La, Ra
Lb, Rb

while Lb <= La and Rb <= Ra: remove



*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >> n >> m;
        vector<long long> a{};
        vector<long long> b{};

        a.push_back(1);
        for (int i = 1; i < n; i++) {
            long long x;
            cin >> x;
            a.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            b.push_back(x);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int la = 0;
        int lb = 0;

        int res = 0;

        while (la < n && lb < n) {
            if (a[la] >= b[lb]) {
                lb++;
            } else {
                res++;
                la++;
                lb++;
            }
        }        

        cout << n - res << "\n";
    }
}