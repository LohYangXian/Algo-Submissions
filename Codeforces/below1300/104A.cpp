//Blackjack

/*
number of ways to get n given first card is queen of spades
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,int> m{
        {1, 4},
        {2, 4},
        {3, 4},
        {4, 4},
        {5, 4},
        {6, 4},
        {7, 4},
        {8, 4},
        {9, 4},
        {10, 15},
        {11, 4}
    };

    int n;
    cin >> n;
    if (m.find(n - 10) == m.end()) {
        cout << 0;
    } else {
        cout << m[n - 10];
    }
}