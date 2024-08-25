// LeetCode 113.Path Sum II

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
    vector<vector<int>> vv;
    vector<int> v;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return vv;
        find(root, 0, targetSum);
        return vv;
    }
    void find(TreeNode* root, int sum, int tar){
        sum += root->val;
        v.push_back(root->val);

        if(root->left)
            find(root->left, sum, tar);
        if(root->right)
            find(root->right, sum, tar);
        if(!root->left && !root->right){
            if(sum == tar){
                vv.push_back(v);
            }
        }
        v.pop_back();
    }
};