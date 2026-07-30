//Gardener and the Array

/*
n integers

check if there are two different subsequences a and b of the original array
for f(a) = f(b), f(x) is the bitwise OR of all numbers in the sequence x

subsequences are diff if the set of indexes are different 
Yes. In fact, they are allowed to overlap completely except that they cannot be the exact same subsequence (same set of indices).

t cases
n size

k, number of set bits in number ci
k distinct integers, numbers of bits that are set to one in number c

k_i how many bits are set to 1 in c_i
next k_i integers tell you which bit positions are 1


*/

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        unordered_map<int, int> freq{};
        vector<vector<int>> v{};
        int x;
        cin >> n;
        for (int i = 0; i < n; i++) {
            vector<int> c{};
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> x;
                freq[x]++;
                c.push_back(x);
            }
            v.push_back(c);
        }

        bool ansGiven = false;

        for (int i = 0; i < v.size(); i++) {
            bool isSolved = true;
            for (int j = 0; j < v[i].size(); j++) {
                if (freq[v[i][j]] == 1) {
                    isSolved = false;
                    break;
                }
            }
            if (isSolved == true) {
                cout << "Yes" << "\n";
                ansGiven = true;
                break;
            }
        }

        if (ansGiven == false) {
            cout << "No" << "\n";
        }

    }
}