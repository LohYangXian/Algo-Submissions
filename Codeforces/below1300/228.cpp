// Is your horseshoe on the other hoof?
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,int> m;
    for (int i = 0; i < 4; i ++) {
        int x{};
        cin >> x;
        m[x]++;
    }
    cout << (4 - m.size());
}
