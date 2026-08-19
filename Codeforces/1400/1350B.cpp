//Orac and Models

/*
there are n models numbered from 1 to n, with sizes s1, s2, ... sn

buy some of the models and arrange them in order of increasing numbers
indices not sizes


strictly increasing index order
and adj pairs must be divisible (all same multiples)
and the a[j] < a[j + 1], which means that the values must be in strictly increasing
order as well

ij+1 is divisible by ij
and sij < sij+1

find maximum number of models that he can buy

and he will ask the queries many times

t cases 
n nmodels
n integers of sizes

try O(n) soln find the longest subarray that is legitimate
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
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        vector<long long> dp(n, 1);
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 2 * i; j <= n; j+=i) {
                if (v[i - 1] < v[j - 1]) {
                    dp[j - 1] = max(dp[j - 1], dp[i - 1] + 1);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}