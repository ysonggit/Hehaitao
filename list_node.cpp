#include "list_node.h"

using namespace std;

void List::Print(){
    Node *tmp = head;
    if(tmp == NULL){
	cout<<" Empty List "<<endl;
	return;
    }
    
    while(tmp != NULL){
	cout<<tmp->GetData();
	cout<<" --> ";
	tmp = tmp->GetNext();	
    }
    cout<<" NULL "<<endl;
    
}

void List::Append(int _data){
    // create a new node
    Node* newNode = new Node();
    newNode->SetData(_data);
    newNode->SetNext(NULL);
    
    // create a copy of list head pointer
    Node* tmp = head; 
    
    if(tmp != NULL){
	// the list already has some nodes
	// keep on parse the tmp pointer to the end of the list
	while(tmp->GetNext() !=NULL){
	    tmp = tmp->GetNext();
	}

	// append the new node
	tmp->SetNext(newNode);
	
    }else{
	// new node will be the first node in the list
	head = newNode;
    }
}

void List::Append(Node* _n){
    if(!_n )
	return;
    Node *tmp = head; // a copy of list head ptr
    if(tmp != NULL){
	while(tmp->GetNext() != NULL){
	    tmp = tmp->GetNext();
	}
	
	//append the new Node to end of the list
	tmp->SetNext(_n);
    }else{
	// the list has no node yet
	head = _n;
    }
    
}

void List::Delete(int _data){ 
    // empty list
    if(head == NULL)
	return;
   
    Node* ToBeDeleted = NULL;
    if(head->GetData() == _data){
	ToBeDeleted = head;
    	head = head->GetNext();
    }else{
	// create a copy of list head pointer
	Node* ptr = head;
	while(ptr->GetNext() != NULL){
	    if(ptr->GetNext()->GetData() == _data ){
		// ptr --> [ptr.next] --> ...
		Node* tmp = ptr->GetNext()->GetNext();
		ToBeDeleted = ptr->GetNext();
		ptr->SetNext(tmp);
		break;
	    }else{
		ptr = ptr->GetNext();
	    }
	}	 
    }
    if(ToBeDeleted != NULL){
	delete ToBeDeleted;
	ToBeDeleted = NULL;
    }
}

// Question 5
void List::PrintReversely(){
    stack<Node*> nodes;
    Node* ptr = head;
    if(ptr==NULL){
	cout<<" Empty List"<<endl;
	return;
    }

    while(ptr!=NULL){
	nodes.push(ptr);
	ptr= ptr->GetNext();
    }
    cout<<"NULL ";
    while(!nodes.empty()){
	Node* tmp = nodes.top();
	cout<<" <-- ";
	cout<<tmp->GetData();
	nodes.pop();
    }
    cout<<endl;
}

void List::Delete(Node* _n){
    if(!head || !_n)
	return;
    //if _n is not the end node
    if(_n->GetNext() != NULL){
	Node* pNext = _n->GetNext();
	_n->SetData(pNext->GetData());
	_n->SetNext(pNext->GetNext());
	delete pNext; // free the memory pointed by pNext
	pNext = NULL; // pointed dangling ptr to NULL
    }
    // if the node to be deleted is the only head node
    else if (head == _n){
	//cout<<"will delete "<<_n->GetData()<<endl;
	delete _n;
	_n = NULL;
	head = NULL;
	
    }else{
	// delete the tail node
	Node* tmp = head;
	while(tmp->GetNext() != _n){
	    tmp = tmp->GetNext();
	}
	tmp->SetNext(NULL);
	delete _n;
	_n = NULL;
    }
}

Node* List::KthNodeToTail(int k){
    if(head == NULL || k<=0 ){
	cerr<<"Empty list!"<<endl;
	return NULL;
    }
   	
    // pointer 1 goes first for k-1 steps
    Node* ptr_1 = head; 
    for(int i =0 ; i<k-1; i++){
	// since so far the list size is unknown
	// need check the list tail each step
	if(ptr_1 ->GetNext() != NULL)
	    ptr_1 = ptr_1->GetNext();
	else
	    return NULL;
	
    } // now ptr_1 points to the kth node in the list
    // create pointer 2 now, let it be the list head
    Node* ptr_2 = head;
    while(ptr_1->GetNext() != NULL){
	// two pointers go forward together
	// until ptr_1 reaches the tail node
	// ptr_2 then points the kth node to the tail
	ptr_1 = ptr_1 -> GetNext();
	ptr_2 = ptr_2 -> GetNext();
    }
    return ptr_2;
}

List List::Reverse(){
    Node* ptr = head;
    List rev_list;
    if(ptr == NULL){
	return rev_list;
    }
    Node* tail = NULL;
    Node* pre = NULL;
    while(ptr != NULL){
	// h <- i -> j
	Node* nxt = ptr->GetNext(); //pre:(h), ptr:(i), nxt:(j)
	if(nxt == NULL){
	    // reaches to the tail
	    tail = ptr;
	}
	// so far current node's pointer points to next
	// do following three steps: (order matters)
	// 1. Set current node's *next pointer point to the node ahead 
	// ptr->GetNext() becomes pre, which is set in last iteration step 2
	// ptr->GetData() is not changed yet
	// h <- i -> j
	ptr->SetNext(pre);
	// 2. Save current node as pre, so it can be used in following iteration
	// pre->GetData() = ptr->GetData()
	// pre->GetNext() is pre
	// pre: (i) | h <- i -> j
	pre = ptr; // without step 1, pre (i) will still points to (j)
	// 3. finally set current node to its *next 
	// after this assignment, ptr->GetNext() actually is ptr->GetNext()->GetNext(), ptr->GetData() is ptr->GetNext()->GetData()
	// ptr:(j) | h <- i <- j -> ...
	ptr = nxt;
	
    }    
    rev_list = List(tail);
    return rev_list;
}

// Question 17
/*
  inputs : two starting nodes from two lists
 */
void merge(Node* n1, Node* n2, List& new_list){
    if(n1 == NULL && n2 == NULL){
	return;
    }
    if(n1  == NULL && n2 != NULL){
	new_list.Append(n2);
	return;
    }
    if(n1 != NULL && n2 == NULL){
	new_list.Append(n1);
	return;
    }
    
    
    if(n1->GetData() < n2->GetData()){
	new_list.Append(n1->GetData());
	merge(n1->GetNext(), n2, new_list);
	
    }
    else{
	new_list.Append(n2->GetData());
	merge(n1, n2->GetNext(), new_list);
    }
    
    
}

int main(){
    List mylist;
    mylist.Append(100);
    mylist.Print();
    mylist.Append(200);
    mylist.Print();
    
    mylist.Append(300);
    mylist.Print();
    mylist.Append(400);
    mylist.Print();
    mylist.PrintReversely();

    mylist.Delete(300);
    mylist.Print();
    mylist.Delete(200);
    mylist.Print();
    mylist.Delete(100);
    mylist.Print();
    mylist.Delete(400);
    mylist.Print();
    

    List yrlist;
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    yrlist.Append(n1);
    yrlist.Append(n2);
    yrlist.Append(n3);
    yrlist.Append(n4);
    yrlist.Append(n5);
    yrlist.Append(n6);
    yrlist.Print();
    
   

    cout<<"the last node to the list is:\n";
    cout<<yrlist.KthNodeToTail(1)->GetData()<<endl;
    cout<<"the 3rd node to the tail is:\n";
    cout<<yrlist.KthNodeToTail(3)->GetData()<<endl;
    yrlist.Delete(n1);
    yrlist.Print();
    // for this method, since n1 is not really deleted but replaced
    yrlist.Delete(n1);
    yrlist.Print();
   
    List herlist = yrlist.Reverse();
    cout<<"create a revese list "<<endl;
    herlist.Print();

    cout<<"Merge two sorted lists"<<endl;
    List a, b;
    a.Append(1);
    a.Append(9);
    a.Append(24);
    a.Append(30);
    cout<<"List 1: ";
    a.Print();
    b.Append(7);
    b.Append(8);
    b.Append(29);
    b.Append(32);
    cout<<"List 2: ";
    b.Print();
    List c;
    merge(a.GetHead(), b.GetHead(), c);
    cout<<"Merged list: ";
    c.Print();
    return 0;
}
