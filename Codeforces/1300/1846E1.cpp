//Rudolf and Snowflakes (simple version)

/*
n <= 10^6 

initially the graph has only one vertex

then, more vertices are added to the graph

initial vertex is connected by edges to k new vertices (K > 1)

each vertex that is connected to only one other vertex is 
connected by edges to k more new vertices
this step is done at least once

help check if a snowflake with n vertices can exist 

sounds like a math qns
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        bool solved = false;
        for (long long i = 2; i <= sqrt(n); i++) {
            long long val = 1 + i + pow(i, 2);
            long long p = 3;
            while (val < n) {
                val += pow(i, p);
                p++;
            } 
            if (val == n) {
                cout << "YES" << "\n";
                solved = true;
                break;
            } 
        }
        if (solved == false) cout << "NO" << "\n";
    }
}