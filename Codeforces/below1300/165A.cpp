//Supercentral Point

#include <iostream>
#include <vector>

using namespace std;

//1 supercentral point is if there exist a left, right, up , low neighbors

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    int x;
    int y;
    int res{};
    for (int i = 0; i < n; i ++) {
        cin >> x >> y;
        v.push_back(pair{x, y});
    }

    for (int i = 0; i < n; i++) {
        x = v[i].first;
        y = v[i].second;
        bool up{false};
        bool down{false};
        bool left{false};
        bool right{false};

        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int a = v[j].first;
            int b = v[j].second;

            if (a == x and b < y) down = true;
            if (a == x and b > y) up = true;
            if (a < x and b == y) left = true;
            if (a > x and b == y) right = true;

            if (down and up and left and right) res++;
        }

    }
    cout << res;

}