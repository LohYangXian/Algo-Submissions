//Cat Cycle

/*
2 cats,
A and B

n napping spots where both cats usually sleep

cat A changes napping in order: n, n-1, n-2, n... 3, 2, 1, n, n-1
cat B: 1,2,3,4,... , n-1, n, 1,2, ... 

cat B is much younger, A and B dont lie together
if both cats go in spot x then A takes this place
and B moves to the next place in its order 

B wont return to the skipped spot x after A frees it

where will B be at hour k

t cases

n and k

try for a O(1) soln
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;

        long long moves = k - 1;

        if (n % 2 == 1) {
            long long gap = n / 2;
            moves += moves / gap;
        }

        cout << moves % n + 1 << '\n';
    }
}