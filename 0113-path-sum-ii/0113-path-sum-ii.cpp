/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>> &ans, vector<int> ds, int sum){
        if(!root) return; 
        sum -= root->val;
        ds.push_back(root->val);
        if(sum == 0 && !root->left && !root->right){
            ans.push_back(ds);
        }
        else{
            solve(root->left, ans, ds, sum);
            solve(root->right, ans, ds, sum);
        }
        sum+=root->val;
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum = targetSum;
        solve(root, ans, ds, sum);
        return ans;
    }
};