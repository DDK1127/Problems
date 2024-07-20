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
        void BST_Create(int n, string s);
        void BST_Delete(TreeNode*& root);
        void BST_insert(TreeNode*& root, int n, string s); // recusion insertion.
        void BST_insert(int n, string s); // sequence insertion.
        bool BST_Search(TreeNode* root, int n);
        bool BST_Search(int n);
        TreeNode* BST_Copy(TreeNode* root);
        bool BST_Equal(TreeNode* x, TreeNode* y);
        bool is_Empty(TreeNode* node){return node == nullptr;};
        bool is_Leaf(TreeNode* node){return node->left == nullptr && node->right == nullptr;};
        unsigned int Node_number(TreeNode* root);
        unsigned int CountDegree2(TreeNode* root);
        unsigned int CountDegree1(TreeNode* root);
        unsigned int CountLeaf(TreeNode* root);
        unsigned int Height(TreeNode* root);
        void Preorder(TreeNode* root);
        void Inorder(TreeNode* root);
        void Postorder(TreeNode* root);
        Binary_Search_Tree& operator=(const Binary_Search_Tree& other);
};

void Binary_Search_Tree::BST_Create(int n, string s){
    if(root == nullptr)
        root = new TreeNode(n, s);
    else
        cout << "Root alredy have value !!!" << endl;
    cout << "root ~~~ value = " << root->get_value() << ", string = " << root->get_str() << endl;
};

void Binary_Search_Tree::BST_Delete(TreeNode*& root){
    if(root != nullptr){
        BST_Delete(root->left);
        BST_Delete(root->right);
        delete root;
        root = nullptr;
    }
}

void Binary_Search_Tree::BST_insert(TreeNode*& root, int n, string s){
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

bool Binary_Search_Tree::BST_Search(TreeNode* root, int n){
    if(root == nullptr)
        return false;
    else{
        if(root->value == n)
            return true;
        else if(root->value < n)
            return BST_Search(root->right, n);
        else
            return BST_Search(root->left, n);
    }
}

bool Binary_Search_Tree::BST_Search(int n){
    TreeNode* current = root;

    while(current != nullptr && current->value != n){
        if(current->value < n)
            current = current->right;
        else
            current = current->left;
    }

    if(current == nullptr || current->value != n){
        cout << "Not find No." << n << endl;
        return false;
    }
    else{
        cout << "Find successful!, is => " << current->s << endl;
        return true;
    }
};

TreeNode* Binary_Search_Tree::BST_Copy(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    else{
        TreeNode* cproot = new TreeNode(root->value, root->s);
        cproot->left = BST_Copy(root->left);
        cproot->right = BST_Copy(root->right);
        return cproot;
    }
}

bool Binary_Search_Tree::BST_Equal(TreeNode* x, TreeNode* y){
    if(x == nullptr && y == nullptr)
        return true;
    else if(x != nullptr && y != nullptr){
        bool result = false;
        if(x->value == y->value){
            if(BST_Equal(x->left, y->left) && BST_Equal(x->right, y->right))
                result = true;
        }
        return result;
    }
    else 
        return false; 
}

unsigned int Binary_Search_Tree::Node_number(TreeNode* root){
    if(!is_Empty(root))
        return 1+Node_number(root->left)+Node_number(root->right);
    else    
        return 0;
};

unsigned int Binary_Search_Tree::CountDegree2(TreeNode* root){
    if(root == nullptr)
        return 0;
    int res = 0;
    if(root->left && root->right)
        res++;
    res += CountDegree2(root->right)+CountDegree2(root->left);
    
    return res;
}

unsigned int Binary_Search_Tree::CountDegree1(TreeNode* root){
    if(root == nullptr)
        return 0;
    int res = 0;
    if((root->left && !root->right) || (root->right && !root->left))
        res ++; 
    res += CountDegree1(root->left)+CountDegree1(root->right);

    return res;
}

unsigned int Binary_Search_Tree::CountLeaf(TreeNode* root){
    if(root == nullptr)
        return 0;
    int res = 0;
    if(!root->left && !root->right)
        res ++;
    res += CountLeaf(root->left)+CountLeaf(root->right);

    return res;
}

unsigned int Binary_Search_Tree::Height(TreeNode* root){
    if(root == nullptr)
        return 0;
    return max(Height(root->left), Height(root->left))+1;
}

void Binary_Search_Tree::Preorder(TreeNode* root){
    if(root != nullptr){
        cout << "'" << root->s << "' ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Binary_Search_Tree::Inorder(TreeNode* root){
    if(root != nullptr){
        Inorder(root->left);
        cout << "'" << root->s << "' ";
        Inorder(root->right);
    }
}

void Binary_Search_Tree::Postorder(TreeNode* root){ 
    if(root != nullptr){
        Postorder(root->left);
        Postorder(root->right);
        cout << "'" << root->s << "' ";
    }
}

Binary_Search_Tree& Binary_Search_Tree::operator=(const Binary_Search_Tree& other){
    if(this != &other){
        BST_Delete(root);
        root = BST_Copy(other.root);
    }
    return *this;
}

int main(){
    Binary_Search_Tree B1, ccc;
    B1.BST_Create(999, "BBBBBBBBig BBBBBBBoos");
    B1.BST_insert(B1.root, 8841, "Ba");
    B1.BST_insert(B1.root, 54, "g");
    B1.BST_insert(B1.root ,11, "Eric");
    B1.BST_insert(B1.root, 98, "DD");
    B1.BST_insert(B1.root, 1223, "HEHEHEH");
    B1.BST_insert(B1.root, 12, "QQ");
    B1.BST_insert(B1.root, 2, "2");
    B1.BST_insert(B1.root, 1, "1");
    cout << "number of Node : " << B1.Node_number(B1.root) << endl;
    // B1.BST_Search(88410);
    // B1.BST_Search(B1.root, 00055) ? cout << "yes" << endl : cout << "not" << endl;
    cout << "Inorder => " << endl;
    B1.Inorder(B1.root);
    cout << "\nPreorder => " << endl;
    B1.Preorder(B1.root);
    cout << "\nDegree2 node have " << B1.CountDegree2(B1.root) << endl;
    cout << "\nDegree1 node have " << B1.CountDegree1(B1.root) << endl;
    cout << "\nLeaf node have " << B1.CountLeaf(B1.root) << endl;
    cout << "\nTree Height =  " << B1.Height(B1.root) << endl;

    ccc = B1;
    cout << "Inorder => " << endl;
    ccc.Inorder(ccc.root);
    B1.BST_Equal(B1.root, ccc.root) ? cout << "\n is TTTTTT" : cout << "\nFFFFFFFFFFF" << endl;
    return 0;
}