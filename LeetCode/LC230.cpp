//230. Kth Smallest Element in a BST
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
    int s = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root->left)
            return kthSmallest(root->left, k);
        s++;
        if(s == k)
            return root->val;
        if(root->right)
            return kthSmallest(root->right, k);
        return root->val;
    }
};