//Mahmoud and Ehab and the bipartiteness

/*
tree consisting of n nodes, asked them to add edges that the
graph is still bipartite

what is the max number of edges they can add

n nodes
n- 1 integers u and v (edges)


*/
#include <vector>
#include <iostream>
using namespace std;

int n;
vector<vector<int>> adjList;
vector<int> visited;
long long black = 0;
long long white = 0;

void dfs(int node, int prevNode, int prevColor) {
    if (visited[node] == 1 || node == prevNode) {
        return;
    } 

    int nextColor;
    visited[node] = 1;

    if (prevColor == 1) {
        white++;
        nextColor = 0;
    }  else {
        black++;
        nextColor = 1;
    }

    for (int nei: adjList[node]) {
        dfs(nei, node, nextColor);
    }
}

int main() {
    cin >> n;
    adjList.resize(n);
    visited.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u;
        int v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
        adjList[v - 1].push_back(u - 1);
    }

    dfs(0, -1, 1);

    cout << black * white - (n - 1);

}