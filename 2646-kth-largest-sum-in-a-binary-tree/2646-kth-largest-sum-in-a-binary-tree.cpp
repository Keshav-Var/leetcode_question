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

    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        queue<TreeNode*> q;
        priority_queue<long long> pq;
        q.push(root);
        q.push(NULL);
        long long sum = 0;
        while(q.size() > 1){
            TreeNode *curr = q.front();
            q.pop();
            
            if(curr == NULL){
                q.push(NULL);
                pq.push(sum);
                sum = 0;
                continue;
            }

            sum = sum + curr->val;

            if(curr->left != NULL)
            q.push(curr->left);
            if(curr->right != NULL)
            q.push(curr->right);
        }
        pq.push(sum);
        long long KthSum = -1;
        cout<<pq.size();
        for(int i = 0; i < k-1 && !pq.empty(); i++){
            pq.pop();
        }
        cout<<" "<<pq.size();
        if(!pq.empty()){
            KthSum = pq.top();
        }
        return KthSum;
    }
};