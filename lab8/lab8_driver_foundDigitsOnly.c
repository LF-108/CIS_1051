#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//prototypes
int foundDigitsOnly (char barcode_chars[12]);

int main(){

char arr1[12] = {'a', 'b', 'c', 'd', 'e', 'f', '1', '2', '3', '4', '5','6'};
char arr2[12] = {'1','2','3','4','5','6','7','8','9','0','2','1'};

printf("The value of foundDigitsOnly for arr1 is %d.\n", foundDigitsOnly(arr1));
printf("The value of foundDigitsOnly for arr2 is %d.\n", foundDigitsOnly(arr2));

return EXIT_SUCCESS;

}
int foundDigitsOnly(char barcode_chars[12])
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: NONE
 *Globals: NONE
 *Returns: only_digits - an integer truth value that is 1 if all the characters are digits, and 0 otherwise
 *Description: Checks to see if all the characters inputted by the user for the UPC barcode are digits and returns a truth value based on that 
 * 
 */
{
    //Declares and assigns a value to only_digits, a flag that holds a truth value dependant on if barcode_chars contains only digit characters
    int only_digits = 1;
    
    //Declares a loop control variable
    int i;

    //Checks if all the elements are digits
    for(i = 0; i<12; i++){
       if(isdigit(barcode_chars[i])==0){
            only_digits = 0;
        }
    }

    return only_digits;
}
