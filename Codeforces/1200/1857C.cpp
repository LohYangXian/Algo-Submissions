// Assembly via Minimums

/*
array a of n integers

for all i,j (i<j), he wrote min value of ai and aj

b of size n*(n-1) / 2

a = [2,3,5,1]
[min(2,3), min(2,5), min(2,1), min(3,5), min(3,1), min(5,1)]

^ O(n^2) to compile this

restore array a from b

t = number of tests, 
n - length of array a
n*(n-1) / 2 integers of b

[1 3 1]

0,1 0,2 1,2



size = (n)(n-1) / 2
1 1 3

1 3 4

3 3 3 5 5 7

3 5 7 8

3 3 3 5 5 7

-2 -2 -2 -2 0 0 0 0 0 3
-2 0 0 3 4

1 1 3
1 3 4

10 11

3 3 3 5 5 7

2 2 2 2 2 2 2 2 2 2


*/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long size = (n * (n - 1) / 2);
        vector<long long> v{};
        long long x;
        for (int i = 0; i < size; i++) {
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        long long pointer{};
        while (pointer < size) {
            cout << v[pointer]  << " ";
            n--;
            pointer += n;
        }

        cout << v[size - 1] << "\n";
    }
}
