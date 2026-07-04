// Jeff and Periods

/*
a1 a2 a3 .. an
x occurs in sequence a 
consider all positions of number x in sequence a . numbers sorted in increasing order 


*/

#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    map<int, pair<int, int>> m{};
    unordered_set<int> exclude{};
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (exclude.find(x) != exclude.end()) continue;
        if (m.find(x) == m.end()) m[x] = pair{i,0};
        if (m[x].second != 0 && i - m[x].first != m[x].second) {
            m.erase(x);
            exclude.insert(x);
            continue; 
        }
        m[x] = pair{i, i - m[x].first};
    }
    
    cout << m.size() << "\n";
    
    for (auto [key, value]: m) {
        cout << key << " " << value.second << "\n";
    }
}
