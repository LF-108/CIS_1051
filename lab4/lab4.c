#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Programmer Name:     Lara Fernandes 
 * Class and Semester:  CIS 1057 Section 004 Fall 2022 
 * Date:                Wednesday, September 21, 2022 
 * Assignment:          Lab 4 
 * Name:                Change Please 
 * Description:         Prompts for an amount of money (in the form of a value 
 *                      with a decimal if change is involved), and returns the 
 *                      least amount of each type of change (from twenties to
 *                      pennies) that amount of money can be broken into.
 *
 *
 */ 

//prototypes
void display_program_banner(void);

int prompt_for_dollar_amount(char *prompt);

void change_calculator(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies);

void print_denominations(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies);

int main(){
        
        int dol; //An int that will store the converted user input 
	dol = prompt_for_dollar_amount("Please enter the dollar amount: \n");
        
        //Variables to store the amount of each type of change
	int twenties;
	int tens;
	int fives;
	int ones;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
        
	//Calls the function change_calculator 
        change_calculator(dol, &twenties, &tens, &fives,
	&ones, &quarters, &dimes, &nickels, &pennies); 
        
	//Calls the function print_denominations
        print_denominations(dol, &twenties, &tens, &fives,
	&ones, &quarters, &dimes, &nickels, &pennies);
        
	return EXIT_SUCCESS;

}

void display_program_banner(void)
/* 
 * Preconditions:  NONE 
 * Postconditions: NONE 
 * Globals:        NONE 
 * Returns:        NONE 
 * Description:    Prints out a banner explaining what the program does (converting 
 *                 a given dollar amount into change).      
 *                       
 * 
 */

{

	printf("CALCULATES THE LEAST AMOUNT OF DIFFERENT TYPES OF CHANGE NEEDED GIVEN A DOLLARS AND CENTS AMOUNT"); 
	printf("This program was written by Lara Fernandes.");
	printf("It will calculate the least amount of different kinds of change needed to make up a value.");
}

int prompt_for_dollar_amount(char *prompt)
/* 
 * Preconditions:   
 *     variable *prompt- A prompt for a dollar value from the user    
 * Postconditions: 	 NONE 
 * Globals:        	 NONE
 * Returns:        	 An integer representing the given scanned in dollar amount 
 *                 	 in pennies 
 * Description:    	 Takes in a prompt asking for input in dollars, and uses that to
 *                 	 to prompt for a dollar amount from the user. Takes that dollar
 *                 	 amount, multiplies it by one hundred, and stores it as an integer.
 *                 	 Then it returns that integer. 
 *                      
 *                       
 * 
 */

{
        //Declares a double that stores user's change input with decimals
      	double dollar_input;

	//Declares and int that stores the user's dollar input multiplied by one hundred
        int dollars;
        
        //Takes in a string to prompt for input
	printf("%s", prompt);

	//Scans in the users dollar input as a double
	scanf("%lf", &dollar_input);

	//Multiples user's dollar input by one hundred for later calculations.
        dollars = dollar_input*100;

	return dollars;

}

void change_calculator(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies)
/* 
 * Preconditions:
 *     variable cashin_amount-     The amount of change enetered by the user, converted into the number
 *                                 of pennies
 *     variable *locate_twenties-  A pointer for the variable twenties, stores the amount of twenty dollar
 *                                 bills.
 *     variable *locate_tens-      A pointer for the variable tens, stores the amount of ten dollar
 *                                 bills.
 *     variable *locate_fives-     A pointer for the variable fives, stores the amount of five dollar
 *                                 bills.
 *     variable *locate_ones-      A pointer for the variable ones, stores the amount of one dollar
 *                                 bills.
 *     variable *locate_quarters-  A pointer for the variable quarters, stores the amount of twenty quarters.
 *                                       
 *     variable *locate_dimes-     A pointer for the variable dimes, stores the amount of dimes. 
 *
 *     variable *locate_nickels-   A pointer for the variable nickels, stores the amount of nickels.     
 *
 *     variable *locate_pennies-   A pointer for the variable pennies, stores the amount of pennies.     
 *
 * Postconditions: NONE
 * Globals:        NONE
 * Returns:        NONE
 * Description:    Prints out the amount of each type of change needed to make up the inputted dollar
 *                 value, as well as the inputted dollar value.
 *
 *
 */

{
        //Divides cashin_amount by 2000 to get the number of twenties, then sets cashin_amount to itself mod 2000 to perform remaining calculations. 
	*locate_twenties = cashin_amount/2000;
        cashin_amount = cashin_amount%2000;

	//Divides cashin_amount by 1000 to get the number of tens, then sets cashin_amount to itself mod 1000 to perform remaining calculations.
	*locate_tens = cashin_amount/1000;
        cashin_amount = cashin_amount%1000;
	
	//Divides cashin_amount by 500 to get the number of fives, then sets cashin_amount to itself mod 500 to perform remaining calculations.
	*locate_fives = cashin_amount/500;
        cashin_amount = cashin_amount%500;
	
	//Divides cashin_amount by 100 to get the number of ones, then sets cashin_amount to itself mod 100 to perform remaining calculations.
	*locate_ones = cashin_amount/100;
        cashin_amount = cashin_amount%100;
	
	//Divides cashin_amount by 25 to get the number of quarters, then sets cashin_amount to itself mod 25 to perform remaining calculations.
	*locate_quarters = cashin_amount/25;
        cashin_amount = cashin_amount%25;

	//Divides cashin_amount by 10 to get the number of dimes, then sets cashin_amount to itself mod 10 to perform remaining calculations.
	*locate_dimes = cashin_amount/10;
        cashin_amount = cashin_amount%10;

	//Divides cashin_amount by 5 to get the number of nickels, then sets cashin_amount to itself mod 5 to perform remaining calculations.
	 *locate_nickels = cashin_amount/5;
        cashin_amount = cashin_amount%5;

	//Divides cashin_amount by 1 to get the number of pennies, then sets cashin_amount to itself mod 1.
 	*locate_pennies = cashin_amount/1;
        cashin_amount = cashin_amount%1;
}

void print_denominations(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies)
/* 
 * Preconditions:   
 *     variable cashin_amount-     The amount of change enetered by the user, converted into the number
 *                                 of pennies 
 *     variable *locate_twenties-  A pointer for the variable twenties, stores the amount of twenty dollar
 *                                 bills.  
 *     variable *locate_tens-      A pointer for the variable tens, stores the amount of ten dollar
 *                                 bills.
 *     variable *locate_fives-     A pointer for the variable fives, stores the amount of five dollar
 *                                 bills.
 *     variable *locate_ones-      A pointer for the variable ones, stores the amount of one dollar
 *                                 bills.
 *     variable *locate_quarters-  A pointer for the variable quarters, stores the amount of twenty quarters.
 *                                
 *     variable *locate_dimes-     A pointer for the variable dimes, stores the amount of dimes.
 *                                  
 *     variable *locate_nickels-   A pointer for the variable nickels, stores the amount of nickels.
 *                            
 *     variable *locate_pennies-   A pointer for the variable pennies, stores the amount of pennies.
 *                                  
 * Postconditions: NONE 
 * Globals:        NONE 
 * Returns:        NONE 
 * Description:    Prints out the amount of each type of change needed to make up the inputted dollar
 *                 value, as well as the inputted dollar value.                        
 *                       
 * 
 */

{
        // A variable that will store the user's original input
	double og_value;

        //Gets the user's original input by dividing cashin_amount by 100.0
	og_value = (double)cashin_amount/100.0;

	//Determines subject-verb agreement for each change type depending on amount of change	
	if (*locate_twenties == 1)
	{
	printf("1  Twenty-dollar bill\n");
	}
	else if(*locate_twenties>1)
	{
	printf("%d  Twenty-dollar bills\n", *locate_twenties);
	}

	if (*locate_tens == 1)
	{
	printf("1  Ten-dollar bill\n");
	}
	else if(*locate_tens> 1)
	{
	printf("%d  Ten-dollar bills\n", *locate_tens);
	}

	if (*locate_fives == 1)
	{
	printf("1  Five-dollar bill\n");
	}
	else if(*locate_fives>1)
	{
        printf("%d  Five-dollar bills\n", *locate_fives);
	}

	if (*locate_ones == 1)
	{
	printf("1  One-dollar bill\n");
	}
	else if(*locate_ones> 1)
	{
	printf("%d  One-dollar bills\n", *locate_ones);
	}

	if (*locate_quarters == 1)
	{
	printf("1  Quarter\n");
	}
	else if(*locate_quarters> 1)
	{
	printf("%d  Quarters\n", *locate_quarters);
	}

	if (*locate_dimes == 1)
	{
	printf("1  Dime\n");
	}
	else if(*locate_dimes > 1)
	{
	printf("%d  Dimes\n", *locate_dimes);
	}

	if (*locate_nickels == 1)
	{
	printf("1  Nickel\n");
	}
	else if(*locate_nickels> 1)
	{
	printf("%d  Nickels\n", *locate_nickels);
	}

	if (*locate_pennies == 1)
	{
	printf("1  Penny\n");
	}
	else if(*locate_pennies> 1)
	{
	printf("%d  Pennies\n", *locate_pennies);
	}
        
        //Prints out the user's original input
	printf("Total: $%.2lf\n", og_value);
}
