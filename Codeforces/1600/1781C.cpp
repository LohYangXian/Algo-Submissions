//Equal Frequencies

/*
balanced if all characters present in it appear the same number of times

given a string s of length n consisting of lowercase eng letters

find balanced string t of length n consiting of lowercase eng letters 
that is diff from string s in as few positions as possible

number of indices i such that si != ti as small as possible

t cases
n
string s

n < 10^5, o(n) or o(n logn)


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> freqCount(26, 0);

        for (char c : s) {
            freqCount[c - 'a']++;
        }

        vector<pair<int, int>> freq;
        for (int c = 0; c < 26; c++) {
            freq.push_back({freqCount[c], c});
        }

        sort(freq.rbegin(), freq.rend());

        int globalK = n;
        int globalMinChanges = n;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0 || n / k > 26)
                continue;

            int groups = n / k;
            int used = 0;

            for (int i = 0; i < groups; i++) {
                used += min(k, freq[i].first);
            }

            int changes = n - used;

            if (changes < globalMinChanges) {
                globalMinChanges = changes;
                globalK = k;
            }
        }

        int groups = n / globalK;

        // How many copies of each chosen character we still need.
        vector<int> remaining(26, 0);

        // Whether this character is one of our chosen groups.
        vector<bool> chosen(26, false);

        for (int i = 0; i < groups; i++) {
            int c = freq[i].second;
            chosen[c] = true;
            remaining[c] = globalK;
        }

        // First preserve as many existing positions as possible.
        vector<int> replacePositions;

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            if (chosen[c] && remaining[c] > 0) {
                remaining[c]--;
            } else {
                replacePositions.push_back(i);
            }
        }

        // Characters still needed in the final string.
        vector<char> needed;

        for (int c = 0; c < 26; c++) {
            while (remaining[c] > 0) {
                needed.push_back('a' + c);
                remaining[c]--;
            }
        }

        // Every "extra" position corresponds to one missing character.
        for (int i = 0; i < replacePositions.size(); i++) {
            s[replacePositions[i]] = needed[i];
        }

        cout << globalMinChanges << '\n';
        cout << s << '\n';
    }
}