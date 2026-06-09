class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; 
        std::unordered_map<char, int> freq_s;
        std::unordered_map<char, int> freq_t;

        for (int i = 0; i < s.size(); i++) {
            freq_s[s[i]]++;
            freq_t[t[i]]++;
        }

        for (const auto& [key, value] : freq_s) 
        {
            if (!freq_t.contains(key) || freq_t[key] != value) return false;
        }
        return true;
    }
};
