class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far=0;
        int a=nums.size();
        for(int i=0;i<a;i++){
            if(i>far){
                return false;
            }
            far=max(far,nums[i]+i);

        }
        if(far>=a-1) return true;
        else{
            return false;
        }
    }
};