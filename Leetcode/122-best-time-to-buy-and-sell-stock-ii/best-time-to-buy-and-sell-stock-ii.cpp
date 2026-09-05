int solve(int index,vector<int> &prices,int buy,vector<vector<int>> &dp){
    if(index==prices.size()) return 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    int profit=0;
    if(buy){
        profit=max(-prices[index]+solve(index+1,prices,0,dp),solve(index+1,prices,1,dp));
    }
    else{
        profit=max(prices[index]+solve(index+1,prices,1,dp),solve(index+1,prices,0,dp));
    }
    return dp[index][buy]=profit;
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,1,dp);
    }
};