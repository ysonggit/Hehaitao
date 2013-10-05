#include <iostream>

using namespace std;

struct Node{
  int value;
  Node* left;
  Node* right;
};

class BinaryTree{
 public:
  BinaryTree(){
    root = NULL;
  }
  ~BinaryTree(){
    destroy_tree();
  }
 BinaryTree(Node* _root) : root(_root){}

  friend ostream & operator<<(ostream &, const BinaryTree &);

  void insert(int);
  Node* search(int);
  Node* predecessor(int);
  void remove(int);
  void destroy_tree();
  int depth();
  void print_top_to_bottom();

 private:
  Node* root; 
  void destroy(Node* );
  void insert(int, Node*);
  Node* search(int, Node*);
  int depth_subtree(Node*);
  void print(ostream &, Node* , int) const;
};

Node* construct_subtree(int*, int*, int*, int*);
Node* construct(int*, int*, int);
