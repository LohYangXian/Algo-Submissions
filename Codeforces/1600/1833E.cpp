//Round Dance

/*
n people came to festival

2 people in round dance, each person has 2 neighbors

how manyt dances were there. each participant rmbred one neighbor
determine min and max of round dances

2 1 4 3 6 5

number of groups

t cases
n number of ppl

n integers of number of neighbor that ith person rmbred beside him

O(n) soln or O(n log n)

min and max

ufds will find the max grps
for min grps, we need to count number of closed grps, becos the
open grps can be merged into 1, to do that, just do a dfs?
*/

#include <vector>
#include <unordered_set>
#include <cmath>
#include <iostream>
using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x - 1] == x) {
        return x;
    }

    parent[x - 1] = find(parent[x - 1], parent);
    return parent[x - 1];
}

bool unite(int x, int y, vector<int>& parent, vector<int>& size) {
    int a = find(x, parent);
    int b = find(y, parent);
    if (a == b) return false;
    if (size[b - 1] > size[a - 1]) {
        swap(a,b);
    }
    parent[b - 1] = a;
    size[a - 1] += size[b - 1];
    return true;
}

bool dfs(int node, int prev, vector<vector<int>>& adjList, vector<int>& visited) {
    if (visited[node - 1] == 1) return true;

    if (visited[node - 1] == 2) return false;

    visited[node - 1] = 1;
    for (int neighbor: adjList[node - 1]) {
        if (neighbor == prev) continue;
        if(dfs(neighbor, node, adjList, visited)) return true;
    }
    visited[node - 1] = 2;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> parent(n);
        for (int i = 1; i <= n; i++) {
            parent[i - 1] = i;
        }
        vector<int> size(n, 1);
        vector<vector<int>> adjList(n, vector<int>{});
        unordered_set<int> set;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            adjList[x - 1].push_back(i);
            adjList[i - 1].push_back(x);
            unite(x, i, parent, size);
        }
        for (int i = 0; i < n; i++) {
            set.insert(find(i + 1, parent));
        }
        int maximum = set.size();
        int closedLoops = 0;
        vector<int> visited(n);

        for (int node: set) {
            if (dfs(node, -1, adjList, visited)) closedLoops++; 
        }

        int minimum = min(closedLoops + 1, maximum);
        // cout << closedLoops << "\n";
        cout << minimum << " " << maximum << "\n"; 
    }
}



