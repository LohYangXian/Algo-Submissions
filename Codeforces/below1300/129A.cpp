//Cookies

/*
steal a bag so sum of remaining is even
0 remaining works too

find number of ways to steal exactly one bag
brute force o(n^2) way
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    vector<int> v{};

    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int res{};

    for (int i = 0; i < n; i++) {
        int sum{};    
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            sum += v[j];
        }
        if (sum % 2 == 0) res++;
    }

    cout << res;
}

