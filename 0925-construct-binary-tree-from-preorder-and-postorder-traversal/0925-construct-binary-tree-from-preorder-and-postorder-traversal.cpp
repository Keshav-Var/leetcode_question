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
    unordered_map<int, int> ht;
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int i1, int i2, int j1, int j2){
        if(i1 > i2 || j1 > j2) return NULL;
        TreeNode *node = new TreeNode(preorder[i1]);
        if(i1 == i2) return node;
        int leftSize = ht[preorder[i1+1]] - j1 + 1;
        node->left = solve(preorder, postorder, i1+1, i1+leftSize, j1, j1+leftSize-1);
        node->right = solve(preorder, postorder, i1+leftSize+1, i2, j1+leftSize, j2-1);
        return node;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++)
        ht[postorder[i]] = i;
        return solve(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size()-1);
    }
};