//Sail

/*

*/

#include <iostream>
using namespace std;

int main() {
    int n;
    int x;
    int y;
    int a;
    int b;

    cin >> n >> x >> y >> a >> b;
    pair<int, int> start{x,y};
    pair<int, int> end{a,b};
    
    char dir;
    for (int i = 0; i < n; i++) {
        if (start.first == end.first && start.second == end.second) {
            cout << i;
            return 0;
        }
        cin >> dir;
        pair<int, int> toMove{0,0};
        switch (dir) {
            case 'N':
                toMove.second++;
                break;
            case 'S':
                toMove.second--;
                break;
            case 'W':
                toMove.first--;
                break;
            case 'E':
                toMove.first++;
                break;
            default:
                break;
        }

        if ((abs(end.first - start.first) + abs(end.second - start.second)) < (abs(end.first - start.first - toMove.first) + abs(end.second - start.second - toMove.second))) {
            continue;
        } else {
            start.first += toMove.first;
            start.second += toMove.second;
        }
    }

    if (start.first == end.first && start.second == end.second) {
        cout << n;
    } else {
        cout << -1;
    }

}