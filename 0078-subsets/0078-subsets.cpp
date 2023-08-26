class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        if(index == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve(index+1, nums, ans, ds);
        ds.pop_back();
        solve(index+1, nums, ans, ds);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,nums, ans, ds);
        return ans;
    }
};