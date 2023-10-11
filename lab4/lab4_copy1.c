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
 */ 

//prototypes
void display_program_banner(void);

int prompt_for_dollar_amount(char *prompt);

void change_calculator(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies);

void print_denominations(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies);

int main(){
        
        int dol;
	dol = prompt_for_dollar_amount("Please enter the dollar amount: \n");
        
        
	int twenties;
	int tens;
	int fives;
	int ones;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
        
        change_calculator(dol, &twenties, &tens, &fives,
	&ones, &quarters, &dimes, &nickels, &pennies); 
        
        print_denominations(dol, &twenties, &tens, &fives,
	&ones, &quarters, &dimes, &nickels, &pennies);
        
	return EXIT_SUCCESS;

}

void display_program_banner(void){

	printf("CALCULATES THE LEAST AMOUNT OF DIFFERENT TYPES OF CHANGE NEEDED GIVEN A DOLLARS AND CENTS AMOUNT"); 
	printf("This program was written by Lara Fernandes.");
	printf("It will calculate the least amount of different kinds of change needed to make up a value.");
}

int prompt_for_dollar_amount(char *prompt){

	double dollar_input;
        int dollars;
	printf("%s", prompt);
	scanf("%lf", &dollar_input);
        dollars = dollar_input*100;
	return dollars;

}

void change_calculator(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies){

	*locate_twenties = cashin_amount/2000;
        cashin_amount = cashin_amount%2000;

	*locate_tens = cashin_amount/1000;
        cashin_amount = cashin_amount%1000;
	
	*locate_fives = cashin_amount/500;
        cashin_amount = cashin_amount%500;
	
	*locate_ones = cashin_amount/100;
        cashin_amount = cashin_amount%100;
	
	*locate_quarters = cashin_amount/25;
        cashin_amount = cashin_amount%25;

	 *locate_dimes = cashin_amount/10;
        cashin_amount = cashin_amount%10;

	 *locate_nickels = cashin_amount/5;
        cashin_amount = cashin_amount%5;

 	*locate_pennies = cashin_amount/1;
        cashin_amount = cashin_amount%1;
}

void print_denominations(int cashin_amount, int *locate_twenties, int *locate_tens, int *locate_fives,
int *locate_ones, int *locate_quarters, int *locate_dimes, int *locate_nickels, int *locate_pennies){

	double og_value;

	og_value = (double)cashin_amount/100.0;

	if (*locate_twenties == 1)
	{
	printf("1 Twenty-dollar bill\n");
	}
	else if(*locate_twenties>1)
	{
	printf("%d Twenty-dollar bills\n", *locate_twenties);
	}

	if (*locate_tens == 1)
	{
	printf("1 Ten-dollar bill\n");
	}
	else if(*locate_tens> 1)
	{
	printf("%d Ten-dollar bills\n", *locate_tens);
	}

	if (*locate_fives == 1)
	{
	printf("1 Five-dollar bill\n");
	}
	else if(*locate_fives>1)
	{
        printf("%d Five-dollar bills\n", *locate_fives);
	}

	if (*locate_ones == 1)
	{
	printf("1 One-dollar bill\n");
	}
	else if(*locate_ones> 1)
	{
	printf("%d One-dollar bills\n", *locate_ones);
	}

	if (*locate_quarters == 1)
	{
	printf("1 Quarter\n");
	}
	else if(*locate_quarters> 1)
	{
	printf("%d Quarters\n", *locate_quarters);
	}

	if (*locate_dimes == 1)
	{
	printf("1 Dime\n");
	}
	else if(*locate_dimes > 1)
	{
	printf("%d Dimes\n", *locate_dimes);
	}

	if (*locate_nickels == 1)
	{
	printf("1 Nickel\n");
	}
	else if(*locate_nickels> 1)
	{
	printf("%d Nickels\n", *locate_nickels);
	}

	if (*locate_pennies == 1)
	{
	printf("1 Penny\n");
	}
	else if(*locate_pennies> 1)
	{
	printf("%d Pennies\n", *locate_pennies);
	}

	printf("Total: $%.2lf\n", og_value);
}
