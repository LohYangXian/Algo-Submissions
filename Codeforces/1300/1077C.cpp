//Good Array

/*
Good array if there is an element in the array
that equals to sum of all other elements

a = [1,3,3,7] is good if 
elem a4 = 7 equals to sum of all other elements

print all indices j of this array such that after removing
j , it will be good

you have to remove all independently 

print k , number of indices j ,
print k integers in any order
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> pre(n);
    vector<long long> suf(n);
    vector<long long> v{};

    vector<int> answers{};

    unordered_map<long long, vector<int>> indices{};

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        indices[x].push_back(i);
        v.push_back(x);
    }

    for (int i = 1; i < n; i++) {
        pre[i] = (pre[i - 1] + v[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = (suf[i + 1] + v[i + 1]);
    }

    long long res{};

    for (int i = 0; i < n; i++) {
        long long remaining = pre[i] + suf[i];
        
        if (remaining % 2 == 0) {
            long long target = remaining / 2;

            if (indices.find(target) != indices.end() && (v[i] != target || indices[target].size() > 1)) {
                answers.push_back(i + 1);
                res++;
            }
        }
    }

    cout << res << "\n";

    for (int i: answers) {
        cout << i << " ";
    }
}