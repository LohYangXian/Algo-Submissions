//Split into two sets

/*
set of n (even) dominoes
Each dominoe contains two integers from 1 to n

can he divide all dominoes into two sets
so that all numbers on the dominoes of each set are different

each dom must go into exactly one of two set

t cases
n integer
n lines, pairs of numbers ai and bi
try O(n) or O(n log n)

yes if possible
no if not possible
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> adjList;
vector<int> color;
vector<int> visited;
bool dfs(int node, int curColor) {
    visited[node] = 1;
    color[node] = curColor;

    for (int next: adjList[node]) {
        if (!visited[next]) {
            if (!dfs(next, 1 - curColor)) {
                return false;
            }
        } else if (color[next] == color[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        adjList.assign(n + 1, {});
        color.assign(n + 1, -1);
        visited.assign(n + 1, 0);
        vector<int> degree(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }
        bool solved = true;

        for (int i = 1; i <= n; i++) {
            if (degree[i] > 2) {
                solved = false;
            }
        }
        
        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {
                if (!dfs(i, 0)) {
                    solved = false;
                    break;
                }
            }
        }

        if (solved == false) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}