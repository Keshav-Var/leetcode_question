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
class FindElements {
    TreeNode *root;

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    int parent(int i){
        return (i-1)/2;
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        // v[0] = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                node->left->val = 2*node->val + 1;
                // v[2*node->val + 1] = 2*node->val + 1;
                q.push(node->left);
            }
            if(node->right){
                node->right->val = 2*node->val + 2;
                // v[2*node->val + 2] = 2*node->val + 2;
                q.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        TreeNode *node = root;
        vector<int> path;
        int temp = target;
        while(temp != 0){
            path.push_back(temp);
            temp = parent(temp);
        }

        while(path.size()){
            int x = path.back();
            if(node->left && node->left->val == x) {node = node->left; path.pop_back();}
            else if(node->right && node->right->val == x) {node = node->right; path.pop_back();}
            else break;
        }
        if(path.empty()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */