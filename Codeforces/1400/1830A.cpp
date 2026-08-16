//Copil Copac Draws Trees

/*
n-1 edges describing a tree of n vertices
Step 0: draw vertex 1
1: for every edge, in order, if edge connects alr drawn vertex u to undrawn v,
draw undrawn v and edge

2: if all vertices drawn, terminate the algo, else go to step 1

find number of readings (step 1) required to draw the tree

t cases
n vertices
n - 1 lines of u and v

O(n) solution

are u sure this is not a set question? 

set(n), delete slowly
*/

#include <vector>
#include <iostream>
using namespace std;


int dfs(int node, int parent, int prevEdge, int count, vector<vector<pair<int, int>>>& adj) {
    int ans = count;

    for (auto [next, edgeIdx] : adj[node]) {
        if (next == parent) continue;

        int nextCount = count;

        if (edgeIdx < prevEdge) {
            nextCount++;
        }

        ans = max(ans, dfs(next, node, edgeIdx, nextCount, adj));
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<pair<int,int>>> adj(n + 1);
        for (int i = 1; i <= n - 1; i++) {
            int u;
            int v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        
        cout << dfs(1, -1, 0, 1, adj) << "\n";
    }
}