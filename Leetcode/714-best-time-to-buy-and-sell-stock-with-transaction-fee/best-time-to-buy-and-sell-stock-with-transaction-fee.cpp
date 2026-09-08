int solve(int index,vector<int> &prices,int buy,int fee,vector<vector<int>> &dp){
    
    int profit=0;
    if(index==prices.size()) return 0;
    if(dp[index][buy]!=-1)
        return dp[index][buy];
    if(buy){
        profit=max(-prices[index]+solve(index+1,prices,0,fee,dp),solve(index+1,prices,1,fee,dp));
    }
    else {
        profit=max(prices[index]-fee+solve(index+1,prices,1,fee,dp),solve(index+1,prices,0,fee,dp));
    }
    return dp[index][buy]=profit;

}
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,1,fee,dp);
    }
};