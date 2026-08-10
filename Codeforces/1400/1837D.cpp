//Bracket Coloring

/*
inserting characters 1 and + between the original characters of the sequence

() () and (()) are regular

sequence is called beautiful if one of the following conditions is 

it is a regular bracket sequence
if the order of characters is reversed, it becomes a regular bracket sequence

given a sequence s, color it in a way
: every bracket is colored into one color
for every color, there is at least one bracket colored into that color
for ever color, if write down the sequence of brackets having that color
in the order they appear, u get beautiful sequence

color s into min number of colors or report impossible

t cases
n number of chars
string s

try O(n) or O(n log n) soln

((())))(

())))((

if valid brackets,  1 1 1 1 1 1
if num opening != num closing, -1

else, try to split into diff subsequences 

( ( ( ) ) ) 
) (

list of stacks?
[
[CCC ) ) )]
[)(]
]


(()))(

[(]
[)]


())(

[]
[]


*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<char> stack1;
        vector<char> stack2;
        vector<int> ans;

        int res = 1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (stack2.size() > 0) {
                    stack2.pop_back();
                    ans.push_back(2);
                    res = 2;
                } else {
                    stack1.push_back('(');
                    ans.push_back(1);
                }
            } else {
                if (stack1.size() > 0) {
                    stack1.pop_back();
                    ans.push_back(1);
                } else {
                    stack2.push_back(')');
                    ans.push_back(2);
                    res = 2;
                }
            }
        }

        if (stack1.size() != 0 || stack2.size() != 0) {
            cout << -1 << "\n";
            continue;
        }

        int ones = 0;
        int twos = 0;
        for (int i: ans) {
            if (i == 1) ones++;
            if (i == 2) twos++;
        }

        if (ones == 0 && twos > 0) {
            res = 1;
            for (int i = 0; i < ans.size(); i++) {
                ans[i] = 1;
            }
        } 

        cout << res << "\n";
        for (int i: ans) {
            cout << i << " ";
        }
        
        cout << "\n";
    }
}