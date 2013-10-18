#include <iostream>

using namespace std;

int fibonacci(int n){
    int result[2] = {0,1};
    if (n <2)
	return result[n];

    int sum = 0;
    int f_n_1 = 0;
    int f_n_2 = 1;
    for(int i=2; i<=n; i++){
	sum = f_n_1 + f_n_2;
	f_n_2 = f_n_1;
	f_n_1 = sum;
    }
    return sum;
}

int main(){
    for(int n=0; n<10; n++)
	cout<<fibonacci(n)<<" ";

    cout<<endl;
    
    return 0;
}
