//Riptide

/*
Count number of turns the game will last

1 2 3

*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;

        int turns = 0;
        while (a != b && b != c && a != c) {
            int largest;
            int smallest;
            if (a > b && a > c) {
                largest = 1;
            } else if (b > a && b > c) {
                largest = 2;
            } else {
                largest = 3;
            }

            if (a < b && a < c) {
                smallest = 1;
            } else if (b < a && b < c) {
                smallest = 2;
            } else {
                smallest = 3;
            }

            if (largest == 1) {
                a--;
            } else if (largest == 2) {
                b--;
            } else {
                c--;
            }

            if (smallest == 1) {
                a++;
            } else if (smallest == 2) {
                b++;
            } else {
                c++;
            }

            turns++;
        }
        cout << turns << "\n";
    }
}