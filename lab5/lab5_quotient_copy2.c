#include <stdio.h>
#include <stdlib.h>
#include "../include/myheader.h"

void quotientAndRemainder(int numerator, int denominator, int *quotient, int *remainder);

int main()
{
	//Calls the program header funcyion
	program_identification(5, "Drivers(Quotient)", "Calculates the quotient and remainder given two integers for the numerator and denominator.");	
	
	int numerator;
	int denominator;

	printf("Please enter an integer for the numerator.\n"); //Prompts the user for an integer numerator
        scanf("%d", &numerator); //Scans in the value and stores it in numerator

        printf("Please enter an integer for the denominator.\n"); //Prompts the user for an integer denominator
        scanf("%d", &denominator); //Scans in the value and stores it in denominator

	int quotient;  //Declares int quotient, which stores the value of the quotient of quotientAndRemainder
 	int remainder; //Declares int remainder, which stores the value of the remainder of quotientAndRemainder
 	
	quotientAndRemainder(numerator, denominator, &quotient, &remainder); //Calls function quotientAndRemainder()

        return EXIT_SUCCESS;
}

void quotientAndRemainder(int numerator, int denominator, int *quotient, int *remainder)
/*  
 * Preconditions:  
 *	variable numerator-   upper number in ratio. 
 *      variable denominator- lower number in ratio. 
 * Postconditons:  
 *	variable quotient-    the whole part of the division. 
 *      variable remainder-   the part that didn't go in evenly. 
 * Globals:                   NONE  
 * Returns:                   NONE 
 * Description:               Calculates the quotient and remainder of a division. 
 */
{
        
	*quotient = numerator/denominator;    //Stores the value of numerator divided by denominator in quotient
	*remainder = numerator % denominator; //Stores the value of numerator mod denominator in remainder

	printf("The quotient is %d and the remainder is %d.\n", *quotient, *remainder);

}
