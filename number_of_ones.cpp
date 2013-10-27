#include <iostream>

using namespace std;

// input n is a binary integer number
int number_of_ones(const unsigned int n){
    int count = 0;
    int i = 0;
    unsigned int flag = 1;
    // always 32 loops 
    while(flag){
	if (n & flag)
	    count++;
	flag = flag << 1;
	i++;
    }
    //cout<<i<<endl; 
    return count;
}

int main(){
    cout<<number_of_ones(1001010)<<endl;
    cout<<number_of_ones(1)<<endl;
    cout<<number_of_ones(0x7FFFFFFF)<<endl;
    cout<<number_of_ones(0)<<endl;
    cout<<number_of_ones(0x80000000)<<endl;
    cout<<number_of_ones(0xFFFFFFFF)<<endl;
    return 0;
}
