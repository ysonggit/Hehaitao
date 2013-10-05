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

  friend ostream & operator<<(ostream &, const BinaryTree &);

  void insert(int);
  Node* search(int);
  Node* predecessor(int);
  void remove(int);
  void destroy_tree();
  
 private:
  Node* root; 
  void destroy(Node* );
  void insert(int, Node*);
  Node* search(int, Node*);
  void print(ostream &, Node* , int) const;
};
