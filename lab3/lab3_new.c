#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Programmer Name:     Lara Fernandes
 * Class and Semester:  CIS 1057 Section 004 Fall 2022 
 * Date:                Wednesday, September 14, 2022 
 * Assignment:          Lab 3
 * Name:                Gosper's Algorithm
 * Description:         Prompts for an integer input, then through a function calculates and dispalys the 
 *                      intermediate steps and final result of calculating the factorial of that integer
 *                      with Gosper's algorithm
 */ 

#define PI 3.14159265 //defines the constant PI for later calculations

//prototypes
void display_program_banner(void); 

int prompt_for_integer(char *prompt);

double calculate_gospers_algorithm(int x);

int main()
{
	int n; //Declares an int value that will be used to store user input
    
        display_program_banner();

        /*stores the value returned by prompt_for_integer in n so it can be manipulated by
        calculate_gospers_algorithm() */
        n = prompt_for_integer("Please enter an integer value to calculate a factorial.\n");
    
        //Displays Gosper's estimate for the users input
        printf("The factorial estimation is %.6lf.", calculate_gospers_algorithm(n));
    
        return EXIT_SUCCESS;
}

void display_program_banner(void)
/* 
 * Preconditions:  NONE
 * Postconditions: NONE 
 * Globals:        NONE
 * Returns:        NONE
 * Description:    Prints a banner that tells the user what the program does (calculating a factorial estimate) 
 *                 and who wrote the program.
 *                       
 * 
 */
 
{
    
    	printf("ESTIMATE A FACTORIAL VALUE WITHOUT ACTUALLY CALCULATING IT\n");
   
        printf("This program was written by Lara Fernandes\n");
   	
	printf("It will estimate the value of \"n!\" using Gosper's algorithm.\n");
    
}

int prompt_for_integer(char *prompt)
/* 
 * Preconditions:   
 *     variable prompt- A string that prompts for user input  
 * Postconditions: NONE 
 * Globals:        NONE
 * Returns:        A positive integer read in from the keyboard
 * Description:    Takes in a string prompt, and uses it to prompt for an integer input from the user.
 *                 This function then scans in that integer and returns it.         
 *                       
 * 
 */ 
 
{
   
    	int num; //Declares an int that stores user input
    
    	printf("%s", prompt); //prints an entered prompt to prompt for an int value 
    
    	scanf("%d", &num); //scans user input into num 
    
    	return num;
    
}

double calculate_gospers_algorithm(int x)
/*
 * Preconditions:
 *     variable x- an integer that will be manipulated to calculate the intermediate
 *                 steps and final estimate of Gosper's algorithm.
 * Postconditions: NONE
 * Globals:        PI - contains the value of pi to nine decimal places
 * Returns:        A double containing the estimate of gosper's algorithm
 * Description:    Takes in an integer x, and performs calculations to yield
 *                 several intermediate steps as well as a final estimate of Gosper's    >
 *                 algorithm, which is returned.
 * 
 */ 

{
  
  	double gos_step1; //Declares an int that stores step 1 of Gosper's algorithm
  
  	double gos_step2; //Declares an double that stores step 2 of Gosper's algorithm
  
  	double gos_step3; //Declares a double that stores step 3 of Gosper's algorithm
  
  	double gos_step4; //Declares a double that stores step 4 of Gosper's algorithm
  
  	double gos_solution; //Declares a double that stores the solution of Gosper's algorithm
  
  	gos_step1 = pow(x,x); //Calculates x to the power of itself and stores it
  
  	gos_step2 = exp(-x); //Calculates e to the power of -x and stores it
  
 	gos_step3 = (2*x + 1.0/3.0)*PI; //Calculates (2x + 1/3)xPI and stores it
  
  	gos_step4 = sqrt(gos_step3); //Takes the square root of the previous step
  
  	gos_solution = gos_step1*gos_step2*gos_step4; //calculates Gosper's algorithm with step 1, 2, and 4
  
  	printf("Part 1: %lf\n", gos_step1); //Displays step 1
  
  	printf("Part 2: %.6lf\n", gos_step2); //Displays step 2
  
  	printf("Part 3: %.6lf\n", gos_step3); //Displays step 3
  
  	printf("Part 4: %.6lf\n", gos_step4); //Displays step 4
  
  	return gos_solution;
  
 }

