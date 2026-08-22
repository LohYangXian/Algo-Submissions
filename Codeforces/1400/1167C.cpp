//News Distribution

/*
n users 
m groups of friends

x root
x sends news to friends

firends continue sending

find number of users that will know if root is x

n, m 
m lines, grp of friends

i think its a dfs question
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> parents;
vector<long long> sizes;

long long find(long long x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

bool unite(long long x, long long y) {

    long long a = find(x);
    long long b = find(y);
    if (a == b) return false;
    
    if (sizes[a] < sizes[b]) {
        swap(a, b);
    }

    parents[b] = a;
    sizes[a] += sizes[b];
    return true;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    parents.resize(n);
    sizes.resize(n);
    for (int i = 0; i < n; i++) {
        parents[i] = i;
        sizes[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<long long> temp{};
        for (int j = 0; j < k; j++) {
            long long member;
            cin >> member;
            temp.push_back(member);
        }
        for (int j = 1; j < k; j++) {
            unite(temp[j] - 1, temp[0] - 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << sizes[find(i)] << " ";
    }
}