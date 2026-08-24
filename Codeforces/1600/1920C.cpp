//Partitioning the Array

/*
array

k positive integer
divisor of n

partitions array into  n / k disjoint subarrays of length k

earns one point if there exists some positive int m (m>=2)
such that if he replaces every element in the array with
its remainder when divided by m, all subarrays identital

t cases
n length
n integers

output number of points allen will earn

find O(n) solution
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v{};
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        vector<long long> factors{};
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (n / i != i) factors.push_back(n / i);
            } 
        }

        long long count = 0;
        
        for (int i: factors) {
            long long totalDenom = 0;
            for (int j = 0; j < i; j++) {
                long long denom = 0;
                for (int k = 1; k < n / i; k++) {
                    denom = gcd(denom, abs(v[k * i + j] - v[j]));
                }
                totalDenom = gcd(totalDenom, denom);
            }
            if (totalDenom != 1) count++;
        }
        cout << count << "\n";
    }
}

