// Kitahara Haruki Gift
/*
n apples, divide all apples between friends
total weight given to Touma must be = to total weight given to ogiso
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    int sum{};
    unordered_map<int,int> m{};
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
        sum += x;
    }

    if (sum % 200 == 0 && (m[200] % 2 == 0 || m[100] >= 2))
        cout << "YES";
    else
        cout << "NO";
}