#include <iostream>

using namespace std;

bool equal(double a, double b){
    if(a - b < 0.000001 && a - b > -0.000001){
	return true;
    }
    return false;
}

double power(double base, int exponent){
    if (equal(0.0, base)){
	if(exponent >=0 )
	    return 0.0;
	else{
	    cerr<<" invalid input "<<endl;
	    return 0.0;
	}
    }
    
    //1. exponent is a positive integer
    double result = 1.0;
    if (exponent >= 0){
	for(int i=0; i<exponent; i++){
	    result *= base;
	}
    }else{
	// 2 exponent is a negative integer
	for(int i=0; i<(-exponent); i++){
	    result *= base;
	}
	result = 1.0/result;
    }

    return result;
}

int main(){
    cout<<power(2,10)<<endl;
    cout<<power(0, 0)<<endl;
    cout<<power(2, -10)<<endl;
    cout<<power(0, -10)<<endl;
    return 0;
}
