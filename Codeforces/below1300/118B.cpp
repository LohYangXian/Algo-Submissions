// Present from Lena

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    int size = (2 * n) + 1;
    for (int i = 0; i < n; i++) {
        int peak = i;
        vector<int> level(size);
        level[n] = peak;
        int l = n - 1;
        int r = n + 1;
        int cur = peak - 1;
        while (l >= 0) {
            level[l] = cur;
            level[r] = cur;
            cur -= 1;
            l--;
            r++;
        } 
        v.push_back(level);
    }

    for (int i = n; i >= 0; i--) {
        int peak = i;
        vector<int> level(size);
        level[n] = peak;
        int l = n - 1;
        int r = n + 1;
        int cur = peak - 1;
        while (l >= 0) {
            level[l] = cur;
            level[r] = cur;
            cur -= 1;
            l--;
            r++;
        } 
        v.push_back(level);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (v[i][j] >= 0) {
                cout << v[i][j];
                if (v[i][j] == 0 && j >= n && j < size - 1) {
                    break;
                }
            } else {
                cout << " ";
            }
            if (j != size - 1) {
                cout << " ";
            }
        }
        if (i != size - 1) cout << "\n";

    }
}