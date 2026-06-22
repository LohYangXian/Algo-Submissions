// Jeff and Digits
// 5 : 2 , 0 : 2
// 5500 

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    unordered_map<int, int> freq;
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        freq[x]++;
    }

    int usable5 = (freq[5] / 9) * 9;

    if (freq[0] == 0) {
        cout << -1;
    } else if (usable5 == 0) {
        cout << 0;
    } else {
        cout << string(usable5, '5') << string(freq[0], '0');
    }
}