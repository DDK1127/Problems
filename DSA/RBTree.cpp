#include<iostream>
#include "RBTree.h"

template <typename T>
RBTree<T>::RBTree(){
	nil = new RBTree<T>(T());
	nil->color = BLACK;
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

// test
template class RBTree<int>;

