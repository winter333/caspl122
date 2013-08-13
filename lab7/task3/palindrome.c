#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome (char *input) {

	int length = 0 ;
	while (input[length] != 0) {
		length = length + 1; 
	}

	int bol = 1 ;
	int ans = 0 ; 
	int index = 0 ; 

	if (length == 1) {
		bol = 0 ;
		ans = 1 ; 
	}

	while (bol == 1) {	
		if (index == (length - index -1) ) {
			bol = 0 ;
			ans = 1 ; 
		}
		

		if (input[index] != input[length - index -1] ) {
			bol = 0 ;
			ans = 0 ; 
		}
		
		else if ((index + 1) == (length - index - 1)) {
			bol = 0 ;
			ans = 1 ; 	
		}

		index++; 
	}
	return ans ; 
	
}


int main(int argc, char **argv) {
	int ans=0;
	ans=isPalindrome(argv[1]);
	if(ans==1){
		printf("%s is a palindrome!\n",argv[1]);
	}
	else{
		printf("%s is not a palindrome!\n",argv[1]);
	}
	return 0;
} 


 
