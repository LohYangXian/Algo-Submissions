// Scoring Subsequences

/*
score of a sequence [s1, s2, ... sd] is (s1 * s2 * .. sd / d!)

score of an empty sequence is 1

let m be max score among all subsequences. cost is defined
as max length of a subsequence with score of m

find the cost of sequence 

t cases 
n length
n integers (non decreasing order)

try o(n) soln

find the cost for each k = 1,2,..,,n

 
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v{};
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }

        int cost = 1;

        for (int i = 0; i < n; i++) {
            int candidate = cost + 1;

            if (candidate <= i + 1 &&
                v[i - candidate + 1] >= candidate) {
                cost++;
            }

            cout << cost << " ";
        }
        cout << "\n";
    }
}