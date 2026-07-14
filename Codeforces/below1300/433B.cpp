//Kuriyama Mirai's Stones 

/*
n stones

1 to n

cost of ith stone is V

l and r, sum up v from lth to rth positions

u = cost of ith cheapest stone, l , r and give sum again (sort in non-decreasing order)
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {


    int n;
    int x;
    cin >> n;

    vector<int> v{};
    vector<int> sv{};
    vector<long long> preV(n,0);
    vector<long long> preSV(n,0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        sv.push_back(x);
    }

    sort(sv.begin(), sv.end());
    int m;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            preV[i] += v[i];
            preSV[i] += sv[i];
            continue
        }
        preV[i] += v[i];
        preV[i] += preV[i - 1];

        preSV[i] += sv[i];
        preSV[i] += preSV[i - 1];
    }

    cin >> m;
    int l;
    int r;
    int t;
    for (int i = 0; i < m; i++) {
        cin >> t >> l >> r;
        if (t == 1) {
            long long left;
            if (l == 1) {
                left = 0;
            } else {
                left = preV[l - 2];
            }
            cout << preV[r - 1] - left << "\n"; 
        } else {
            long long left;
            if (l == 1) {
                left = 0;
            } else {
                left = preSV[l - 2];
            }
            cout << preSV[r - 1] - left << "\n";
        }  
    }
}