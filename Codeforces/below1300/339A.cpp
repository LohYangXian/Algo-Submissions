// Helpful Maths
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> v(3);
    char x;

    while (cin >> x) {
        switch(x) {
            case '1':
                v[0]++;
                break;
            case '2':
                v[1]++;
                break;
            case '3':
                v[2]++;
                break;
            case '+':
                break;
        }
    }
    string res{};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v[i]; j++) {
            res += to_string(i + 1);
            res += '+';
        }
    }
    res.pop_back();
    cout << res;
}