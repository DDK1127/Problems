#include <iostream>
#include "RBTree.h"

template <typename T>
RBTree<T>::RBTree() {
	nil = new RBNode<T>(T());
	nil->color = BLACK;
	nil->left = nil->right = nil->parent = nullptr;
	root = nil;
}

template <typename T>
RBTree<T>::~RBTree() {
	destoryTree(root);
	delete nil;
}

template <typename T>
void RBTree<T>::destoryTree(RBNode<T>* node) {
	if (node != nil) {
		destoryTree(node->left);
		destoryTree(node->right);
		delete node;
	}
}

template <typename T>
void RBTree<T>::leftRotate(RBNode<T>* x) {
	RBNode<T>* y = x->right;
	x->right = y->left;

	if (y->left != nil)
		y->left->parent = x;

	y->parent = x->parent;

	if (x->parent == nullptr)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

template <typename T>
void RBTree<T>::rightRotate(RBNode<T>* y) {
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

template <typename T>
void RBTree<T>::insert(T key) {
	RBNode<T>* z = new RBNode<T>(key);
	z->left = z->right = z->parent = nil;

	RBNode<T>* y = nullptr;
	RBNode<T>* x = root;

	while (x != nil) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;

	if (y == nullptr)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	z->left = z->right = nil;
	z->color = RED;

	insertFixup(z);
}

template <typename T>
void RBTree<T>::insertFixup(RBNode<T>* z) {
	while (z->parent && z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			RBNode<T>* y = z->parent->parent->right;
			if (y && y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->right) {
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(z->parent->parent);
			}
		}
		else {
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
void RBTree<T>::inorder(RBNode<T>* node) const {
	if (node != nil) {
		inorder(node->left);
		std::cout << node->key << " ";
		inorder(node->right);
	}
}

template <typename T>
void RBTree<T>::preorder(RBNode<T>* node) const {
	if (node != nil) {
		std::cout << node->key << " ";
		preorder(node->left);
		preorder(node->right);
	}
}

template <typename T>
void RBTree<T>::postorder(RBNode<T>* node) const {
	if (node != nil) {
		postorder(node->left);
		postorder(node->right);
		std::cout << node->key << " ";
	}
}

template <typename T>
RBNode<T>* RBTree<T>::search(T key) const {
	RBNode<T>* x = root;
	while (x != nil && key != x->key) {
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return (x == nil) ? nullptr : x;
}


template <typename T>
void RBTree<T>::transplant(RBNode<T>* u, RBNode<T>* v) {
	if (u->parent == nullptr)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

template <typename T>
void RBTree<T>::remove(T key) {
	RBNode<T>* z = search(key);
	if (z == nullptr)
		return;

	RBNode<T>* y = z;
	Color yOriginalColor = y->color;
	RBNode<T>* x;

	if (z->left == nil) {
		x = z->right;
		transplant(z, z->right);
	}
	else if (z->right == nil) {
		x = z->left;
		transplant(z, z->left);
	}
	else {
		y = z->right;
		while (y->left != nil)
			y = y->left;

		yOriginalColor = y->color;
		x = y->right;

		if (y->parent == z)
			x->parent = y;
		else {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	delete z;

	if (yOriginalColor == BLACK)
		deleteFixup(x);
}

template <typename T>
void RBTree<T>::deleteFixup(RBNode<T>* x) {
	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			RBNode<T>* w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				leftRotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(x->parent);
				x = root;
			}
		}
		else {
			RBNode<T>* w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}