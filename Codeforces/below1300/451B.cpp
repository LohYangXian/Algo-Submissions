// Sort the Array

/*
array a consisting of n distinct integers

isit possible to sort the array a in increasing order
by reversing exactly one segment of a? 
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b = a;
    sort(b.begin(), b.end());

    int l = 0;
    while (l < n && a[l] == b[l]) l++;

    if (l == n) {
        cout << "yes\n1 1";
        return 0;
    }

    int r = n - 1;
    while (r >= 0 && a[r] == b[r]) r--;

    reverse(a.begin() + l, a.begin() + r + 1);

    if (a==b) {
        cout << "yes\n";
        cout << l + 1 << " " << r + 1;
    } else {
        cout << "no";
    }

}