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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int levelSum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                levelSum += curr->val;
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            v.push_back(levelSum);
        }

        root->val = 0;
        int level = 1;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int sum = 0;
                TreeNode* curr = q.front();
                q.pop();
    
                if(curr -> left)
                sum += curr->left->val;
                if(curr->right)
                sum += curr->right->val;

                if(curr->left){
                    curr->left->val = v[level] - sum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = v[level] -sum;
                    q.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
};