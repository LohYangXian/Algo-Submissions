// White-Black Balanced Subtrees

/*
rooted tree consisting of n vertices numbered 1 to n

the root is vertex 1

string s denoting color of each vertex

B black, W white, subtree is balanced if W = B

count number of balanced subtrees


*/

#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> children;
string colors;
long long res;

int dfs(int i) {
    int score = (colors[i] == 'B' ? 1:-1);

    for (int child: children[i]) {
        score += dfs(child);
    }

    if (score == 0) {
        res++;
    }

    return score;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        children.assign(n, {});
        
        res = 0;

        for (int node = 1; node < n; node++) {
            int parent;
            cin >> parent;

            parent--;
            children[parent].push_back(node);
        }

        cin >> colors;

        dfs(0);

        cout << res << "\n";
    }    
}