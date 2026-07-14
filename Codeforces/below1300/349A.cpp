// Cinema Line

/*
n people standing in a hige line
100, 50, 25 ruble bill
a ticket cost 25 rubles

can the clerk sell a ticket to each person and give change if he 
sells tickets strictly in order?

brute force? always give the big bills first
*/

#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    unordered_map<int,int> m{};
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;

        // Get change here
        if (x == 100) {
            if (m[50] >= 1 && m[25] >= 1) {
                m[50] -= 1;
                m[25] -= 1;
            } else if (m[25] >= 3) {
                m[25] -= 3;
            } else {
                cout << "NO";
                return 0;
            }
        } else if (x == 50) {
            if (m[25] >= 1) {
                m[25] -= 1;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}