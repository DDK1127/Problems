// LeetCode 783. Minimum Distance Between BST Nodes
// https://leetcode.com/problems/minimum-distance-between-bst-nodes
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
    vector<int> vv;
    void traversal(TreeNode* root){
        if(!root)
            return;
        if(root->left)
            vv.push_back(root->left->val);
        traversal(root->left);
        if(root->right)
            vv.push_back(root->right->val);
        traversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        vv.push_back(root->val);
        traversal(root);
        sort(vv.begin(), vv.end());
        int s = 10000000;
        for(int i = 0; i < vv.size()-1; i++)
            s = min(s, vv[i+1]-vv[i]);
        return s;
    }
};