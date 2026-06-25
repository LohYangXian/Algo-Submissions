// The number of positions

#include <iostream>
using namespace std;

int main() {
    int n;
    int a;
    int b;
    cin >> n >> a >> b;

    int res{};
    int front{};
    int back{};
    for (int i = 1; i <= n; i++) {
        front = i - 1;
        back = n - i;
        if (front >= a && back <= b) res++;
    }
    cout << res;
}