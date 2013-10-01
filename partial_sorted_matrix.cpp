#include <iostream>

using namespace std;

bool find(int *matrix, int rows, int cols, int number){
    
    if(matrix != NULL && rows >0 && cols > 0){
	// search from lower left to the upper right  
	// start from bottom row 
	int current_row = rows - 1;
	// start from first column 
	int current_col = 0;
	
	while(current_row >=0 && current_col < cols){
	    if( matrix[current_row * cols + current_col] == number ){
		cout<<"The number "<<number<<" is founded ";
		cout<<"at row ("<<current_row+1<<"), column ("<<current_col+1<<")"<<endl;
		return true;
	    }else{
		if(matrix[current_row *  cols + current_col] > number){
		    // go up and search above element in the same column
		    current_row--;
		}else{
		    // go right and search element in the same row
		    current_col++;
		}
	    }
	}
    }else{
	cout<<"invalid matrix (NULL pointer passed) "<<endl;
	return false;
    }

    return false;
}

int main(){
    int matrix[4][4] = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};    
    // Test 1: find a number that is in  the matrix
    int numIn[] = {1, 15, 9};
    for(int i=0; i<3; i++){
	cout<<"Test 1: "<<numIn[i]<<" is already in matrix ..."<<endl;	
	find((int*)matrix, 4, 4, numIn[i]);
    }
    // Test 2: find a number that is out of the matrix
    int numOut[] = {0, 20, 5};
    for(int i=0; i<3; i++){
	cout<<"Test 2: "<<numOut[i]<<" is not in matrix ..."<<endl;
	find((int*)matrix, 4, 4, numOut[i]);
    }

    // Test 3: pass a null pointer
    cout<<"Test 3: pass a null pointer to find() ..."<<endl;
    find(NULL, 4, 4, 15);
    return 0;
}
