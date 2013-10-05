#include "binary_tree.h"
#include <iomanip> // width()

const int width_unit = 5;

void BinaryTree::destroy(Node* leaf){
    if(leaf!=NULL){
	destroy(leaf->left);
	destroy(leaf->right);
	delete leaf;
    }
}

void BinaryTree::destroy_tree(){
    destroy(root);
}


void BinaryTree::insert(int key, Node* leaf){
    // if the number to insert is < given leaf node's value
    // it is the left child
    // otherwise, it is the right child
    if(key < leaf->value){
	if(leaf->left != NULL){
	    insert(key, leaf->left);
	}else{
	    leaf->left = new Node;
	    (leaf->left)->value = key;
	    (leaf->left)->left = NULL;
	    (leaf->left)->right = NULL;
	}
    }else{
	if(leaf->right !=NULL){
	    insert(key, leaf->right);
	}else{
	    leaf->right = new Node;
	    (leaf->right)->value = key;
	    (leaf->right)->left = NULL;
	    (leaf->right)->right = NULL;
	}
    }
    
}


void BinaryTree::insert(int key){
    if(root !=NULL){
	insert(key, root);
    }else{
	root = new Node;
	root->value = key;
	root->left = NULL;
	root->right = NULL;
    }
}


Node* BinaryTree::search(int key, Node* leaf){
    if(leaf != NULL){
	if (key == leaf->value)
	    return leaf;
	if (key < leaf->value)
	    return search(key, leaf->left);
	else
	    return search(key, leaf->right);
    }

    return NULL;
} 

Node* BinaryTree::search(int key){
    return search(key, root);
}

Node* BinaryTree::predecessor(int key){
    Node* current = root;
    Node* parent = NULL;
    while(current && current->value != key){
	parent = current;
	if(key < current->value){
	    current = current->left;
	}else{
	    current = current->right;
	}
    }
    return parent;
}

void BinaryTree::remove(int key){
    Node* current = search(key);
    Node* parent = predecessor(key);
    if(current != NULL){
	if(current->left && current->right){
	    Node* replace = current;
	    parent = current;
	    current = current->left;
	    while(current->right){
		parent = current;
		current = current->right;
	    }
	    replace->value = current->value;
	}

	// 1 or 0 child case
	// if 1 child,  tmp is the non-null child
	// if 0 child,  tmp is null
	Node *tmp = (current->left ? current->left: current->right);
	if(parent == NULL){ // this means a one-node tree
	    root = tmp;
	}else{
	    if (parent->value < current->value)
		// the number to be removed is actually the righ child of this parent
		parent->right = tmp;
	    else
		parent->left = tmp;
	}
	
	delete current;
    }
    return;
}


void BinaryTree::print(ostream & lhs, Node* leaf, int level) const{
    if(leaf != NULL){
	print(lhs, leaf->right, level+1);
	// print the node data w/respect to its level
	cout<<setw(level*width_unit)<<leaf->value<<endl;
	print(lhs, leaf->left, level+1);
    }
}

ostream & operator<<(ostream & lhs, const BinaryTree & T) {
    T.print(lhs, T.root, 1);
    return lhs;
}


int main(){
    BinaryTree mytree;
    mytree.insert(5);
    mytree.insert(3);
    mytree.insert(2);
    mytree.insert(7);
    mytree.insert(0);
    mytree.insert(1);
 
    mytree.insert(10);
    mytree.insert(4);
    cout<<mytree<<endl;

    cout<<"--------- Remove form tree ---------"<<endl;
    mytree.remove(0);
    cout<<mytree<<endl;
    mytree.remove(3);
    cout<<mytree<<endl;
    mytree.remove(5);
    cout<<mytree<<endl;
    return 0;
}
