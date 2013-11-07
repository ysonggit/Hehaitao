#include <iostream>
#include <vector>
using namespace std;

// print the complete number of n bits 
void print(vector<char>& number){
    bool is_beginning_zero = true;
    
    for(int i=0; i<number.size(); i++){
	// filter the '0' before non-zero int, like 010
	if(number[i] != '0')
	    if(is_beginning_zero)
		is_beginning_zero = false;

	if(is_beginning_zero == false)
	    cout<<number[i];
    }
    cout<<" ";
}

// recursivel print number from low bit to high bit
// for example: a decimal number of 3 bits
// first fix the hundred bit to 0, then fix the tenth bit to 0, reaches the integer bit
// then iterates 10 times on the integer bit to print 000, 001, 002,...,009
// and fix the hundred bit to 0, update the tenth bit to 1, reaches the integer bit
// iterates 10 times to print 010, 011, ..., 019
// etc.
void recursive_print(vector<char> &number, int index){
    if(index == number.size()-1){
	print(number);
	return;
    }
    for(int i=0; i<10; i++){
	number[index+1] = i+'0';
	recursive_print(number, index+1);
    }
}


void ints_less_than_n_digits(int n){
    if (n <=0 )
	return;
    // initialize vector of char 
    vector<char> number;
    for(int i=0; i<n; i++){
	number.push_back('0');
    }
    for(int i=0; i<10; i++){
	number[0] = i+'0'; // ASCII representation
	recursive_print(number, 0);
    }
    
}

int main(){
    int count = 0;
    ints_less_than_n_digits(2);
    cout<<endl;
    //ints_less_than_n_digits(3);
    return 0;
}
