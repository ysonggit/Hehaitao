#include <iostream>
#include <stack>

using namespace std;

template <typename T> 
class CQueue{
public:
    CQueue(){}
    ~CQueue(){}

    void append(const T&);
    T remove_head();
    void print(); 
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T>
void CQueue<T>::append(const T& node){
    stack1.push(node);
}

template<typename T>
T CQueue<T>::remove_head(){
   
    if(stack2.size()<=0){
	// 1) if stack2 is empty
	// pop element from stack1 to stack2
	while(stack1.size()>0){
	    // use T& , must be initialized
	    T& data = stack1.top();
	    // so any modification on data will placed to stack1.top() also
	    stack1.pop();
	    stack2.push(data);
	}
    }
    
    // 2) if stack2 is not empty, just pop 
    //    the element in stack2 one-by-one
    T head = stack2.top();
    stack2.pop();
    return head;
}

template<typename T>
void CQueue<T>::print(){
    stack<T> tmp;
    if(!stack1.empty()){
	tmp=stack1;
	// make a copy of stack1, keep original data safe
	stack<T> nodes;
    
	while(!tmp.empty()){
	    nodes.push(tmp.top());
	    tmp.pop();
	}
	while(!nodes.empty()){
	    cout<<nodes.top()<<" ";
	    nodes.pop();
	}
    }else{
	tmp=stack2;
	// so after remove operation, stack1 is already empty
	// the data are stored in stack2
	while(!tmp.empty()){
	    cout<<tmp.top()<<" ";
	    tmp.pop();
	}
    }    
    cout<<endl;
}


int main(){
    CQueue<int> int_q;
    int_q.append(1);
    int_q.append(2);
    int_q.append(3);
    int_q.print();
    for(int i=0; i<3; i++){
	int_q.remove_head();
	int_q.print();
    }

    CQueue<char> char_q;
    char_q.append('a');
    char_q.append('b');
    char_q.append('c');
    char_q.print();
    for(int i=0; i<3; i++){
	char_q.remove_head();
	char_q.print();
    }
    return 0;
}
