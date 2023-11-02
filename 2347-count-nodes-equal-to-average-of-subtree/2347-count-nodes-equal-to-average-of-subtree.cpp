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
    int count=0;
private: 
    pair<int,int> dfs(TreeNode* root){
        // cout<<root->val<<" ";
        if(!root->left && !root->right) {
            count++;
            return {root->val, 1};
        }

        pair<int, int> left, right;
        // Check for root left child
        if(root->left){
            left  = dfs(root->left);
        }

        // Check for root right child
        if(root->right){
            right = dfs(root->right);
        }

        cout<<left.first<<" "<<left.second<<" "<<right.first<<" "<<right.second<< endl;
        int sum = left.first + right.first + root->val;
        int num = left.second + right.second + 1;

        int avg = sum/num; 
        if(avg == root->val) count++;
        return {sum, num};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};