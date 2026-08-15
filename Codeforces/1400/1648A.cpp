//Weird Sum

/*
n x m

lines numbered from 1 to n
and columns numbered from 1 to m

each cell has a color, int from 1 to 
10^5

manhatten dist between 2 cells as length of shortest 
path between them where each consecutive
cells in path must have a common side?

Move along the axis no diagnonal moves

find the sum of manhattan distances between
each pair of cells of same color

n and m 

*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    long long n; long long m;
    cin >> n >> m;

    unordered_map<long long, pair<vector<long long>, vector<long long>>> map{};

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            long long x;
            cin >> x;

            map[x].first.push_back(i);
            map[x].second.push_back(j);
        }
    }

    for (auto& [key, value]: map) {
        sort(value.first.begin(), value.first.end());
        sort(value.second.begin(), value.second.end());
    }

    long long total = 0;

    for (auto& [key, value]: map) {
        for (int i = 0; i < value.first.size(); i++) {
            total += (value.first[i] * i);
            total -= (value.first[i] * (value.first.size() - i - 1));
        }

        for (int i = 0; i < value.second.size(); i++) {
            total += (value.second[i] * i);
            total -= (value.second[i] * (value.second.size() - i - 1));
        }
    }

    cout << total;
}