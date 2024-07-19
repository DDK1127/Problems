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
        TreeNode(TreeNode*node):left(node->left), right(node->right), s(node->s), value(node->value){}; 
        string get_str(){return this->s;}
        int get_value(){return this->value;}
        friend class Binary_Search_Tree;
};
class Binary_Search_Tree{
    private:
    public:
        TreeNode *root;
        Binary_Search_Tree():root(nullptr){};
        TreeNode* BST_Create(int n, string s);
        bool BST_Search(int n);
        TreeNode* BST_insert(TreeNode*& root, int n, string s); // recusion insertion.
        void BST_insert(int n, string s); // sequence insertion.
        bool is_Empty(TreeNode* node){return node == nullptr;};
        bool is_Leaf(TreeNode* node){return node->left == nullptr && node->right == nullptr;};
        int Node_number(TreeNode* root);
};

TreeNode* Binary_Search_Tree::BST_Create(int n, string s){
    if(root == nullptr)
        root = new TreeNode(n, s);
    else
        cout << "Root alredy have value !!!" << endl;
    cout << "value = " << root->get_value() << ", string = " << root->get_str() << endl;
};

bool Binary_Search_Tree::BST_Search(int n){
    TreeNode* current = root;

    while(current != nullptr && current->value != n){
        if(current->value < n)
            current = current->right;
        else
            current = current->left;
    }

    if(current == nullptr || current->value != n)
        return false;
    else{
        cout << "find successful!, is => " << current->s << endl;
        return true;
    }
};

TreeNode* Binary_Search_Tree::BST_insert(TreeNode*& root, int n, string s){
    if(root == nullptr)
        root =  new TreeNode(n, s);
    else if(root->value < n)
        BST_insert(root->right, n, s);
    else    
        BST_insert(root->left, n, s);
};

void Binary_Search_Tree::BST_insert(int n, string s){
    //
};

int Binary_Search_Tree::Node_number(TreeNode* root){
    if(!is_Empty(root))
        return 1+Node_number(root->left)+Node_number(root->right);
    else    
        return 0;
};

int main(){
    Binary_Search_Tree B1;
    B1.BST_Create(9999, "BBBBBBBBig BBBBBBBoos");
    B1.BST_insert(B1.root, 8841, "Ba");
    B1.BST_insert(B1.root, 00054, "g");
    cout << "number of Node : " << B1.Node_number(B1.root) << endl;
    B1.BST_Search(8840) ? cout << "Find!" << endl : cout << "Not Find~" << endl;
    return 0;
}