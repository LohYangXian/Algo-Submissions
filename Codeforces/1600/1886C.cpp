//Decreasing String

/*
string a < b if a is a prefix of b (a != b) or
index i where ai < bi for any index j 1 <= j < i

lowercase latin

string s1 is given
generate other strings

remove a char from string si-1 in a way that si is lexicographical
minimal

S = s1 + s2 + ..... sn
get S[pos]

t cases 
s1 (10^6)
pos 

try a O(n) or O(nlogn) soln?
*/
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long pos;
        cin >> pos;

        long long n = s.size();

        long double root =
            ((2.0L * n + 1) -
            sqrtl((2.0L * n + 1) * (2.0L * n + 1) - 8.0L * pos))
            / 2.0L;

        long long groupNumber = ceill(root);
        long long prevConsumed = (groupNumber - 1) * (2 * n - groupNumber + 2) / 2;

        long long groupPos = pos - prevConsumed - 1;
        stack<long long> stack;

        if (groupNumber > 1) {
            for (int i = 0; i < n - 1; i++) {
                stack.push(i);
                if (s[i] > s[i + 1]) {
                    while (stack.size() > 0 && s[stack.top()] > s[i + 1]) {
                        s[stack.top()] = '0';
                        stack.pop();
                        groupNumber--;
                        if (groupNumber <= 1) break;
                    }
                } 
                if (groupNumber <= 1) break;
            }

            for (int i = n - 1; i >= 0; i--) {
                if (groupNumber <= 1) break;
                if (s[i] == '0') continue;
                s[i] = '0';
                groupNumber--;
                if (groupNumber <= 1) break;
            }
        }
        
        int pointer = 0;
        int k = 0;
        while (pointer < n) {
            if (s[pointer] != '0') {
                if (k == groupPos) break;
                k++;
            }
            pointer++;
        } 
        cout << s[pointer];
    }
}