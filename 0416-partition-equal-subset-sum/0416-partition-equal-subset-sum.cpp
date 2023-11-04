class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for(int i=0; i<nums.size(); i++) totSum += nums[i];
        if(totSum % 2 == 1) return false;
        int target = totSum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(totSum+1, false));

        for(int i=0; i<nums.size(); i++){
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;

        for(int ind=1; ind<nums.size(); ind++){
            for(int tar = 1; tar <= target; tar++){
                bool notTake = dp[ind-1][tar];
                bool take = false;
                if(nums[ind] <= tar) take = dp[ind-1][tar-nums[ind]];
                dp[ind][tar] = take || notTake;
            }
        }
        return dp[nums.size()-1][target];
    }
};