//Vika and the Bridge

/*
cans of paint of k colors

paint each plank in one of k colors

only step on planks of the same color
can repaint one plank of the bridge

minimum possible max number of planks she will have to cross in one step 
if she can repaint one (or zero) plank. a different color while crossing
the bridge

t test cases

1 1 2 1 1


1 2 3 2 3 2 1
*/

#include <unordered_map>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        int x;
        unordered_map<int,int> largestGap{};
        unordered_map<int,int> secondLargestGap{};
        unordered_map<int,int> last{};

        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> x;

            int gap = i - last[x] - 1;

            if (gap > largestGap[x]) {
                secondLargestGap[x] = largestGap[x];
                largestGap[x] = gap;
            } else if (gap > secondLargestGap[x]) {
                secondLargestGap[x] = gap;
            }
            last[x] = i;
        }

        int ans = numeric_limits<int>::max();

        for (int c = 1; c <= k; c++) {
            int gap = n - last[c];

            if (gap > largestGap[c]) {
                secondLargestGap[c] = largestGap[c];
                largestGap[c] = gap;
            } else if (gap > secondLargestGap[c]) {
                secondLargestGap[c] = gap;
            }

            ans = min(ans, max(secondLargestGap[c], largestGap[c] / 2));
        }

        cout << ans << "\n";
    }
}