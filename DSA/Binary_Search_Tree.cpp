// Binary Search Tree
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    private:
        int value;
        string s;
    public:
        TreeNode* left;
        TreeNode* right;
        TreeNode():left(nullptr), right(nullptr), s(""), value(0){};
        TreeNode(int n, string s):left(nullptr), right(nullptr), s(s), value(n){}; 
        string get_str(){return this->s;}
        int get_value(){return this->value;}
        friend class Binary_Search_Tree;
};
class Binary_Search_Tree{
    private:
    public:
        TreeNode *root;
        Binary_Search_Tree():root(nullptr){};
        TreeNode* BST_Create(TreeNode*, int input_n, string input_s);
        void BST_insert(int input_n, string input_s);
        bool is_Empty(TreeNode* node){return node == nullptr;};
        bool is_Leaf(TreeNode* node){return node->left == nullptr && node->right == nullptr;};
        int Node_number(TreeNode* root);
};

TreeNode* Binary_Search_Tree::BST_Create(TreeNode* ,int input_n, string input_s){
    if(root == nullptr)
        root = new TreeNode(input_n, input_s);
    else
        cout << "Root alredy have value !!!" << endl;
    cout << "value = " << root->get_value() << ", string = " << root->get_str() << endl;
};

// void Binary_Search_Tree::BST_insert(int input_n, string input_s){};

int Binary_Search_Tree::Node_number(TreeNode* root){
    if(!is_Empty(root))
        return 1+Node_number(root->left)+Node_number(root->right);
    else    
        return 0;
};

int main(){
    Binary_Search_Tree B1;
    B1.BST_Create(B1.root, 56, "oewugfwoe");
    B1.BST_Create(B1.root, 9999, "BBBBBBBBig BBBBBBBoos");
    return 0;
}