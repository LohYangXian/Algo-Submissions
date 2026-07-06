// Hungry Sequence

/*
n integers, elements are in increasing order, ai < aj for any i,j (i<J)

aj must not be divisible by ai

generate prime numbers? then skip the first n numbers

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m{10000000};
    int n;
    vector<int> v{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        v.push_back(m);
        m--;
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}