//Friends and the Restaurant

/*
n friends

x burles, y burles

each day, some group of >= 2 visits restaurant
they do not visit more than once

total budget of each grp must be >= amt of burles 
that friends r gg to spend

sum of x <= sum of y
max number of days friends can visit the res

t 
n
[x, x, ,x ]
[y ,y , y]


*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        vector<int> Xs{};
        vector<int> Ys{};
        vector<int> diffs{};

        int n;
        int x;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            Xs.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            Ys.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            diffs.push_back(Ys[i] - Xs[i]);
        }

        sort(diffs.begin(), diffs.end());
        int l{};
        int r = n - 1;

        int count{};
        while (l < r) {
            if (diffs[l] + diffs[r] >= 0) {
                count++;
                l++;
                r--;
            } else {
                l++;
            }
        }
        cout << count << "\n";
    }
    

}