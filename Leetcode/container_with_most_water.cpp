class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer{};
        int l = 0;
        int r = heights.size() - 1;
        while (l < r) {
            answer = max(min(heights[l], heights[r]) * (r - l), answer);
            if (heights[l] >= heights[r]) {
                r--;
            } else {
                l++;
            }
        }
        return answer;
    }
};
