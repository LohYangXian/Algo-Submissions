//Shooshuns and sequence

#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;

int main() {
    deque<int> q{};
    int n;
    int k;

    cin >> n >> k;
    int x;

    unordered_map<int,int> freq{};
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push_back(x);
        freq[x]++;
    }

    for (int i = 0; i < 2 * n; i++) {
        if (freq.size() <= 1) {
            cout << i;
            return 0;
        } 

        int cur = q[k - 1];
        q.push_back(cur);
        freq[cur]++;
        freq[q.front()]--;
        if (freq[q.front()] == 0) freq.erase(q.front());
        q.pop_front(); 
    }

    cout << -1;
}