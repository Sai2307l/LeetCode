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
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        dfs(root, best);
        return best;
    }
private:
    int dfs(TreeNode* node, int &best) {
        if (!node) return 0;
        int leftGain = max(0, dfs(node->left, best));
        int rightGain = max(0, dfs(node->right, best));
        int priceNewPath = node->val + leftGain + rightGain;
        best = max(best, priceNewPath);
        return node->val + max(leftGain, rightGain);
    }
};