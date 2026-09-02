//Triangle Coloring

/*
undirected graph consisting of n vertices and n edges

n is divisible by 6 (NOTE THIS)

each edge has a weight > 0

split into n / 3 triples of vertices
first vertices 1,2,3 , second 4,5,6 so on

every pair of vertices from the same triple is
connected by an edge

no edges between triples

paint the vertices into red n blue
each vertex have exactly one color, n / 2 red and
n / 2 blue

weight of coloring is sum of weights of diff colors

W is maximum possible weight of valid coloring
calc number of valid colorings with weight W,
print modulo 998244353

find the number of valid combinations with weight
W, where W is max weight

n
n weights
*/

#include <iostream>
using namespace std;

long long MOD = 998244353LL;

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;

    long long ans = 1;
    long long triangles = n / 3;
    long long k = triangles / 2;
    for (long long i = 1; i <= k; i++) {
        ans = ans * (triangles - i + 1) % MOD;
        ans = ans * power(i, MOD - 2) % MOD;
    }

    for (int i = 0; i < n / 3; i++) {
        long long a; long long b; long long c;
        cin >> a >> b >> c;
        long long combinations = 0;
        if (a != b && b != c && a != c) {
            combinations = 1;
        } else if (a == b && b == c && a == c) {
            combinations = 3;
        } else {
            if ((a == b && c > a) || (a == c && b > a) || (b == c && a > b)) {
                combinations = 2;
            } else {
                combinations = 1;
            }
        }
        ans *= combinations;
        ans %= MOD;
    }
    cout << ans;
}