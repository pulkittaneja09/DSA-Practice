class Solution {
public:
    int solve(int index, vector<int>& prices, int buy, vector<vector<int>>& dp) {
        int n = prices.size();

        if (index >= n)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        if (buy) {
            return dp[index][buy] = max(
                -prices[index] + solve(index + 1, prices, 0, dp),
                solve(index + 1, prices, 1, dp)
            );
        }
        else {
            return dp[index][buy] = max(
                prices[index] + solve(index + 2, prices, 1, dp),
                solve(index + 1, prices, 0, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, prices, 1, dp);
    }
};