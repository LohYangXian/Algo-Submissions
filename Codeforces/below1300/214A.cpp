//System of Equations

/*
how many pairs of integers (a,b) which satisfy the system

A single line contains n,m 

a2 + b = 9
a + b2 = 3
*/ 
#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;

    int res{};

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i * i + j == n && i + j * j == m) {
                res++;
            }
        }
    }
    cout << res;
}