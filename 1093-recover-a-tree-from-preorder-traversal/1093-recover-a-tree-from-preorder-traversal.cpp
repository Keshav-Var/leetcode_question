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
        int idx = 0;
public:
    TreeNode* recoverFromPreorder(string s, int d = 0) {
        if(idx >= s.length()) return NULL;
        int count = 0, st = idx;
        while(idx < s.length() && s[idx] != '-') {count++; idx++;}
        TreeNode *node = new TreeNode(stoi(s.substr(st, count)));
        count = 0;
        while(idx<s.length() && s[idx] == '-') {idx++; count++;}
        if(count <= d) {idx -= count; return node;}
        node->left = recoverFromPreorder(s, d+1);
        count = 0; 
        while(idx<s.length() && s[idx] == '-') {idx++; count++;}
        if(count <= d) {idx -= count; return node;}
        node->right = recoverFromPreorder(s, d+1);
        return node;
    }
};