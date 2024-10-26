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
    void traverse_left(TreeNode* root, vector<int>& depth, int level, int &max_depth){
        if(!root)
        return;
        depth[root->val] = max_depth;
        max_depth = max(max_depth, level);
        traverse_left(root->left, depth, level+1, max_depth);
        traverse_left(root->right, depth, level+1, max_depth);
    }

    void traverse_right(TreeNode* root, vector<int>& depth, int level, int &max_depth){
        if(!root)
        return;
        depth[root->val] = max(max_depth, depth[root->val]);
        max_depth = max(max_depth, level);
        traverse_right(root->right, depth, level+1, max_depth);
        traverse_right(root->left, depth, level+1, max_depth);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> depth(100001, 0);
        int max_depth = 0;
        traverse_left(root, depth, 0, max_depth);
        max_depth = 0;
        traverse_right(root, depth, 0, max_depth);

        vector<int> ans;
        for(auto it:queries){
            ans.push_back(depth[it]);
        }
        return ans;
    }
};