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
    int solve(int& maxSum, TreeNode* root) {
        if (!root) return 0;
        int left = solve(maxSum, root->left);
        int right = solve(maxSum, root->right);
        int round = left + right + root->val;
        int onlyOne = max(left, right) + root->val;
        int onlyRoot = root->val;
        maxSum = max({maxSum, round, onlyOne, onlyRoot});
        return max(onlyOne, onlyRoot);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(maxSum, root);
        return maxSum;
    }
};