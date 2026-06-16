class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        
        int l = 0;
        int r = 0;
        int res = 0;
        int freqMax = 0;

        while (r < s.size()) {
            m[s[r]]++;
            freqMax = max(freqMax, m[s[r]]);
            while (r - l + 1 - freqMax > k) {
                m[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;

    }
};
