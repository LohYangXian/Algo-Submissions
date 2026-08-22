//Queen

/*
root with vertices 1 to n 
tree, no cycles

n - 1 edges

if c = 1, i does not respect ancestors
if c = 0, i respects all

delete vertices one by one
select a non-root that doest no respect its parent and children
all do not respect it. Choose the one w the smallest number

all children of v becomes connected with the parent of V

stop once no vertices matching criteria, print order of
deletion 

order is unique!

n number of vertices
n lines of p and c: p is parent of vertex i, c = 0 or 1 for respect
root , p = -1, c = 0
*/

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int val;
    int parent;
    unordered_set<int> children;
    int respect;

    Node() : val(0), parent(0), respect(0) {}


    Node(int v, int p, int r) {
        val = v;
        parent = p;
        respect = r;
    }
};

int main() {
    int n;
    cin >> n;

    unordered_map<int, Node> m{};
    for (int i = 1; i <= n; i++) {
        m.emplace(i, Node(i, i, 0));
    }

    for (int i = 1; i <= n; i++) {
        int node = i;
        int p;
        cin >> p;
        int r;
        cin >> r;
        
        m[node].parent = p;
        m[node].respect = r;
        if (p != -1) m[p].children.insert(node);
    }

    vector<int> ans{};

    for (int i = 1; i <= n; i++) {
        int cur = i;
        if (m[cur].respect == 0) continue;
        bool toPurge = true;
        for (int child: m[cur].children) {
            if (m[child].respect == 0) {
                toPurge = false;
                break;
            }
        }
        if (toPurge == true) ans.push_back(cur);
    }

    for (int i: ans) {
        cout << i << " ";
    }
    if (ans.size() == 0) {
        cout << -1;
    }
}