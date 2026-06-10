class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const int num: nums) 
        {
            m[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& [key, value]: m)
        {
            bucket[value].push_back(key);
        }

        vector<int> ans;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int j = bucket[i].size() - 1; j >= 0; j--) {
                ans.push_back(bucket[i][j]);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
