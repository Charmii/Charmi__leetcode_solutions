class Solution {
    bool subsetSum(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];

        int notTake = subsetSum(ind-1, target, nums, dp);
        int take = false;
        if(nums[ind] < target) take = subsetSum(ind-1, target-nums[ind], nums, dp);

        return dp[ind][target] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for(int i=0; i<nums.size(); i++) totSum += nums[i];
        if(totSum % 2) return false;
        int target = totSum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return subsetSum(nums.size()-1, target, nums, dp);
    }
};