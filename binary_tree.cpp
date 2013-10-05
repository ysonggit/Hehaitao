#include "binary_tree.h"
#include <iomanip> // width()
#include <deque> 
#include <cmath>

const int width_unit = 5;

void BinaryTree::destroy(Node* leaf){
    if(leaf!=NULL){
	destroy(leaf->left);
	destroy(leaf->right);
	remove(leaf->value);
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
	    // if 2 children
	    // goes to the LEFT subtreexs
	    Node* replace = current;
	    parent = current;
	    current = current->left;
	    // keep on parse through the subtree until 
	    // reach the rightmost node of the LEFT subtree
	    while(current->right){
		parent = current;
		current = current->right;
	    }
	    // replace the value_to_be_removed with the rightmost value 
	    // then remove the rightmost node later
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


/******** Question 23 Print from top to bottom **********/
void BinaryTree::print_top_to_bottom(){
    if(root==NULL)
	return;
    
    deque<Node*> deque_tree_nodes;
    deque_tree_nodes.push_back(root);
    while(deque_tree_nodes.size()){
	Node* current = deque_tree_nodes.front();
	cout<<current->value<<" "<<endl;
	deque_tree_nodes.pop_front();
	if(current->left != NULL){
	    deque_tree_nodes.push_back(current->left);
	}
	if(current->right != NULL){
	    deque_tree_nodes.push_back(current->right);
	}
    }
}

/********** Question 39 Binary Tree Depth *************/
int BinaryTree::depth_subtree(Node* leaf){
    if(leaf==NULL)
	return 0;
    int depth_left = depth_subtree(leaf->left);
    int depth_right = depth_subtree(leaf->right);
    
    return (depth_left > depth_right) ? depth_left : depth_right; 
}

int BinaryTree::depth(){
    return depth_subtree(root);
}

/*********** Question 6 Reconstruct binary tree ************/
// two input sequences of numbers 
// output root node of tree
Node* construct(int* preorder, int* inorder, int length){
    if(preorder == NULL || inorder ==NULL || length ==0 ){
	return NULL;
    }

    return construct_subtree(preorder, preorder+length-1, inorder, inorder+length-1);
}

Node* construct_subtree(int *start_preorder, int* end_preorder, int* start_inorder, int* end_inorder){
    // the first number of pre-order is the root value
    Node* tree_root = new Node();
    tree_root->value = start_preorder[0];
    tree_root->left = NULL;
    tree_root->right = NULL;
    if(start_preorder == end_preorder){
	if(start_inorder == end_inorder && *start_preorder == *start_inorder){
	    return tree_root;
	}else{
	    cout<<"invalid input\n";
	    return NULL;
	}
    }
    int* root_inorder = start_inorder;
    // root_inorder = address of the value start_inorder[0]
    while(root_inorder <= end_inorder && *root_inorder != tree_root->value)
	++root_inorder;

    if(root_inorder == end_inorder && *root_inorder != tree_root->value){
	cout<<"invalid input"<<endl;
	return NULL;
    }

    int left_length = root_inorder - start_inorder;
    int *left_preorder_end = start_preorder + left_length;    
    // construct left subtree
    if(left_length >0){
	tree_root->left = construct_subtree(start_preorder+1, left_preorder_end, start_inorder, root_inorder-1);
    }
    // construct right subtree
    if(left_length < end_preorder - start_preorder){
	tree_root->right = construct_subtree(left_preorder_end+1, end_preorder, root_inorder+1, end_inorder);
    }
    return tree_root;
}

int main(){
    BinaryTree mytree;
    cout<<"--------- Insert to the tree ---------"<<endl;
    mytree.insert(5);
    mytree.insert(3);
    mytree.insert(2);
    mytree.insert(7);
    mytree.insert(0);
    mytree.insert(1);
 
    mytree.insert(10);
    mytree.insert(4);
    cout<<mytree<<endl;
    
    mytree.print_top_to_bottom();
    
    cout<<"--------- Remove form the tree ---------"<<endl;
    mytree.remove(0);
    cout<<mytree<<endl;
    mytree.remove(3);
    cout<<mytree<<endl;
    mytree.remove(5);
    cout<<mytree<<endl;
    
    cout<<"destroy the tree ... "<<endl;
    mytree.destroy_tree();
    cout<<mytree<<endl;
    
    
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    
    Node* tree_root= construct(preorder, inorder, length);
    BinaryTree tree(tree_root);
    cout<<tree<<endl;
    return 0;
}
