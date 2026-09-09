//Monocarp and Projects

/*
k months
first month, x employees

y projects to do

in each next month

number of employees and number of projects  increase
by 1

in month i (0 <= i < k) , company has x + i employees
and has to complete y + i projects

each employee must receive the same number of 
projects, each proj can be assigend to at most 
one employee

monocrap completes all unassigned projects himself
give me the least as possdible

so maybe projects / employee, then 
monocarp gets projects % employee

find total number of projects he complete 
over the next k months

t cases
x , y, k

k is 10^12, so we cannot calc in O(n), 
find a smart O(1) way to solve it

sum of y does not exceed 10^6, maybe do that? 
*/
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        long long y;
        long long k;
        cin >> x >> y >> k;
        long long d = y - x;

        long long limit = min(x + k - 1, d);
        long long ans = k * d;
        long long l = x;
        while (l <= limit) {
            long long q = d / l;
            long long r = min(limit, d / q);
            long long count = r - l + 1;
            long long sum = (l + r) * count / 2;
            ans -= q * sum;
            l = r + 1;
        }

        cout << ans << "\n";
    }
}