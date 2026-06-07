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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> nodes;
        map<int,bool> isRoot;
        for(auto i:descriptions){
            int parent = i[0];
            int child = i[1];
            bool left = i[2] == 1;
            if(nodes.find(parent)==nodes.end()){
                nodes[parent] = new TreeNode(parent);
                isRoot[parent] = true;
            }
            if(nodes.find(child)==nodes.end()){
                nodes[child] = new TreeNode(child);
                isRoot[child] = false;
            }
            if(left){
                nodes[parent]->left = nodes[child];
            }else{
                nodes[parent]->right = nodes[child];
            }
            isRoot[child] = false;
        }
        for(auto i:isRoot) if(i.second) return nodes[i.first];
        return nullptr;
    }
};