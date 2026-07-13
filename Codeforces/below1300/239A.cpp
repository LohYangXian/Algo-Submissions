// Two Bags of Potatoes

/*
first bag x potatoes
second bag y potatoes

x+y <= n and x + y % k == 0

find x

print all possible values of x
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int y;
    int k;
    int n;

    int remainder;

    cin >> y >> k >> n;
    remainder = n - y;

    int start = k - (y % k);

    vector<int> v{};
    for (int i = start; i <= remainder; i+=k) {
        if (i == 0) continue;
        v.push_back(i);
    }

    if (v.size() == 0) {
        cout << -1;
    } else {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            cout << " ";
        }
    }
    
}