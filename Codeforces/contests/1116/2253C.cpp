//Sum of distinct values in a matrix

/*
n rows m cols

all elements equal 0

2 arrays of 

a  = [a1, a2, ax... ]
b = [b1, b2... by]

strictly increasing (rmbr this!)

any number of ops

1. choose a number c from array a and a row of the matrix , set every element
in this row to c

2. choose  a number d from array b  and a col of matrix
set every element in this col to d

cost of a matrix is the sum of all distinct numbers that
occur in it at least once
find the max possible cost of the matrix


try (m + n) soln
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        int x;
        int y;
        cin >> n >> m >> x >> y;

        vector<long long> a{};
        for (int i = 0; i < x; i++) {
            long long x;
            cin >> x;
            a.push_back(x);
        }

        vector<long long> b{};
        for (int i = 0; i < y; i++) {
            long long x;
            cin >> x;
            b.push_back(x);
        }

        long long res = 0;

        int pointerA = x - 1;
        int pointerB = y - 1;

        int usedA = 0;
        int usedB = 0;
        int total = 0;

        int totalLimit = n + m - 1;

        while ((pointerA >= 0 || pointerB >= 0) && total < totalLimit) {
            if (pointerA >= 0 && pointerB >= 0) {
                if (a[pointerA] == b[pointerB]) {
                    res += a[pointerA];
                    total++;

                    pointerA--;
                    pointerB--;
                }
                else if (a[pointerA] > b[pointerB]) {
                    if (usedA < n) {
                        res += a[pointerA];
                        usedA++;
                        total++;
                    }
                    pointerA--;
                }
                else {
                    if (usedB < m) {
                        res += b[pointerB];
                        usedB++;
                        total++;
                    }
                    pointerB--;
                }
            }
            else if (pointerA >= 0) {
                if (usedA < n) {
                    res += a[pointerA];
                    usedA++;
                    total++;
                }
                pointerA--;
            }
            else {
                if (usedB < m) {
                    res += b[pointerB];
                    usedB++;
                    total++;
                }
                pointerB--;
            }
        }
        cout << res << '\n';
    }
}