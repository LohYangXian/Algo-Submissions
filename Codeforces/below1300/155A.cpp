// I love username

#include <iostream>
using namespace std;

int main() {
    int curMax{};
    int curMin{};

    int n;
    int x;
    cin >> n;
    int res{};
    cin >> x;
    curMax = x;
    curMin = x;
    
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x > curMax) {
            res++;
            curMax = x;
        } else if (x < curMin) {
            res++; 
            curMin = x;
        }
    }
    cout << res;
}