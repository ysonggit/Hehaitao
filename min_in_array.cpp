#include <iostream>

using namespace std;

int min_in_order(int* array, int index_1, int index_2){
    int min = array[index_1];
    for(int i= index_1+1; i<= index_2; i++){
	if(array[i] < min){
	    min = array[i];
	}
    }
    return min;
}

int min_in_array(int* array, int length){
    if (array == NULL || length<=0 ){
	cout<<"array contains no number"<<endl;
	return -1;
    }
    
    int index_1 = 0;
    int index_2 = length -1;
    int index_mid = index_1;
    while(array[index_1] >= array[index_2]){
	if(index_2 - index_1 ==1){
	    // loop terminate condintion, two indices meet, 
	    // the larger one points to the min number
	    index_mid = index_2;
	    break;
	}
	index_mid = (index_1 + index_2)/2;
	
	if(array[index_1]==array[index_2]){
	    if(array[index_mid] == array[index_2]){
		return min_in_order(array, index_1, index_2);
	    }
	}

	if(array[index_mid] > array[index_1]){
	    // the min number is not in the first half
	    // move the index_1 to the position pointed by index_mid
	    index_1 = index_mid;
	}else{
	    index_2 = index_mid;
	}
    }
    return array[index_mid];
}

int main(){
    int a[5] = {3,4,8,0,2};
    cout<<min_in_array(a, 5)<<endl;
    int b[5] ={1,0,1,1,1};
    cout<<min_in_array(b, 5)<<endl;
    int c[5] = {1,1,1,0,1};
    cout<<min_in_array(c, 5)<<endl;
    return 0;
}
