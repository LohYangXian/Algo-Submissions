// Airport

/*
plane has x empty seats, ticket cost x units

n passengers, m number of planes
next line has m integers , for number of empty seats in ith plane
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int> pq{};
    priority_queue<int> minpq{};
    int n;
    int m;
    cin >> n >> m;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        pq.push(x);
        minpq.push(-x);
    }

    int resMin{};
    int resMax{};
    int cur;
    for (int i = 0; i < n; i++) {
        cur = pq.top();
        resMax += cur;
        pq.pop();
        cur--;
        if (cur > 0) pq.push(cur);
    }

    for (int i = 0; i < n; i++) {
        cur = -minpq.top();
        resMin += cur;
        minpq.pop();
        cur --;
        if (cur > 0) minpq.push(-cur);
    }

    cout << resMax << " " << resMin;
}