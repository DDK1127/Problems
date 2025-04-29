#ifndef RBTREE_H
#define RBTREE_H 

enum Color {RED, BLACK};

template <typename T>
struct RBNode{
	T key;
	Color color;
	RBNode* parent;
	RBNode* left;
	RBNode* right;

	RBNode(T key) : key(key), color(RED), parent(nullptr), left(nullptr), right(nullptr);
};

template <typename T>
class RBTree {
	private:
		RBNode<T>* root;
		RBNode<T>* nil; // Sentinel Node 
		
		void leftRotate(RBNode<T>* x);
		void rightRotate(RBNode<T>* y);
		void insertFixup(RBNode<T>* z);
		void deleteFixup(RBNode<T>* x);
		void transplant(RBNode<T>* u, RBNode<T>* v);
		void destoryTree(RBNode<T>* node);
	public:
		RBTree();
		~RBTree();

		void insert(T key);
		void remove(T key);
		RBNode<T>* search(T key) const;
		void inorder(RBNode<T>* node) const;
		void preorder(RBNode<T>* node) const;
		void postorder(RBNode<T>* node) const;
};

#endif 
