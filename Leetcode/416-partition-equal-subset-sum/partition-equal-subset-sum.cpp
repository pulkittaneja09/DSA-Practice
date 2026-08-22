bool solve(int index,int sum,vector<int>& nums,vector<vector<int>>&dp){
    if(sum==0) return true;
    if(index==0) return (nums[index]==sum);
    if(dp[index][sum]!=-1){
        return dp[index][sum];

    }
    int nottake=solve(index-1,sum,nums,dp);
    
    int take=false;
    if(nums[index]<=sum){
        take=solve(index-1,sum-nums[index],nums,dp);
    }
    return dp[index][sum]=take||nottake;
}
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(sum%2==1) return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum/2,nums,dp);
    }
};