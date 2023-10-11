#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/myheader.h"

double printIsArmstrongNumber(int num);

int main()
{
        //Calls header function
        program_identification(5, "Drivers(Armstrong)", "Determines if a given integer is an armstrong number.");   
    

        int armstrongInput; //Declares an int to serve as input for printIsArmstrong
        
	//Prompts for a number from the user
        printf("Please enter a number to check if it's an armstrong number.\n");

        //Scans in user input
        scanf("%d", &armstrongInput);

	printIsArmstrongNumber(armstrongInput); //Calls printIsArmstrongNumber(armstrongInput)
    
	return EXIT_SUCCESS;
}

double printIsArmstrongNumber(int num)
/*  
 * Preconditions:  
 *     variable numberin-  Number to check. 
 * Postconditions:         NONE 
 * Globals:    		   NONE 
 * Returns:    		   Zero if the number passed in is not an Armstrong number, or the number itself 
 *                         if it is. 
 * Description:  	   An Armstrong number is an n-digit number that is equal to the  
 *                         sum of the nth powers of its digits.   
 * 
 *                         This function will print out "Yes, X is an Armstrong number." if the  
 *                         number passed in is indeed an Armstrong, or "No, X is not an  
 *                         Armstrong number." if it is not. 
 * 
 *                         For example, the number 153 is an Armstrong number, as is the  
 *                         number 1,634, as explained in the following examples: 
 * 
 *                         153 =    1*1*1  +  5*5*5  +  3*3*3 
 *                              1   +    125   +   27   =  153 
 * 
 * 
 *                        1,634 =   1*1*1*1  +  6*6*6*6  +  3*3*3*3  +  4*4*4*4 
 *                              1  +      1,296  +     81  +       256    = 1,634 
 */ 
{	
     
	int copyNum = num; //Declares int copyNum, so we can save the value for display and use num for calculations
	int count = 0;     //Declares int count, which will be used to maintain a count for while loops and used for exponent calculations
	int i = 0;         //Declares int i, which will be used to control flow of while loop
	int sum = 0;       //Declares int sum, 
	int digit;         //Declares int digit, which will store the digits during while loop calculations
	int is_Armstrong = 0; //Declares int is_Armstrong, which stores the truth value of whether num is an armstrong number
        
        //Finds the number of digits by dividng num by ten until it equals 0, incrementing count each loop to store the number of digits    
 	while (num != 0){
 	num = num / 10;    
 	count++;
	}

        //Finds the value of each digit by dividing copyNum by 10 and taking the modulus of that value. 
        //Then adds that value to the power of count to sum    
        while(i<count){
    	digit = (int)(copyNum / pow(10,i)) % 10;
    	sum = sum + pow(digit, count);
    	i++;
    
    	}
    
        //Checks is the sum is equal to copyNum and adjusts truth value of is_Armstrong accordingly
    	if(copyNum == sum){
       	     printf("Yes, %d is an Armstrong number.\n", copyNum);
             is_Armstrong++;
        }
    
        else{
            printf("No, %d is not an Armstrong number.\n", copyNum);
        }
    
        return is_Armstrong;

}
