#include <stdio.h>
#include <stdlib.h>
#include "../include/myheader.h"

#define NUMBER_OF_LIGHT_YEARS_IN_A_PARSEC 3.26 //Defines a constant for the number of light years in a parsec

double parsecToLightYear(double numberin);

int main()
{
        //Calls the header function
	program_identification(5, "Drivers(Parsec)", "Converts a given number of parsecs to light years.");
        
	double numberin;//Declares a double numberin to serve as input for parsecToLightYear()
         
	printf("Please enter a the number of parsecs you want converted.\n"); //Prompts the user for the number of parsecs
        
	scanf("%lf", &numberin); //Scans in the user input and stores it in numberin

	printf("%lf parsecs is %lf lightyears.\n", numberin, parsecToLightYear(numberin));//Calls parsecToLightYear and prints out the conversion

        return EXIT_SUCCESS;
}

double parsecToLightYear(double numberin)
/*  
 * Preconditions:  
 *	variable numberin-  Distance in parsecs. 
 * Postconditions:          NONE 
 * Globals:                 NUMBER_OF_LIGHT_YEARS_IN_A_PARSEC 
 * Returns:                 light years. 
 * Description:             Converts a distance provided in parsecs to light years. 
 *                          One parsec is equal to 3.26 light years. 
 */
{
	double light_years;//Declares double light years, which will store the number of light years
    
        light_years = numberin * NUMBER_OF_LIGHT_YEARS_IN_A_PARSEC; //stores the value of the number of parsecs times the constant for number of light years in a parsec

        return light_years;
}
