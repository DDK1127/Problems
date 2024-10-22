#include<bits/stdc++.h>
using namespace std;

struct node{
    char val;
    node *left;
    node *right;
};

node *newnode(char c){
    node * Node = new node();
    Node->val = c;
    Node->left = nullptr;
    Node->right = nullptr;

    return Node;
}

int helper(string s, int start, int end, char value){
    for(int i = start; i <= end; i++){
        if(s[i] == value)
            return i;
    }
    return 0; // no way not find, maybe input error value.
}

node *build_tree(string in, string pre, int s, int t/*, int &preindex */){
    static int preindex = 0;
    if(s > t)
        return NULL;
    node *tnode = newnode(pre[preindex++]);

    if(s == t)
        return tnode;
    int inindex = helper(in, s, t, tnode->val);
    tnode->left = build_tree(in, pre, s, inindex-1);
    tnode->right = build_tree(in, pre, inindex+1, t);

    return tnode;
}

void Postorder(node *root){
    if(root == nullptr)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->val << " ";
}

void Inorder(node *root){
    if(root != nullptr){
        Inorder(root->left);
        cout << root->val << " ";
        Inorder(root->right);
    }
}


int main(){
    string in = "DBEAFC", pre = "ABDECF";
    node *root = build_tree(in, pre, 0, in.size()-1);
    cout << "Post order => " << endl;
    Postorder(root);
    return 0;
}