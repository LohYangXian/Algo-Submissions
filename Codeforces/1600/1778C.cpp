//Flexible string

/*
string a and stirng b

both string length n

at most 10 different characters in string a
(TAKE NOTE)

also have a set Q
Q is empty

you can apply following operation on string a any number of times
choose an index i (1 <= i <= n) and a lowercase english letter c 
add ai to the set Q and then replace ai with c

in the end set Q should contain at m,ost k diff characters
maximuize the bnumber of integer pairs (l,r) such that a[l,r] = b[l,r]
substring (l and r inclusive)

t cases
n length, k limit
string a of length n 
at most 10 diff characters in a 

string b of length n

print max number of pairs satisfy constraint
*/

#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

long long ans = 0;

unordered_set<char> set;
string a;
string b;
vector<char> chars;
int k;


void calculateScore(bool selected[]) {
    int l = 0;
    int r = 0;
    long long score = 0;
    while (r < a.size()) {
        if (selected[a[r] - 'a'] || a[r] == b[r]) {
            r++;
        } else {
            long long len = r - l;
            score += (len) * (len + 1) / 2LL;
            r++;
            l = r;
        }
    }
    long long len = r - l;
    score += (len) * (len + 1) / 2LL;
    
    if (score > ans) {
        ans = score;
    }
}

void backtrack(int pointer, int selectedCount, bool selected[]) {
    if (selectedCount == k) {
        calculateScore(selected);
        return;
    } 

    if (pointer >= chars.size()) {
        return;
    }

    //Select the current char
    selected[chars[pointer] - 'a'] = true;
    backtrack(pointer + 1, selectedCount + 1, selected);

    selected[chars[pointer] - 'a'] = false;
    
    backtrack(pointer + 1 , selectedCount, selected);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> k;
        cin >> a >> b;
        ans = 0;
        set.clear();
        chars.clear();
        for (char c: a) {
            set.insert(c);
        }
        for (char c: set) {
            chars.push_back(c);
        }

        k = min(k, (int)chars.size());
        bool selected[26] = {};
        backtrack(0, 0, selected);
        cout << ans << "\n";
    }
}