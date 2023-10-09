class Solution {
private:
    // int f(int ind, vector<int> nums, vector<int>& dp){
    //     if(ind == 0){
    //         return nums[0];
    //     }
    //     if(ind<0) return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     int pick = nums[ind] + f(ind-2, nums, dp);
    //     int not_pick = 0 + f(ind-1, nums, dp);
    //     return dp[ind] = max(pick,not_pick);
    // }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        // return f(nums.size()-1, nums, dp);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            int pick = nums[i];
            if(i-2 >= 0) pick += dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[nums.size()-1];
    }
};