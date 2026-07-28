//Romantic Glasses

/*
n glasses in a line

ith glass has ai units of juice in it

lulia only drinks from odd numbered glasses

while her date drinks only from even numbered glasses

lulia wants to find a contiguous subarray of these glasses such that
both lulia and her date will have the same amt of juice in
total only if the glasses in the subarray are considered

t cases
n 
n integers 

find a (O(n)) soln

output yes if theres an answer, no need to state the l and r

sum of odd and sum of even are same in subarray 
*/
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        long long rollingOdd{};
        long long rollingEven{};
        long long curOdd{};
        long long curEven{};
        cin >> n;

        unordered_set<long long> s(n * 2);
        bool solved = false;

        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (i % 2 == 1) {
                curOdd = rollingOdd + x;
                curEven = rollingEven;
            } else {
                curEven = rollingEven + x;
                curOdd = rollingOdd;
            }
            if (curOdd - curEven == 0 || s.find(curOdd - curEven) != s.end()) {
                solved = true;
            }
            rollingEven = curEven;
            rollingOdd = curOdd;
            s.insert(curOdd - curEven);
        }
        if (solved == false) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}