#include <stdio.h>
#include <stdlib.h>

/*
 Programmer Name:     Lara Fernandes  
 *Class and Semester:  CIS 1057 Section 004  Fall 2022
 *Date:                Wednesday, August 31, 2022
 *Assignment:          Lab 1
 *Name:                Temperature Conversion
 *Description:         Prompt for input, converts Fahrenheit to
 *                     Celcius, dispaly output.
 */

#define CELCIUS_ADJUSTMENT 0.555555555555

int main()
{
    
    printf("Please enter fahrenheit number you want to convert:");
    
    double fahrenheit; //Declaring the variable fahrenheit
    double celcius;   //Declaring the variable celcius
    
    scanf("%lf", &fahrenheit);
    
    printf("The value of fahrenheit is %lf \n", fahrenheit);
    
    celcius = (fahrenheit-32)*(CELCIUS_ADJUSTMENT);
    //Calculates the right hand side, and stores that value in celcius
    
    printf("The value in celcius is %lf", celcius);
    return EXIT_SUCCESS;
}	

