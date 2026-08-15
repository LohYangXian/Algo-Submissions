//Arranging the Sheep

/*
string n
. empty space and * sheep

move sheep one square left or right, if corresponding square 
exists and is empty

game ends when sheep are lined up, no empty cells between them

determine the min number of moves needed to make the level

t cases
n integer
string of length n

try a O(N) soln
*/
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string sheeps;
        cin >> n >> sheeps;

        vector<long long> pos{};
        for (long long i = 0; i < n; i++) {
            if (sheeps[i] == '*') pos.push_back(i);
        }

        long long ans = 0;
        long long lval;
        long long rval;
        long long lpointer;
        long long rpointer;

        long long size = pos.size();
        if (size == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        if (size % 2 == 1) {
            lpointer = (size / 2) - 1;
            rpointer = (size / 2) + 1;
            lval = pos[size / 2] - 1;
            rval = pos[size / 2] + 1;
        } else {
            lpointer = (size / 2) - 1;
            rpointer = (size / 2);
            long long total = pos[lpointer] + pos[rpointer];
            lval = (total / 2);
            rval = (total / 2) + 1;
        }

        while (lpointer >= 0 && rpointer < size) {
            ans += abs(pos[lpointer] - lval);
            ans += abs(pos[rpointer] - rval);
            lpointer--;
            lval--;
            rpointer++;
            rval++; 
        }

        cout << ans << "\n";
    }
}