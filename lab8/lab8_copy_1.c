#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/myheader.h"
#include "../include/upc.h"

int main()
{
    //Declares an int array to store the values of the UPC barcode
    int upc[12];

   //A loop that runs while the user doesn't input Q
    while(!promptforUPCbarcode(upc)){
        display_UPC_designation(upc);
    }

    return EXIT_SUCCESS;
}

int promptforUPCbarcode (int barcode_array[12])
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: 
 *Globals: NONE
 *Returns: 1 if the user inputs a Q, or 0 otherwise
 *Description: Prompts the user for the input of a UPC barcode and checks for a Q to end the program. 
 * If no Q is inputted, converted the given characters to integers and stores them in an array.
 *
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
 *
 */
{

    //Declares and assigns value the ASCII code value of char c
    int value = c - '0';
    
    return value;
}

int foundDigitsOnly(char barcode_chars[12])
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: NONE
 *Globals: NONE
 *Returns: only_digits - an integer truth value that is 1 if all the characters are digits, and 0 otherwise
 *Description: Checks to see if all the characters inputted by the user for the UPC barcode are digits and returns a truth value based on that 
 *
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


int calculateUPCCheckDigit(int barcode_array[12])
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: NONE
 *Globals: NONE
 *Returns: check_digit - the value of the check digit, an integer
 *Description: Checks to see if the check digit and last digit are the same, and prints out the UPC designations or an error message accordingly 
 *
 * 
 */
{
    //Declares and assigns 0 to integer variables holding intermediate check digit calculation values, as well as the check digit value
    int step1 = 0;
    int step2 = 0;
    int step3 = 0;
    int step4 = 0;
    int last_digit = 0;
    int check_digit = 0;

    //Declares loop control variable
    int i;
    int j;

    //Sums elements in the odd position
    for(i = 0; i<12; i+=2){
    step1+=barcode_array[i];
    }
     
    //Multiplies the above summed elements by 3 
    step2 = step1*3;

    //Sums elements in the even position
    for(j = 1; j<11; j+=2){
    step3+=barcode_array[j];
    }

    //Adds the summed even elements and multiplied and summed odd elements
    step4 = step2 + step3;

    //Gets the last digit of the above sum
    last_digit = step4%10;

    //Finds the check digit by substracting the last digit from 10 is the last digit is not zero
    if(last_digit!=0){
        check_digit = 10-last_digit;
    }
    else{
        check_digit = 0;
    }
    
    //Prints out intermediate steps of check digit calculation
    puts("");
    printf("a.Sum of odd elements times 3 = %d. \n", step2);
    printf("b.Sum of odd elements times three and even elements = %d. \n", step4);
    printf("c.Check Digit = %d. \n", check_digit);
    puts("");

    return check_digit;
}

void display_UPC_designation(int barcode_array[12])
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: Prints out the UPC designation (standard and A/V) if the barcode is validated, else a message that the barcode was invalid
 *Globals: NONE
 *Returns: NONE
 *Description: Checks to see if the check digit and last digit are the same, and prints out the UPC designations or an error message accordingly 
 *
 * 
 */
{
      //Declares and assigns to variable check digit the value of a call to calculateUPCCheckDigit
      int check_digit = calculateUPCCheckDigit(barcode_array);
      
      //Checks if the check digit and last digit of the barcode are equal and prints out a success or failure message accordingly
      if(check_digit == barcode_array[11]){
       printf("The barcode has been successfully validated.\n");
       printf("SUCCESS: The check digit is equal to the last digit of the barcode ");
       printArray(barcode_array, 12);
      printf("This UPC code is designated as %s\n", upc_standard(barcode_array));
      printf("If it is an audio/visual product, it would be %s\n", upc_audio_visual(barcode_array));
      puts("");
      }
      
      else{
          printf("The barcode has been declared invalid.\n");
          printf("FAILURE: The check digit did not match the last digit of the barcode ");
          printArray(barcode_array, 12);
          puts("");
      }
     
}

char *upc_audio_visual(int barcode_array[12])
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: NONE
 *Globals: AV_0 - Represents the A/V UPC designation when the first digit is 0
           AV_1 - Represents the A/V UPC designation when the first digit is 1
           AV_2 - Represents the A/V UPC designation when the first digit is 2
           AV_3 - Represents the A/V UPC designation when the first digit is 3
           AV_4 - Represents the A/V UPC designation when the first digit is 4
           AV_5 - Represents the A/V UPC designation when the first digit is 5
           AV_6 - Represents the A/V UPC designation when the first digit is 6
           AV_7 - Represents the A/V UPC designation when the first digit is 7
           AV_8 - Represents the A/V UPC designation when the first digit is 8
           AV_9 - Represents the A/V UPC designation when the first digit is 9
 *Returns: *rc - a string that holds the A/V UPC designation
 *Description: Uses the first element of barcode array to determine the A/V UPC designation
 *
 * 
 */
{
    //Declares string vairable *rc assigns it a default value
     char *rc = "There's a logic error in the UPC Designation.";

    //Assigns a value to *rc based on the last digit of barcode_array
        if ( barcode_array[11] == 1 )
                rc = AV_1;
        if ( barcode_array[11] == 2 )
                rc = AV_2;
        if ( barcode_array[11] == 3 )
                rc = AV_3;
        if ( barcode_array[11] == 4 )
                rc = AV_4;
        if ( barcode_array[11] == 5 )
                rc = AV_5;
        if ( barcode_array[11] == 6 )
                rc = AV_6;
        if ( barcode_array[11] == 7 )
                rc = AV_7;
        if ( barcode_array[11] == 8 )
                rc = AV_8;
        if ( barcode_array[11] == 9 )
                rc = AV_9;
        if ( barcode_array[11] == 0 )
                rc = AV_0;
        return rc;
    
}

char *upc_standard( int barcode_array[12] )
/*
 *Preconditions: int barcode_array[12] - an integer array containing 12 elements
 *Postconditions: NONE
 *Globals: UPC_MOST_PRODUCTS - Represents the UPC designation for general products, when the first digit of the UPC barcode is 0,1,6,7, or 8
           UPC_2 -Represents the UPC designation for coupons, when the first digit of the UPC barcode is 2
           UPC_3 - Represents the UPC designation for coupons, when the first digit of the UPC barcode is 3
           UPC_4 - Represents the UPC designation for coupons, when the first digit of the UPC barcode is 4
           UPC_COUPONS - Represents the UPC designation for coupons, when the last digit of the UPC barcode is 5 or 9
 *Returns: up_char - a string that holds the UPC designation
 *Description: Uses the first element of barcode array to determine the standard UPC designation
 *
 * 
 */
{
        //Declares string vairable *up_char assigns it a default value
        char *up_char = "There's a logic error in the UPC Designation.";

        //Assigns a value to *up_char based on the value of the first element of barcode_array
        if ( barcode_array[0] == 1 )
                up_char = UPC_MOST_PRODUCTS;
        if ( barcode_array[0] == 2 )
                up_char = UPC_2;
        if ( barcode_array[0] == 3 )
                up_char = UPC_3;
        if ( barcode_array[0] == 4 )
                up_char = UPC_4;
        if ( barcode_array[0] == 5 )
                up_char = UPC_COUPONS;
        if ( barcode_array[0] == 6 )
                up_char = UPC_MOST_PRODUCTS;
        if ( barcode_array[0] == 7 )
                up_char = UPC_MOST_PRODUCTS;
        if ( barcode_array[0] == 8 )
                up_char = UPC_MOST_PRODUCTS;
        if ( barcode_array[0] == 9 )
                up_char = UPC_COUPONS;
        if ( barcode_array[0] == 0 )
                up_char = UPC_MOST_PRODUCTS;
        return up_char;
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
