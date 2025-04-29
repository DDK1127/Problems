#include<iostream>
#include "RBTree.h"

template <typename T>
RBTree<T>::RBTree(){
	nil = new RBTree<T> (T());
	nil->color = BLACK;
	nil->left = nil->right = nil->parent = nullptr;
	root = nil;
}

template <typename T>
RBTree<T>::~RBTree(){
	destroyTree(root);
	delete nil;
}

template <typename T>
void RBTree<T>::destroyTree(RBNode<T>* node){
	if(node != nil){
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

template <typename T>
void RBTree<T>::leftRotate(RBNode<T>* x){
	RBNode<T>* y = x->right;
	x->right = y->left;
	
	if(y->left != nil)
		y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == nullptr)
		root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else 
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

template <typename T>
void RBTree<T>::rightRotate(RBNode<T>* y){
	RBNode<T>* x = y->left;
    y->left = x->right;

    if (x->right != nil)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

template < typename T>
void RBTree<T>::insert(T key){
	RBNode<T>* x = new RBNode<T>(key);
	z->left = z->right = z->parent = nil;

	RBNode<T>* y = nullptr, *x = root;
	while(x != nil){
		y = x;
		if(z->key < x->key)
			x = x->left;
		else 
			x = =x->right;
	}

	z->parent = y;

	if(y == nullptr)
		root = z;
	else if(z->key < y->key)
		y->left = z;
	else 
		y->right = z;

	z->left = z->right = nil;
	z->color = RED;

	insertFixup(z);
}

template <typename T>
void RBTree<T>::insertFixup(RBNode<T>* z){
	while(z->parent && z->parent->color == RED){
		if(z->parent == z->parent->parent->left){
			RBNode<T>* y = z->parent->parent->right;
			if(y && y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent = RED;
				z = z->parent->parent;
			}
			else{ // y not exit, (nbalanced) need to rotation.
				if(z == z->parent->right){
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(z->parent->parent);
			}
		}
		else{ // z->parent == z->parent->parent-right 
			RBNode<T>* y = z->parent->parent->left;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
			else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
		}
	}
	root->color = BLACK;
}

template <typename T>
void RBTree<T>::inorder(RBNode<T>* node) const{
	if(node != nil){
		inorder(node->left);
		std::cout << node-key << " ";
		inorder(node->right);
	}

}

template <typename T>
void RBTree<T>::preorder(RBNode<T>* node) const{
	if(node != nil){
		std::cout << node->key << " ";
		preorder(node->left);
		preorder(node-right);
	}
}

template <typename T>
void RBTree<T>::postorder(RBNode<T>* node) const{
	if(node != nil){
		postorder(node->left);
		postorder(node->right);
		std::cout << node-val << " ";
	}
}

// test example
template class RBTree<int>;

