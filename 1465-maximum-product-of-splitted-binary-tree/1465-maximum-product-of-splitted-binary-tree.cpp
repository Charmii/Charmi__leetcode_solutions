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
private: 
long long total = 0;
long long maxi = 1;
int MOD = 1e9 + 7;
void find_sum(TreeNode* root){
    if(!root) return;
    total += root->val;
    
    if(root->left){
        find_sum(root->left);
        root->val += root->left->val;
    }

    if(root->right){
        find_sum(root->right);
        root->val += root->right->val;
    }
}

void find_max(TreeNode* root){
    if(!root->left && !root->right){
        long long num1 = root->val;
        long long num2 = total - num1;
        maxi = max(maxi, (num1*num2));
        return;
    }

    if(root->left){
        long long num1 = root->left->val;
        long long num2 = total - num1;
        maxi = max(maxi, (num1*num2));
        find_max(root->left);
    }

    if(root->right){
        long long num1 = root->right->val;
        long long num2 = total - num1;
        maxi = max(maxi, (num1*num2) );
        find_max(root->right);
    }

}
public:
    int maxProduct(TreeNode* root) {
        find_sum(root);
        find_max(root);
        cout<<total;
        return maxi % MOD;
    }
};