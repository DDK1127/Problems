// LeetCode 450.Delete Node in a BST

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else{
            // find root == key
            if(!root->right && !root->left) // degree 0
                return nullptr; // direct delete;
            else if(!root-> right || !root->left){ // degree 1
                TreeNode* temp;
                if(!root->right)
                    temp = root->left;
                else if(!root->left)
                    temp = root->right;
                return temp;
            }
            else{ // degree 2
                TreeNode* temp = find_min_left(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, root->val);
                return root;
            }
        }
        return root;
    }
    TreeNode* find_min_left(TreeNode* root){
        while(root->left != nullptr)
            root = root->left;
        return root;
    }
};
