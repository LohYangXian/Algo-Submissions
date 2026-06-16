class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - min);
            if (prices[i] < min) min = prices[i];
        }
        return res;
    }
};
