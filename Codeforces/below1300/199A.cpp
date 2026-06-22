// Hexadecimal's theorem

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v{0,1};
    
    while (v.back() < n) {
        int sz = v.size();
        v.push_back(v[sz - 1] + v[sz - 2]);
    }

    if (n == 0) 
        cout << "0 0 0";
    else if (n == 1)
        cout << "0 0 1";
    else cout << v[v.size() - 2] << " " << v[v.size() - 3] << " " << 0;
}