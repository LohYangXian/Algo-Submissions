class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m_s;
        unordered_map<char, int> m_t;

        for (char c: t) {
            m_t[c]++;
        }

        int matches = 0;
        int l = 0;
        int r = 0;
        int res_len = numeric_limits<int>::max();
        string res = "";

        while (r < s.size()) {
            m_s[s[r]]++;
            if (m_t.contains(s[r]) and m_s[s[r]] == m_t[s[r]]) {
                matches++;
            }

            while (matches == m_t.size()) {
                if (r - l + 1 < res_len) {
                    res_len = r - l + 1;
                    res = s.substr(l, r - l + 1);
                }
                if (m_t.contains(s[l]) and m_t[s[l]] == m_s[s[l]]) {
                    matches--;
                }
                m_s[s[l]]--;
                l++;
            }
            r++;
        }
        return res;
    }
};
