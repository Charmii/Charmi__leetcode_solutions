class Solution {
public:
    void findCombinations(int index, int k, int target, vector<vector<int>>& ans, vector<int>& ds) {
        if(ds.size() == k ){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        for (int i = index; i <= 9; i++) {
            ds.push_back(i);
            findCombinations(i+1, k, target - i, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(1, k, n, ans, ds);
        return ans;
    }
};