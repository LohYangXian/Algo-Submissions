//Jzzhu and Children

#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main() {
    int n;
    int m;
    deque<pair<int,int>> q{};
    int x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        q.push_back(pair{x, i});
    }

    while (q.size() > 1) {
        auto cur = q.front();
        cur.first -= m;
        if (cur.first > 0) {
            q.push_back(cur);
        }
        q.pop_front();
    }

    cout << q.front().second;
}