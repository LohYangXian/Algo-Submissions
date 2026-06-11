class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int total = nums[i] + nums[l] + nums[r];
                if (total == 0) {
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r and nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (l < r and nums[r] == nums[r + 1]) {
                        r--;
                    }
                    
                } else if (total < 0) {
                    l++;
                } else if (total > 0) {
                    r--;
                }
            }
        }
        return result;
    }
};
