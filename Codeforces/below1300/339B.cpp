// Xenia and Ringroad
/*
n houses, numbered 1 to n in clockwise order
start from house 1, m things to do

4 3
3 2 3

4 houses, 3 tasks. to do the 1st task, she needs to be in house number 3, and complete all tasks with numbers lesser than 1
to do 2nd task, she needs to be in house 2, and complete all tasks with numbers lesser than 2
to do 3rd task, she needs to be in house 3, and complete all tasks with numbers lesser than 3

think of it as a brute force round robin
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    long long res{};
    int cur{1};


    cin >> n >> m;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        res += ((x - cur + n) % n);
        cur = x;
    }
    cout << res;
}