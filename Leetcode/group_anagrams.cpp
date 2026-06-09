class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> m;
        for (const string& str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            m[s].push_back(str);
        }
        vector<vector<string>> ans;
        for (const auto& [key, value] : m)
        {
            ans.push_back(value);
        }
        return ans;
    }
};
