class Solution {
    bool solve(int step, vector<int>& nums, vector<int>& dp) {
        if (step == 0) return true;
        if(dp[step] != -1) return dp[step];
        for (int i = 1; i <= step; i++) {
            if (step - i >= 0 && nums[step - i] >= i ) {
                if (solve(step - i, nums, dp)) {
                dp[step] = 1;
                return true;
                }
            }
        }
        dp[step] = 0;
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums.size() - 1, nums, dp);
    }
};
