// Drinks

//ith value in list is percent orange juice in ith item

#include <iostream>
using namespace std;

int main() {
    int n;
    double total{};

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        total += x;
    }

    cout << total / n;
}