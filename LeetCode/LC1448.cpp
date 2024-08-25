// LeetCode 1448.Count Good Nodes in Binary Tree

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
    int result = 0;
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        help(root, root->val);
        return result;
    }
    void help(TreeNode* root, int m){
        if(root->val >= m){
            result++;
            m = root->val;
        }
        if(root->left)
            help(root->left, m);
        if(root->right)
            help(root->right, m);
        
    }
};