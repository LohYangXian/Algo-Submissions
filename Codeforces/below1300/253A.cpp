// Boys and Girls

/*
n boys and m girls
alternate as much as possible

indexed from left to right by numbers from 1 to n + m
*/

#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int m;
    string ans{};

    cin >> n >> m;
    bool curBoy;

    if (n >= m) {
        curBoy = true;
    } else {
        curBoy = false;
    }

    while (n != 0 && m != 0) {
        if (curBoy == true) {
            ans += 'B';
            n -= 1;
        } else {
            ans += 'G';
            m -= 1;
        }
        curBoy = !curBoy;
    }

    if (n > 0) {
        ans += string(n, 'B');
    }

    if (m > 0) {
        ans += string(m, 'G');
    }

    cout << ans;
}