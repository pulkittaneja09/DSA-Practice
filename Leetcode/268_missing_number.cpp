
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long expected = (long long)n * (n + 1) / 2; // sum from 0..n
        long long actual = 0;
        for (int num : nums) {
            actual += num;
        }
        return (int)(expected - actual);
    }
};
