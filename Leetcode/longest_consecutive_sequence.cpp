class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        
        int max_count = 0;
        int count;
        for (const int num: nums)
        {
            if (!s.count(num - 1)) {
                count = 0;
                int temp = num;
                while (s.find(temp) != s.end()) {
                    count++;
                    s.erase(temp);
                    temp++;
                }
                max_count = max(max_count, count);
            }
        }
        return max_count;
    }
};
