//Spying on the Beaver

/*
rooted tree* with n vertices, numbered 1 to n
vertex numbered 1 is root

starts from root, travel to each dam located at vertices
numbered a1, ... am

determine which of these m vertices beaver went

place camera on edge of tree. if beaver traverse an edge w 
a camera, u will c this

sequence of edges with cameras , beaver was observed passing

min number of cameras to dteremine his destination

state min necessary number of cameras k and edges they shld be placed


t cases

n integers
n - 1 parents of vertices from 2nd to nth

m number of vertices containing beaver dams

m integers , numbers of these vertcies

output k 
in same line, output output the vertex u

do a O(n) soln

*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> children;
vector<bool> isDam;
vector<int> ans;

bool dfs(int u) {
    vector<int> dChildren{};

    for (int v: children[u]) {
        if (dfs(v)) {
            dChildren.push_back(v);
        }
    }

    if (isDam[u]) {
        for (int v: dChildren) {
            ans.push_back(v);
        }
    } else {
        for (int i = 0; i + 1 < (int)dChildren.size(); i++) {
            ans.push_back(dChildren[i]);
        }
    }

    return isDam[u] || !dChildren.empty();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        children.assign(n + 1, {});

        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;

            children[p].push_back(i);
        }

        int m;
        cin >> m;

        isDam.assign(n + 1, false);

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;

            isDam[x] = true;
        }

        ans.clear();

        dfs(1);

        cout << ans.size();

        for (int x: ans) {
            cout << " " << x;
        }

        cout << "\n";
    }
}