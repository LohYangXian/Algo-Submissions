//Team

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a;
    int b;
    int c;
    int res{};
    int count{};
    for (int i = 0; i < n; i++) {
        count = 0;
        cin >> a >> b >> c;
        count += a;
        count += b;
        count += c;
        if (count >= 2) res++;
    }
    cout << res;
}