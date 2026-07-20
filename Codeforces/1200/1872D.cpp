//Plus Minus Permutation

/*
3 integers - n, x ,y

p1, p ..... , pn

(p1x + p2x + ... + _ ) -  (p1y + p2y + ... + )

score of a permutation is the sum of pi for all indices i divisible by x
minus the sum of pi for all indices i divisible by y

t number of test cases
n number of integers, x , y
output a single integer, max score among all permutations of length n

* rearrange the n integers such that u max the value of 
the formula
px - py 

7 6 5 4 3 2 1

1 2 3 4 5 6 7
- 1 - 1 - 1 -
- - 0 - - 0 -

7 + 6 + 5 - 1 - 5 

12

*/
#include <iostream>
#include <numeric> // gcd
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        long long lcm = x / gcd(x, y) * y;

        long long both = n / lcm;
        long long numAdds = n / x - both;
        long long numMinus = n / y - both;

        // Sum of largest numAdds numbers:
        // n + (n-1) + ... + (n-numAdds+1)
        long long addSum =
            n * (n + 1) / 2 -
            (n - numAdds) * (n - numAdds + 1) / 2;

        // Sum of smallest numMinus numbers:
        // 1 + 2 + ... + numMinus
        long long minusSum =
            numMinus * (numMinus + 1) / 2;

        cout << addSum - minusSum << '\n';
    }
}