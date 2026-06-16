class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0;
        int r = 0;
        int res = 0;
        while (r < s.size()) {
            m[s[r]]++;
            while (m[s[r]] > 1) {
                m[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
