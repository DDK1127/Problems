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
    int s = 0, ans;
    int kthSmallest(TreeNode* root, int k) {
        help(root, k);
        return ans;
    }
    int help(TreeNode* root, int k) {
        if(root->left)
            s += kthSmallest(root->left, k);
        if(++s == k){
            ans = root->val;
            return 0;
        }
        if(root->right)
            s += kthSmallest(root->right, k);
        return s;
    }
};