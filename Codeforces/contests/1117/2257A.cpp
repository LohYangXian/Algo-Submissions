//Creating Abbreviations

/*
set of words S, 

n words

m times

1. forms a sequence of one or more words from set S
word may appear in sequence several times
* is formed from resulting phrase

Then beaver adds resulting abbreviation to S and can 
now use in subsequent ops as an ordinary word

given n initial words,
and set of abbreviations

determine if made a mistake and whether all these abbre
shld have appeared as a result

not need to be in same order

t cases
n words, m abbre

n lines of words
m lines of abbre

try O(n) SOln
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; int m;
        cin >> n >> m;
        unordered_set<char> set{};
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            set.insert(toupper(s[0]));
        }

        bool solved = false;

        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                if (set.find(s[j]) == set.end()) {
                    solved = true;
                    break;
                }
            }
        }

        if (solved == false) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}