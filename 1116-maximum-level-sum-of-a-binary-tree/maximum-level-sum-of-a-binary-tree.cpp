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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        int sol = INT_MIN,sol_lv = INT_MAX,lv=1;
        while(!bfs.empty()){
            int n = bfs.size();
            int level_sum = 0;
            for(int i=0;i<n;i++){
            TreeNode* top = bfs.front();
            bfs.pop();
            level_sum += top->val;
            if(top->left) bfs.push(top->left);
            if(top->right) bfs.push(top->right);
            }
            sol_lv = level_sum > sol?lv:sol_lv;
            sol = max(level_sum,sol);
            lv++;
        }
        return sol_lv;
    }
};