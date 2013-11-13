#include <iostream>
#include <stack>


class Node{
    int data; 
    Node* next;
public:
    Node(){};
    Node(int _data): data(_data), next(NULL){};
    void SetData(int aData) {data = aData;}
    void SetNext(Node* aNext){ next = aNext;}
    int GetData(){ return data;}
    Node* GetNext() {return next;}
};


class List{
    Node *head;
public:
    List() {head = NULL;}
    List(Node* h): head(h){}
    void Print();
    void Append(int _data);
    void Delete(int _data);
    // Question 13
    void Append(Node* _n);
    void Delete(Node* _n);

    void PrintReversely();

    // Question 15
    Node* KthNodeToTail(int k);
    
    Node* GetHead(){return head; }
    
    List Reverse();
};


