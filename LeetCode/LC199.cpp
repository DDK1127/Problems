// LeetCode 199. Binary Tree Right Side View

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;

        if(!root)
            return v;

        q.push(root);

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode *current = q.front();
                if(i == 0)
                    v.push_back(current->val);
                if(current->right)
                    q.push(current->right);
                if(current->left)
                    q.push(current->left);
                q.pop();
            }
        }
        return v;
    }
};