//Contract Value

/*



contrast of an array of size 1 is equal to 0

given array a,

build an array of B, such that:
b is not empty; at least one element
b is subseq of a (must follow order?)

the contrast of b is equal to contrast of a

what is minimum size of b

t is number of test cases
n , size of array a

n integers, elements of array it self

print min size of b

find a O(n) soln

1 2 3
-1 -1 = 1 + 1 = 2

1 - 3 = -2 = 2

1 3 2
-2 + 1 = 2 + 1 = 3

1 - 2 = -1 = 1

3 2 1

1 + 1 = 2
3 -1 = 2

3 1 2
2 5 3

*/

#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        int y;

        bool undecided{true};
        bool isIncreasing{};

        int ans{2};
        
        for (int i = 0; i < n - 1; i++) {
            cin >> y;

            if (undecided == true) {
                if (y > x) {
                    isIncreasing = true;
                    undecided = false;
                } else if (y < x) {
                    isIncreasing = false;
                    undecided = false;
                }
            } else {
                if (isIncreasing == true) {
                    if (y < x) {
                        ans++;
                        isIncreasing = false;
                    } 
                } else {
                    if (y > x) {
                        ans++;
                        isIncreasing = true;
                    }
                }
            }
            x = y;
        }

        if (undecided == true) {
            cout << 1 << "\n";
            continue;
        }
        cout << ans << "\n";
    }
}