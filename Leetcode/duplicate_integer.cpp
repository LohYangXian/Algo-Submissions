class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (const int num: nums) 
        {
            if (!s.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};