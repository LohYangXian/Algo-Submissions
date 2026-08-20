// The number of products

/*
given a sequence a1, a2, ... an , consisting of n non-zero integers

calc following values

(l,r) (  l <= r) such that al. al+1.... ar is negative
(l,r) ( l<= r) such that al * al+1 ... * ar is positive

n 
n integers elements in sequence

print two  integers, number of subsegments with -ve pdt
and number of subsegments with positive product

try O(n) soln or O(nlogn)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v{};
    v.push_back(0);
    long long numN = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x < 0) numN++;
        v.push_back(numN % 2);
    }

    long long num1 = 0;
    for (int i = 0; i < n + 1; i++) {
        if (v[i] == 1) num1++;
    }

    cout << num1 * ((n + 1) - num1) << " " << 1LL * n * (n + 1) / 2 - num1 * ((n + 1) - num1);
}