#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//prototypes
int promptForUPCbarcode (int barcode_array[12]);
void printArray(int arr[], int size);
int convertToDigit(char c);

int main(){

int upc[12];
promptForUPCbarcode(upc);
printArray(upc, 12);

return EXIT_SUCCESS;

}

int promptForUPCbarcode (int barcode_array[12])
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: 
 *Globals: NONE
 *Returns: 1 if the user inputs a Q, or 0 otherwise
 *Description: Prompts the user for the input of a UPC barcode and checks for a Q to end the program. 
 * If no Q is inputted, converted the given characters to integers and stores them in an array.
 * 
 */
{
    //Declares an array of chars to store user inputted barcode incase Q is inputted
    char barcode_chars[12];
    
    //Declares a loop control variable
    int i;

    //Prompts for user input, then scans and checks if the first character is a Q, ending the program if so
    printf("Enter a 12-digit UPC barcode or 'Q' to quit: \n");
    scanf("%c", &barcode_chars[0]);
    if(barcode_chars[0] == 'Q'){
        return 1;
    }
    
    //Converts the first inputted element to an integer digit if not Q
    else{
        barcode_array[0] = convertToDigit(barcode_chars[0]);
    }

    //Converts the other eleven characters to integer digits
    for(i = 1; i<12; i++ ){
         scanf("%c", &barcode_chars[i]);
        barcode_array[i] = convertToDigit(barcode_chars[i]);
    }
    
    getchar();

    return 0;
}

int convertToDigit(char c)
/*
 *Preconditions: char c- a char to be converted to an integer
 *Postconditions: NONE
 *Globals: NONE
 *Returns: value - the integer equivalent of the given char
 *Description: Converts a given char into an integer value
 * 
 */
{

    //Declares and assigns value the ASCII code value of char c
    int value = c - '0';
    
    return value;
}

void printArray(int arr[], int size)
/*
 *Preconditions: int arr[] is declared 
 *	             int size is size of arr
 *Postconditions: exits function after printing {} if array is empty
 *Globals: NONE
 *Returns: NONE
 *Description: Prints out every item in an int array
 *
 *
 */
{
    //Prints {} if array size 0, else prints out all the elements
    if (size == 0)
    {
        printf("{}");
        return;
    }

    printf("%d", arr[0]);

    for (int i = 1; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    
    printf("\n");
}
