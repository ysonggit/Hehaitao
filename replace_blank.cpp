#include <iostream>

using namespace std;

void replace_blank(char str[]){
    if(str == NULL)
	return;
    //1. get input char array length 
    int str_length = strlen(str)+1;
    //cout<<str_length<<endl;
    cout<<"Original char array : ";
    printf("%s\n", str);
    
    //2. new char array length should be str_length + 2*num_blanks
    int num_blanks =0;
    for(int i=0; i<str_length; i++){
	// get num_blanks
	if(str[i] ==' '){
	    num_blanks++;
	}
    }
    //cout<<num_blanks<<" blanks are found"<<endl;
    int new_str_length = str_length + 2*num_blanks;
    
    // create a new char array with new length
    char new_str[new_str_length];
    strcpy(new_str, str);
    //3. two relative address tracers  :
    // idx1 is the index of the end of original str
    // idx2 is the index of the end of new str
    int idx1 = str_length; //The last char is stored at Memory addr: (int&)str+str_length 
    int idx2 = new_str_length;
    while(idx1 >= 0 && idx2 > idx1){
	if(new_str[idx1] != ' '){
	    // copy the non-blank char back 
	    new_str[idx2--] = new_str[idx1];
      	}else{
	    // replace ' ' with '%''2''0' from back to front
	    new_str[idx2--] ='0';
	    new_str[idx2--] ='2';
	    new_str[idx2--] ='%';
	}	
	idx1--;
    }
    cout<<"Replace "<<num_blanks<<" blanks with %20 :";
    printf("%s\n", new_str);
}

int main(){
    // Test 1: blanks contained 
    char str1[] = " hello world I love ya ";
    replace_blank(str1);
    
    // Test 2: consecutive blanks contained 
    char str2[] ="    you are      beautiful   ";
    replace_blank(str2);
    
   
    // Test 3: char array only contains blanks
    char str3[] = "   ";
    replace_blank(str3);

    // Test 4: NULL array
    replace_blank(NULL);
    
    return 0;
}
