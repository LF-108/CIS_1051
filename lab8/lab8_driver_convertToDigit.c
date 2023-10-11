#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//prototypes
int convertToDigit(char c);

int main(){

char c = '8';
printf("Converting character '%c' to the integer %d.\n", c, convertToDigit(c));

return EXIT_SUCCESS;

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
